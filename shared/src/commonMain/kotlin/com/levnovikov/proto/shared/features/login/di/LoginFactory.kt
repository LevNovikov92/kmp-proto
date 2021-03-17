package com.levnovikov.proto.shared.features.login.di

import com.levnovikov.proto.shared.features.login.LoginFlow
import com.levnovikov.proto.shared.features.login.api.LoginApi
import com.levnovikov.proto.shared.features.login.api.LoginApiImpl
import com.levnovikov.proto.shared.features.login.deps.LoginApiDep

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class LoginFactory(private val apiDep: LoginApiDep) {

    private fun api(): LoginApi = LoginApiImpl(apiDep)

    fun loginFlow() = LoginFlow(api())
}