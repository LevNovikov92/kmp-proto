package com.levnovikov.proto.shared.business.services.offer

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */
interface OfferApi {
    fun confirm(offerId: Int, success: () -> Unit, error: (String) -> Unit)
    fun reject(offerId: Int, success: () -> Unit, error: (String) -> Unit)
}