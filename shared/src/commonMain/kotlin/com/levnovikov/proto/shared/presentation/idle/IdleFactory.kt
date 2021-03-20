package com.levnovikov.proto.shared.presentation.idle

import com.levnovikov.proto.shared.presentation.AppFactory

/**
 * Author: lev.novikov
 * Date: 20/3/21.
 */
class IdleFactory(
    private val appFactory: AppFactory,
    private val idleNavigator: IdleNavigator
) {

    fun idleFlow() = appFactory.run {
        return@run IdleFlow(
            driverService,
            offerService,
            orderService,
            idleNavigator
        )
    }
}