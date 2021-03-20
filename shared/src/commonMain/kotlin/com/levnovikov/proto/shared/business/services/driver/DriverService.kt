package com.levnovikov.proto.shared.business.services.driver

import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Stream

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
        subject.next(DriverState(status))
    }
}

data class DriverState(
    val driverStatus: DriverStatus = DriverStatus.OFFLINE,
    val progress: DailyProgress = DailyProgress(0)
)

enum class DriverStatus{
    OFFLINE, ON_DUTY, BREAK
}