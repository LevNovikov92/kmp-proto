package com.levnovikov.proto.shared.business.services.order

import com.levnovikov.proto.shared.foundation.Logger
import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Stream

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
class OrderService {

    private val logger = Logger("OrderService")

    private val subject = BehaviourSubject(OrderState())

    val stream: Stream<OrderState> = subject

    fun completeStep(orderId: Int) {
        logger.info("complete step for order with id $orderId")
        subject.next { it.completeCurrent(orderId) }
    }

    fun addNewOrder(order: Order): Boolean {
        logger.info("add new order $order")
        subject.next { it.addOrder(order) }
        return true
    }
}