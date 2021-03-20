package com.levnovikov.proto.shared.business.services.offer

import com.levnovikov.proto.shared.foundation.stream.Listener

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */
interface OfferListener {
    fun post(offer: Offer)
    fun subscribe(listener: Listener<Offer>)
    fun unsubscribe(listener: Listener<Offer>)
}