package com.levnovikov.proto.shared.business.services.driver

import com.levnovikov.proto.shared.foundation.storage.SerializableKVStore
import kotlinx.serialization.Serializable

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
interface DriverProgressRepo {
    fun getDriverState(): DailyProgress
    fun setDriverState(state: DailyProgress)
}

class DriverProgressRepoImpl(
    private val kvStore: SerializableKVStore
) : DriverProgressRepo {
    override fun getDriverState(): DailyProgress {
        return kvStore.get<DailyProgress>(KEY_DRIVER_PROGRESS) ?: DailyProgress(0)
    }

    override fun setDriverState(state: DailyProgress) {
        kvStore.set(KEY_DRIVER_PROGRESS, state)
    }

    companion object {
        private const val KEY_DRIVER_PROGRESS = "driver_progress"
    }
}

@Serializable
data class DailyProgress(val ordersCompleted: Int)