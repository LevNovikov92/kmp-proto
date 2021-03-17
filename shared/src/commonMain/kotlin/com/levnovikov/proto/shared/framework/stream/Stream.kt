package com.levnovikov.proto.shared.framework.stream

interface Stream<T> {
    var lastValue: T

    fun listen(listener: Listener<T>)
    fun dispose(listener: Listener<T>)
}

interface Listener<T> {
    fun onNext(v: T)
    fun onDispose() {}
}

interface Subject<T> : Stream<T> {
    fun next(v: T)
}
