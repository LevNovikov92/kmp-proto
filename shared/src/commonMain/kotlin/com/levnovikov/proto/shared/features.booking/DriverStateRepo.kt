package com.levnovikov.proto.shared.features.booking

import com.levnovikov.proto.shared.framework.storage.KSerializable
import com.levnovikov.proto.shared.framework.storage.SerializableKVStore
import kotlinx.serialization.Serializable

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
interface DriverStateRepo {
    fun getDriverState(): DriverState
    fun setDriverState(state: DriverState)
}

class DriverStateRepoImpl(
    private val kvStore: SerializableKVStore
) : DriverStateRepo {
    override fun getDriverState(): DriverState {
        return kvStore.get<DriverState>(KEY_DRIVER_STATE) ?: DriverState(0)
    }

    override fun setDriverState(state: DriverState) {
        kvStore.set(KEY_DRIVER_STATE, state)
    }

    companion object {
        private const val KEY_DRIVER_STATE = "driver_state"
    }
}

@Serializable
data class DriverState(val ordersCompleted: Int): KSerializable