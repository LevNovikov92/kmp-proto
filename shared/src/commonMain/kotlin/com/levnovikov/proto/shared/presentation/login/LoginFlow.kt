package com.levnovikov.proto.shared.presentation.login

import com.levnovikov.proto.shared.presentation.login.api.LoginApi
import com.levnovikov.proto.shared.presentation.login.api.LoginReq
import com.levnovikov.proto.shared.foundation.Logger
import com.levnovikov.proto.shared.foundation.framework.Flow
import com.levnovikov.proto.shared.presentation.login.ui.LoginErrUIState
import com.levnovikov.proto.shared.presentation.login.ui.LoginPageUIState

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
class LoginFlow(
    private val api: LoginApi,
    private val navigator: LoginNavigator
) : Flow() {

    private val logger = Logger("LoginFlow")

    override fun init() {
        post(
            LoginPageUIState(
                greeting = "Hello!",
                success = false,
                onLogin = onLogin
            )
        )
        logger.info("LoginFlow initialized")
    }

    private val onLogin: (String, String) -> Unit = { name, pass ->
        logger.info("onLogin clicked")
        api.login(LoginReq(name, pass), { resp ->
            logger.info("success received: $resp")
            navigator.showOrderFlow()
        }, { err ->
            logger.info("error received: $err")
            showErr(err)
        })
    }

    private fun showErr(err: String) {
        post(LoginErrUIState(err))
    }
}