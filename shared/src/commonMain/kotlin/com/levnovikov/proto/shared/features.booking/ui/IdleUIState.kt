package com.levnovikov.proto.shared.features.booking.ui

import com.levnovikov.proto.shared.framework.ui.UIState

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
data class IdleUIState(
    val bookingsDoneToday: Int
) : UIState
