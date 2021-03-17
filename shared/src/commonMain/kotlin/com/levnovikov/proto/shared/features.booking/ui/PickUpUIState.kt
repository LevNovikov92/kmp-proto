package com.levnovikov.proto.shared.features.booking.ui

/**
 * Author: lev.novikov
 * Date: 16/3/21.
 */
data class PickUpUIState(
    val pickup: String,
    val stuff: String,
    val etaSec: Int,
    val onPickup: () -> Unit
)
