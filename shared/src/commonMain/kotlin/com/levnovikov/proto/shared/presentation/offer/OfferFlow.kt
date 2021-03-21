package com.levnovikov.proto.shared.presentation.offer

import com.levnovikov.proto.shared.business.services.offer.Offer
import com.levnovikov.proto.shared.business.services.offer.OfferService
import com.levnovikov.proto.shared.business.services.offer.OfferState
import com.levnovikov.proto.shared.foundation.Logger
import com.levnovikov.proto.shared.foundation.framework.Flow
import com.levnovikov.proto.shared.foundation.framework.UIState
import com.levnovikov.proto.shared.foundation.stream.Listener

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */
class OfferFlow(
    private val offerService: OfferService,
    private val navigator: OfferNavigator
) : Flow(), Listener<OfferState> {

    private val logger = Logger("OfferFlow")

    override fun init() {
        offerService.stream.listen(this)
    }

    override fun dispose() {
        offerService.stream.dispose(this)
    }

    override fun onNext(v: OfferState) {
        logger.info("state received: $v")

        when (v) {
            is OfferState.Received -> post(v.offer.toUIState(showProgress = false, showError = false))
            is OfferState.Confirming -> post(v.offer.toUIState(showProgress = true, showError = false))
            is OfferState.ConfirmationFailed -> post(v.offer.toUIState(
                showProgress = false,
                showError = true
            ))
            is OfferState.Rejecting -> post(v.offer.toUIState(showProgress = true, showError = false))
            is OfferState.RejectionFailed -> post(v.offer.toUIState(
                showProgress = false,
                showError = true
            ))
            is OfferState.Confirmed, is OfferState.Rejected -> offerService.acknowledge()
            is OfferState.Idle -> {
                dispose()
                navigator.dismiss()
            }
        }
    }

    private fun Offer.toUIState(showProgress: Boolean, showError: Boolean) =
        OfferUIState(
            "Delivery from $pickUp to $dropOff",
            showProgress,
            showError,
            onConfirmed,
            onRejected,
            onAck
        )

    private val onConfirmed = {
        offerService.confirm()
    }

    private val onRejected = {
        offerService.reject()
    }

    private val onAck = {
        offerService.acknowledge()
    }
}

data class OfferUIState(
    val offerInfo: String,
    val showProgress: Boolean,
    val showError: Boolean,
    val confirm: () -> Unit,
    val reject: () -> Unit,
    val ack: () -> Unit
) : UIState
