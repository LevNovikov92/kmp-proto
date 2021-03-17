package com.levnovikov.proto.shared.framework

/**
 * Author: lev.novikov
 * Date: 15/3/21.
 */
expect class Logger() {

    enum class Level {
        INFO, WARNING, ERROR
    }

    fun info(msg: String)
    fun error(msg: String)
    fun warning(msg: String)
    fun log(level: Level, msg: String)
}