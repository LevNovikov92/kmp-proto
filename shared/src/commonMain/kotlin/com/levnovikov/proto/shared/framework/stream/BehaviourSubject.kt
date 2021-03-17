package com.levnovikov.proto.shared.framework.stream

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
class BehaviourSubject<T>(default: T) : Subject<T> {

    private val listeners = mutableSetOf<Listener<T>>()

    override var lastValue = default

    override fun listen(listener: Listener<T>) {
        listener.onNext(lastValue)
        listeners.add(listener)
    }

    override fun dispose(listener: Listener<T>) {
        listener.onDispose()
        listeners.remove(listener)
    }

    override fun next(v: T) {
        listeners.forEach { it.onNext(v) }
    }

    fun next(fn: (T) -> T) {
        listeners.forEach { it.onNext(fn(lastValue)) }
    }
}