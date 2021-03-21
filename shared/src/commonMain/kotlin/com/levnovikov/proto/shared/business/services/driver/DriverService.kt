package com.levnovikov.proto.shared.business.services.driver

import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Stream
import kotlinx.serialization.Serializable

/**
 * Author: lev.novikov
 * Date: 19/3/21.
 */
class DriverService(
    private val repo: DriverProgressRepo
) {

    private val subject = BehaviourSubject(DriverState())
    val stream: Stream<DriverState> = subject

    fun init() {
        subject.next { it.copy(progress = repo.getDriverState()) }
    }

    fun changeStatus(status: DriverStatus) {
        subject.next { it.copy(driverStatus = status) }
    }

    fun incrementCompletedOrderCounter() {
        val current = repo.getDriverState()
        repo.setDriverState(current.copy(ordersCompleted = current.ordersCompleted + 1))
        subject.next { it.copy(progress = repo.getDriverState()) }
    }
}

@Serializable
data class DriverState(
    val driverStatus: DriverStatus = DriverStatus.OFFLINE,
    val progress: DailyProgress = DailyProgress(0)
)

@Serializable
enum class DriverStatus{
    OFFLINE, ON_DUTY, BREAK
}