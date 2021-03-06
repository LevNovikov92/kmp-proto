package com.levnovikov.proto.shared.presentation.login.api

import kotlinx.serialization.*
import kotlinx.serialization.json.*

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
interface LoginApi {
    fun login(req: LoginReq, onSuccess: (LoginResp) -> Unit, onErr: (String) -> Unit)
}

class LoginApiImpl(
    private val api: LoginApiDep
) : LoginApi {

    override fun login(req: LoginReq, onSuccess: (LoginResp) -> Unit, onErr: (String) -> Unit) {
        api.login(Json.encodeToString(req), { resp ->
            onSuccess(Json.decodeFromString(resp))
        }, onErr)
    }

}