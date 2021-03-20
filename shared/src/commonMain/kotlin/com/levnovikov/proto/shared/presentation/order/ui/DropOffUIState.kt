package com.levnovikov.proto.shared.presentation.order.ui

import com.levnovikov.proto.shared.foundation.framework.UIState

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
data class DropOffUIState(
    val dropOff: String,
    val onDropOff: () -> Unit
) : UIState
