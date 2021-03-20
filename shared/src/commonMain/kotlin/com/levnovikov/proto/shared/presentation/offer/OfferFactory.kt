package com.levnovikov.proto.shared.presentation.offer

import com.levnovikov.proto.shared.presentation.AppFactory

/**
 * Author: lev.novikov
 * Date: 20/3/21.
 */
class OfferFactory(
    private val appFactory: AppFactory,
    private val navigator: OfferNavigator
) {

    fun offerFlow() = OfferFlow(appFactory.offerService, navigator)
}