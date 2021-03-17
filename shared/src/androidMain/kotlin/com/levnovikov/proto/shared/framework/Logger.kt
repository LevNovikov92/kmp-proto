package com.levnovikov.proto.shared.framework

import android.util.Log

/**
 * Author: lev.novikov
 * Date: 15/3/21.
 */
actual class Logger {
    actual enum class Level {
        INFO, WARNING, ERROR
    }

    actual fun info(msg: String) {
        log(Level.INFO, msg)
    }

    actual fun error(msg: String) {
        log(Level.ERROR, msg)
    }

    actual fun warning(msg: String) {
        log(Level.WARNING, msg)
    }

    actual fun log(level: Level, msg: String) {
        Log.println(level.ordinal, level.name, msg)
    }
}