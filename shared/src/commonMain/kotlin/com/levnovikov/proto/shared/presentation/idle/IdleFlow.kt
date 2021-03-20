package com.levnovikov.proto.shared.presentation.idle

import com.levnovikov.proto.shared.business.services.driver.DriverService
import com.levnovikov.proto.shared.business.services.driver.DriverState
import com.levnovikov.proto.shared.business.services.driver.DriverStatus
import com.levnovikov.proto.shared.business.services.offer.OfferService
import com.levnovikov.proto.shared.business.services.offer.OfferState
import com.levnovikov.proto.shared.business.services.order.OrderService
import com.levnovikov.proto.shared.business.services.order.OrderState
import com.levnovikov.proto.shared.business.services.order.isIdle
import com.levnovikov.proto.shared.foundation.Logger
import com.levnovikov.proto.shared.foundation.framework.Flow
import com.levnovikov.proto.shared.foundation.framework.UIState
import com.levnovikov.proto.shared.foundation.stream.Listener

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */
class IdleFlow(
    private val driverService: DriverService,
    private val offerService: OfferService,
    private val orderService: OrderService,
    private val idleNavigator: IdleNavigator
) : Flow() {

    private val logger = Logger("IdleFlow")

    private val driverListener = DriverListener()

    private val offerListener = OfferListener()

    private val orderListener = OrderListener()

    override fun init() {
        driverService.stream.listen(driverListener)
        offerService.stream.listen(offerListener)
        orderService.stream.listen(orderListener)
    }

    override fun dispose() {
        driverService.stream.dispose(driverListener)
        offerService.stream.dispose(offerListener)
        orderService.stream.dispose(orderListener)
    }

    private val onStatusChanged: (DriverStatus) -> Unit = { st ->
        driverService.changeStatus(st)
    }

    private inner class DriverListener : Listener<DriverState> {
        override fun onNext(v: DriverState) {
            logger.info("DriverState: $v")
            post<IdleUiState> {
                val prev = it ?: IdleUiState()
                prev.copy(
                    driverStatus = v.driverStatus.name,
                    ordersCompleted = "Completed: ${v.progress.ordersCompleted}",
                    onStatusChanged = onStatusChanged
                )
            }
        }
    }

    private inner class OfferListener : Listener<OfferState> {
        override fun onNext(v: OfferState) {
            logger.info("OfferState: $v")
            if (v !is OfferState.Idle) {
                idleNavigator.showOffer()
            }
        }
    }

    private inner class OrderListener : Listener<OrderState> {
        override fun onNext(v: OrderState) {
            logger.info("OrderState: $v")
            if (!v.isIdle()) {
                idleNavigator.showOrder()
            }
        }
    }

}

data class IdleUiState(
    val driverStatus: String = "Offline",
    val ordersCompleted: String = "No data",
    val onStatusChanged: (DriverStatus) -> Unit = {}
) : UIState