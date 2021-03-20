package com.levnovikov.proto.shared.presentation.order

import com.levnovikov.proto.shared.presentation.AppFactory
import com.levnovikov.proto.shared.business.services.driver.DriverProgressRepoImpl

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class BookingFactory(
    private val appFactory: AppFactory
) {

    private fun driverStateRepo() = DriverProgressRepoImpl(appFactory.kvStore)

    fun bookingFlow() = OrderFlow(appFactory.orderService)
}