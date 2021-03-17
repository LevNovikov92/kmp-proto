package com.levnovikov.proto.shared.framework.storage

import platform.Foundation.NSUserDefaults

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
actual class KVStore {

    private val prefs = NSUserDefaults.standardUserDefaults()

    actual fun get(key: String): String? {
        return prefs.stringForKey(key)
    }

    actual fun set(key: String, value: String) {
        return prefs.setObject(value = value, forKey = key)
    }
}