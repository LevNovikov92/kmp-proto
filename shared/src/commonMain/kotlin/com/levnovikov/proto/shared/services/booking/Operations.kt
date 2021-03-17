package com.levnovikov.proto.shared.services.booking

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */

fun BookingState.isIdle(): Boolean {
    return id < 0 || isCompleted()
}

fun BookingState.currentStep(): Step {
    return steps[current]
}

fun BookingState.isCompleted(): Boolean {
    return current >= 0
}

fun BookingState.completeCurrent(): BookingState {
    if (isIdle()) return this

    val nextStep = if (current == steps.lastIndex) {
        -1
    } else {
        current + 1
    }
    return copy(current = nextStep)
}