package com.levnovikov.proto.shared.presentation

import com.levnovikov.proto.shared.business.services.driver.DriverProgressRepoImpl
import com.levnovikov.proto.shared.business.services.driver.DriverService
import com.levnovikov.proto.shared.business.services.offer.OfferApi
import com.levnovikov.proto.shared.business.services.offer.OfferListener
import com.levnovikov.proto.shared.business.services.offer.OfferService
import com.levnovikov.proto.shared.foundation.storage.KVStore
import com.levnovikov.proto.shared.foundation.storage.SerializableKVStore
import com.levnovikov.proto.shared.business.services.order.OrderService

/**
 * Author: lev.novikov
 * Date: 17/3/21.
 */
class AppFactory(
    offerApi: OfferApi,
    @Suppress("MemberVisibilityCanBePrivate")
    val offerListener: OfferListener
) {

    val kvStore: SerializableKVStore = SerializableKVStore(KVStore())

    val orderService = OrderService()
    val offerService = OfferService(offerApi, offerListener).apply { init() }
    val driverService = DriverService(DriverProgressRepoImpl(kvStore)).apply { init() }

}