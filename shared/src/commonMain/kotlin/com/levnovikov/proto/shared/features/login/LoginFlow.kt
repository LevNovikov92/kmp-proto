package com.levnovikov.proto.shared.features.login

import com.levnovikov.proto.shared.features.login.api.LoginApi
import com.levnovikov.proto.shared.features.login.api.LoginReq
import com.levnovikov.proto.shared.features.login.api.LoginResp
import com.levnovikov.proto.shared.features.login.ui.LoginErrUIState
import com.levnovikov.proto.shared.features.login.ui.LoginPageUIState
import com.levnovikov.proto.shared.framework.Logger
import com.levnovikov.proto.shared.framework.ui.Flow

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
class LoginFlow(
    private val api: LoginApi,
    private val navigator: LoginNavigator
) : Flow() {

    private val logger = Logger()

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
        navigator.showBookingFlow()
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