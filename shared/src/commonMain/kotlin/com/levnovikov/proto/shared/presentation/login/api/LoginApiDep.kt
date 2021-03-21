package com.levnovikov.proto.shared.presentation.login.api

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
interface LoginApiDep {

    fun login(body: String, onSuccess: (String) -> Unit, onErr: (String) -> Unit)
}