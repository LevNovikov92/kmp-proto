package com.levnovikov.proto.shared.presentation.login

import com.levnovikov.proto.shared.presentation.login.api.LoginApi
import com.levnovikov.proto.shared.presentation.login.api.LoginReq
import com.levnovikov.proto.shared.presentation.login.api.LoginResp
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
                greeting = "Yo!",
                success = false,
                onLogin = onLogin,
                onEnter = onEnter
            )
        )
        logger.info("LoginFlow initialized")
    }

    private val onLogin: (String, String) -> Unit = { name, pass ->
        logger.info("onLogin clicked")
        api.login(LoginReq(name, pass), { resp ->
            logger.info("success received: $resp")
            updateUI(resp)
            logger.info("ui updated")
        }, { err ->
            logger.info("error received: $err")
            showErr(err)
        })
    }

    private val onEnter: () -> Unit = {
        navigator.showOrderFlow()
    }

    private fun showErr(err: String) {
        post(LoginErrUIState(err))
    }

    private fun updateUI(resp: LoginResp) {
        post(
            LoginPageUIState(
                greeting = "Yo, ${resp.name}!",
                resp.success,
                onLogin,
                onEnter
            )
        )
    }
}