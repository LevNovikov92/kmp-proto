package com.levnovikov.proto.shared.framework.storage

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
expect class KVStore() {
    fun get(key: String): String?
    fun set(key: String, value: String)
}