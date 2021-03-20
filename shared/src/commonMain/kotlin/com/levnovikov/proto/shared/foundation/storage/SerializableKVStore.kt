package com.levnovikov.proto.shared.foundation.storage

import kotlinx.serialization.encodeToString
import kotlinx.serialization.decodeFromString
import kotlinx.serialization.json.Json

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class SerializableKVStore(
    val kvStore: KVStore
) {

    fun set(key: String, value: KSerializable) {
        kvStore.set(key, Json.encodeToString(value))
    }

    inline fun <reified T> get(key: String): T? {
        val str = kvStore.get(key) ?: return null
        return Json.decodeFromString<T>(str)
    }
}

// The implementation must be serializable
interface KSerializable