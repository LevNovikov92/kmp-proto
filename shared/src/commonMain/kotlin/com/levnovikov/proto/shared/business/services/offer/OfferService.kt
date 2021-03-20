package com.levnovikov.proto.shared.business.services.offer

import com.levnovikov.proto.shared.foundation.Logger
import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Listener
import com.levnovikov.proto.shared.foundation.stream.Stream

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */
class OfferService(
    private val api: OfferApi,
    private val listener: OfferListener
) : Listener<Offer> {

    private val logger = Logger("OfferService")
    private val subject = BehaviourSubject<OfferState>(OfferState.Idle)
    val stream: Stream<OfferState> = subject

    fun init() {
        listener.subscribe(this)
    }

    fun terminate() {
        listener.unsubscribe(this)
    }

    fun confirm() {
        val state = subject.currentValue
        logger.info("offer confirmation...")
        if (state !is OfferState.Received) return
        subject.next(OfferState.Confirming(state.offer))
        api.confirm(
            offerId = state.offer.id,
            success = {
                logger.info("offer confirmed")
                subject.next(OfferState.Confirmed(state.offer))
            },
            error = {
                logger.info("offer confirmation failed")
                subject.next(OfferState.ConfirmationFailed(state.offer))
            }
        )
    }

    fun reject() {
        val state = subject.currentValue
        logger.info("offer rejection...")
        if (state !is OfferState.Received) return
        subject.next(OfferState.Rejecting(state.offer))
        api.confirm(
            offerId = state.offer.id,
            success = {
                logger.info("offer rejected")
                subject.next(OfferState.Rejected(state.offer))
            },
            error = {
                logger.info("offer rejection failed")
                subject.next(OfferState.RejectionFailed(state.offer))
            }
        )
    }

    fun acknowledge() {
        logger.info("offer acknowledged")
        subject.next(OfferState.Idle)
    }

    override fun onNext(v: Offer) {
        logger.info("new offer received: $v")
        if (subject.currentValue != OfferState.Idle) return
        logger.info("offer state changed: $v")
        subject.next(OfferState.Received(v))
    }
}

sealed class OfferState {
    object Idle : OfferState()
    data class Received(val offer: Offer) : OfferState()
    data class Confirming(val offer: Offer) : OfferState()
    data class ConfirmationFailed(val offer: Offer) : OfferState()
    data class Confirmed(val offer: Offer) : OfferState()
    data class Rejecting(val offer: Offer) : OfferState()
    data class RejectionFailed(val offer: Offer) : OfferState()
    data class Rejected(val offer: Offer) : OfferState()

}

data class Offer(
    val id: Int,
    val pickUp: String,
    val dropOff: String
)

