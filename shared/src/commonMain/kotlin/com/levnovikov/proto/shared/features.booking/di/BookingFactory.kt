package com.levnovikov.proto.shared.features.booking.di

import com.levnovikov.proto.shared.di.AppFactory
import com.levnovikov.proto.shared.features.booking.BookingFlow
import com.levnovikov.proto.shared.features.booking.DriverStateRepoImpl

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class BookingFactory(
    private val appFactory: AppFactory
) {

    private fun driverStateRepo() = DriverStateRepoImpl(appFactory.kvStore)

    fun bookingFlow() = BookingFlow(appFactory.bookingStateMachine, driverStateRepo())
}