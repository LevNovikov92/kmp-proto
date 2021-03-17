package com.levnovikov.proto.shared.services.booking

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
data class BookingState(
    val id: Int,
    val steps: List<Step>,
    val current: Int
)

sealed class Step {
    class PickUp(
        val pickup: String,
        val stuff: String
    ) : Step()

    class DropOff(
        val dropOff: String
    ) : Step()

}

