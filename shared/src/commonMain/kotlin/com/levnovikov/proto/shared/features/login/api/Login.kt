package com.levnovikov.proto.shared.features.login.api

import kotlinx.serialization.Serializable

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */

@Serializable
data class LoginReq(val name: String, val pass: String)

@Serializable
data class LoginResp(val token: String, val name: String, val success: Boolean)
