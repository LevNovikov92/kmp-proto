package com.levnovikov.proto.shared.presentation.login.ui

import com.levnovikov.proto.shared.foundation.framework.UIState

/**
 * Author: lev.novikov
 * Date: 14/3/21.
 */
data class LoginPageUIState(
    val greeting: String,
    val success: Boolean,
    val onLogin: (name: String, pass: String) -> Unit
) : UIState