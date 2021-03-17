//
//  LoginApi.swift
//  iosApp
//
//  Created by Lev Novikov on 14/3/21.
//  Copyright © 2021 orgName. All rights reserved.
//

import Foundation
import shared

class LoginApi: LoginApiDep {
    func login(body: String, onSuccess: @escaping (String) -> Void, onErr: @escaping (String) -> Void) {
        DispatchQueue.global(qos: .background).async {
            print("calling api...")
            sleep(1)

            DispatchQueue.main.async {
                onSuccess("{\"token\":\"new_token\", \"name\": \"Valera\", \"success\":true}")
            }
        }
    }
}
