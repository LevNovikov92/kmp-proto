package com.levnovikov.proto.shared.foundation.stream

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
class BehaviourSubject<T>(default: T) : Subject<T> {

    private val listeners = mutableSetOf<Listener<T>>()

    override var currentValue = default

    override fun listen(listener: Listener<T>) {
        listener.onNext(currentValue)
        listeners.add(listener)
    }

    override fun dispose(listener: Listener<T>) {
        listener.onDispose()
        listeners.remove(listener)
    }

    override fun next(v: T) {
        currentValue = v
        listeners.forEach { it.onNext(v) }
    }

    fun next(fn: (T) -> T) {
        val value = fn(currentValue)
        currentValue = value
        listeners.forEach { it.onNext(value) }
    }
}