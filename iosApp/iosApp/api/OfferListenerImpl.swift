//
// Created by Lev Novikov on 20/3/21.
// Copyright (c) 2021 orgName. All rights reserved.
//

import Foundation
import shared

class OfferListenerImpl : OfferListener {

    private var listeners: Array<Listener> = []

    func post(offer: Offer) {
        listeners.forEach { listener in
            listener.onNext(v: offer)
        }
    }

    func subscribe(listener: Listener) {
        listeners += [listener]
    }

    func unsubscribe(listener: Listener) {
        listeners.removeAll { ($0 as Listener) === listener }
    }

}
