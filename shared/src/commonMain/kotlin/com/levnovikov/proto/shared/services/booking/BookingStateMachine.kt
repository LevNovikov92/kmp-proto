package com.levnovikov.proto.shared.services.booking

import com.levnovikov.proto.shared.framework.stream.BehaviourSubject
import com.levnovikov.proto.shared.framework.stream.Stream

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
class BookingStateMachine {

    private val subject = BehaviourSubject(BookingState(-1, listOf(), -1))

    val stream: Stream<BookingState> = subject

    fun completeStep(): Boolean {
        if (subject.lastValue.isIdle()) return false

        subject.next { it.completeCurrent() }
        return true
    }

    fun addNewBooking(id: Int, pickup: String, stuff: String, dropOff: String): Boolean {
        subject.next(BookingState(id, listOf(Step.PickUp(pickup, stuff), Step.DropOff(dropOff)), 0))
        return true
    }
}