package com.levnovikov.proto.shared.foundation.storage

import com.levnovikov.proto.shared.foundation.Logger
import kotlinx.serialization.Serializable
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

    val logger = Logger("SerializableKVStore")

    inline fun <reified T> set(key: String, value: T) {
        kvStore.set(key, Json.encodeToString(value))
    }

    inline fun <reified T> get(key: String): T? {
        val str = kvStore.get(key) ?: return null
        return try {
            Json.decodeFromString<T>(str)
        } catch (e: Exception) {
            logger.error("error while reading '$key': $e")
            null
        }
    }
}