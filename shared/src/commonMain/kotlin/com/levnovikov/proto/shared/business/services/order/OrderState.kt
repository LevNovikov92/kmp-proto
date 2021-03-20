package com.levnovikov.proto.shared.business.services.order

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
data class OrderState(
    val orders: List<Order> = emptyList(),
    val completed: List<Order> = emptyList()
)

data class Order(
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

