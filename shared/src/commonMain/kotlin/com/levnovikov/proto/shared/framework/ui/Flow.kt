package com.levnovikov.proto.shared.framework.ui

import com.levnovikov.proto.shared.framework.stream.BehaviourSubject
import com.levnovikov.proto.shared.framework.stream.Stream
import kotlin.reflect.KClass

abstract class Flow {

    private val stream = BehaviourSubject<UIState>(EmptyUIState)
    private val lastStates = mutableMapOf<KClass<out UIState>, UIState>()

    abstract fun init()
    open fun dispose() {}

    fun getStream(): Stream<UIState> = stream

    fun post(uiState: UIState) {
        stream.next(uiState)
        lastStates[uiState::class] = uiState
    }

//    fun <T> update(fn: (T?) -> T) {
//        fn()
//        lastStates[]
//    }
//
}

interface UIState

object EmptyUIState : UIState