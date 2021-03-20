package com.levnovikov.proto.shared.foundation

/**
 * Author: lev.novikov
 * Date: 15/3/21.
 */
expect class Logger(name: String) {

    val name: String

    enum class Level {
        INFO, WARNING, ERROR
    }

    fun info(msg: String)
    fun error(msg: String)
    fun warning(msg: String)
    fun log(level: Level, msg: String)
}