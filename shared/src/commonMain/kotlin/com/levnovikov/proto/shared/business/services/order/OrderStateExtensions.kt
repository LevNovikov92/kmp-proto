package com.levnovikov.proto.shared.business.services.order

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */

fun OrderState.addOrder(order: Order): OrderState {
    return this.copy(orders = orders.toMutableList().apply { add(order) })
}

fun OrderState.isIdle(): Boolean {
    return orders.isEmpty()
}

fun OrderState.currentStep(orderId: Int): Step? {
    val order = orders.firstOrNull { it.id == orderId } ?: return null
    return order.steps[order.current]
}

fun OrderState.order(id: Int): Order? {
    return orders.firstOrNull { it.id == id }
}

fun OrderState.updateOrder(id: Int, fn: (Order) -> Order): OrderState {
    val order = order(id) ?: return this
    val newOrders = orders.toMutableList()
    newOrders[orders.indexOf(order)] = fn(order)
    return copy(orders = newOrders)
}

fun OrderState.completeCurrent(orderId: Int): OrderState {
    val order = order(orderId) ?: return this
    if (order.isCompleted) return this

    val nextStep = if (order.current == order.steps.lastIndex) {
        -1
    } else {
        order.current + 1
    }
    return updateOrder(orderId) { o -> o.copy(current = nextStep) }
}

val Order.isCompleted: Boolean
    get() = current < 0