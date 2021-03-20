package com.levnovikov.proto.shared.foundation.stream

interface Stream<T> {
    var currentValue: T

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
