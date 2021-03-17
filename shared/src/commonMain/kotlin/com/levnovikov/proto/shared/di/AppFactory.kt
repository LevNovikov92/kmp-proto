package com.levnovikov.proto.shared.di

import com.levnovikov.proto.shared.framework.storage.KVStore
import com.levnovikov.proto.shared.framework.storage.SerializableKVStore
import com.levnovikov.proto.shared.services.booking.BookingStateMachine

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class AppFactory {

    val bookingStateMachine = BookingStateMachine()

    val kvStore: SerializableKVStore = SerializableKVStore(KVStore())


}