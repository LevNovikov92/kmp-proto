package com.levnovikov.proto.shared.business.services.order

import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Stream

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
class OrderService {

    private val subject = BehaviourSubject(OrderState())

    val stream: Stream<OrderState> = subject

    fun completeStep(orderId: Int) {
        subject.next { it.completeCurrent(orderId) }
    }

    fun addNewOrder(order: Order): Boolean {
        subject.next { it.addOrder(order) }
        return true
    }
}