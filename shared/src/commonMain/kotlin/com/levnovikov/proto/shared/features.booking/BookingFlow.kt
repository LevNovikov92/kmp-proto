package com.levnovikov.proto.shared.features.booking

import com.levnovikov.proto.shared.features.booking.ui.DropOffUIState
import com.levnovikov.proto.shared.features.booking.ui.IdleUIState
import com.levnovikov.proto.shared.framework.stream.Listener
import com.levnovikov.proto.shared.framework.ui.Flow
import com.levnovikov.proto.shared.services.booking.*

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
class BookingFlow(
    private val stateMachine: BookingStateMachine,
    private val driverStateRepo: DriverStateRepo
) : Flow(), Listener<BookingState> {

    override fun init() {
        stateMachine.stream.listen(this)
    }

    override fun dispose() {
        super.dispose()
        stateMachine.stream.dispose(this)
    }

    override fun onNext(v: BookingState) {
        if (v.isIdle()) return showIdle()
        return when (val step = v.currentStep()) {
            is Step.PickUp -> showPickup(step)
            is Step.DropOff -> showDropOff(step)
        }
    }

    private fun showDropOff(step: Step.DropOff) {
        post(DropOffUIState(step.dropOff) { stateMachine.completeStep() })
    }

    private fun showIdle() {
        val completed = driverStateRepo.getDriverState().ordersCompleted
        post(IdleUIState(completed))
    }

    private fun showPickup(step: Step.PickUp) {
        post(DropOffUIState(step.pickup) { stateMachine.completeStep() })
    }

}