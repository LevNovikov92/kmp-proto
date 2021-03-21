package com.levnovikov.proto.shared.presentation.order

import com.levnovikov.proto.shared.business.services.order.*
import com.levnovikov.proto.shared.foundation.Logger
import com.levnovikov.proto.shared.presentation.order.ui.DropOffUIState
import com.levnovikov.proto.shared.presentation.order.ui.PickUpUIState
import com.levnovikov.proto.shared.foundation.stream.Listener
import com.levnovikov.proto.shared.foundation.framework.Flow

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
class OrderFlow(
    private val service: OrderService,
    private val navigator: OrderNavigator
) : Flow(), Listener<OrderState> {

    private val logger = Logger("OrderFlow")

    override fun init() {
        service.stream.listen(this)
    }

    override fun dispose() {
        super.dispose()
        service.stream.dispose(this)
    }

    override fun onNext(v: OrderState) {
        logger.info("OrderState = $v")
        if (v.isIdle() || v.orders[0].isCompleted) {
            dispose()
            navigator.dismiss()
            return
        }
        val order = v.orders[0]
        return when (val step = v.currentStep(order.id)) {
            is Step.PickUp -> showPickup(order.id, step)
            is Step.DropOff -> showDropOff(order.id, step)
            null -> {}
        }
    }

    private fun showDropOff(orderId: Int, step: Step.DropOff) {
        post(DropOffUIState(step.dropOff) { service.completeStep(orderId) })
    }

    private fun showPickup(orderId: Int, step: Step.PickUp) {
        post(PickUpUIState(step.pickup, step.stuff) { service.completeStep(orderId) })
    }

}