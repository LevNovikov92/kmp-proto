package com.levnovikov.proto.shared.presentation.login

import com.levnovikov.proto.shared.presentation.login.api.LoginApi
import com.levnovikov.proto.shared.presentation.login.api.LoginApiImpl
import com.levnovikov.proto.shared.presentation.login.api.LoginApiDep

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class LoginFactory(
    private val apiDep: LoginApiDep,
    private val navigator: LoginNavigator
) {

    private fun api(): LoginApi = LoginApiImpl(apiDep)

    fun loginFlow() = LoginFlow(api(), navigator)
}