package com.levnovikov.proto.shared.foundation.framework

import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Stream
import kotlin.reflect.KClass

abstract class Flow {

    private val stream = BehaviourSubject<UIState>(EmptyUIState)
    val lastStates = mutableMapOf<KClass<out UIState>, UIState>()

    abstract fun init()
    open fun dispose() {}

    fun getStream(): Stream<UIState> = stream

    fun post(uiState: UIState) {
        stream.next(uiState)
        lastStates[uiState::class] = uiState
    }

    inline fun <reified T : UIState> post(fn: (T?) -> T) {
        val last: T? = lastStates[T::class] as T?
        post(fn(last))
    }

}

interface UIState

object EmptyUIState : UIState