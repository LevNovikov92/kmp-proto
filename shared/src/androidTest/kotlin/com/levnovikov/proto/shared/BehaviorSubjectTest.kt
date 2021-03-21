package com.levnovikov.proto.shared

import com.levnovikov.proto.shared.foundation.stream.BehaviourSubject
import com.levnovikov.proto.shared.foundation.stream.Listener
import org.junit.Test
import kotlin.test.assertEquals

class BehaviorSubjectTest {

    @Test
    fun testDispose() {
        val subject = BehaviourSubject("default")
        val received = mutableListOf<String>()
        val listener = object : Listener<String> {
            override fun onNext(v: String) {
                received.add(v)
            }
        }

        subject.listen(listener)

        subject.next("val1")
        subject.dispose(listener)

        subject.next("val2")

        assertEquals(listOf("default", "val1"), received)
    }
}