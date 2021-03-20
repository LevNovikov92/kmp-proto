//
// Created by Lev Novikov on 20/3/21.
// Copyright (c) 2021 orgName. All rights reserved.
//

import Foundation
import shared

class OfferApiImpl : OfferApi {
    func confirm(offerId: Int32, success: @escaping () -> Void, error: @escaping (String) -> Void) {
        success()
    }

    func reject(offerId: Int32, success: @escaping () -> Void, error: @escaping (String) -> Void) {
        success()
    }
}
