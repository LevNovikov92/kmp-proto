//
//  ViewController.swift
//  iosApp
//
//  Created by Lev Novikov on 17/3/21.
//  Copyright © 2021 orgName. All rights reserved.
//

import Foundation
import UIKit
import shared

class LoginController: UIViewController, Listener {

    var loginButton: UIButton!
    var enterButton: UIButton!
    var nameTextField: UITextField!
    var passwordTextField: UITextField!
    var greetingLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .white

        loginButton = UIButton(type: .system)
        loginButton.setTitle("Login", for: .normal)
        loginButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(loginButton)
        loginButton.addTarget(self, action: #selector(handleLoginTouchUpInside), for: .touchUpInside)

        nameTextField = UITextField(frame: .zero)
        nameTextField.placeholder = "Login Name"
        nameTextField.borderStyle = .roundedRect
        nameTextField.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(nameTextField)

        passwordTextField = UITextField(frame: .zero)
        passwordTextField.placeholder = "Password"
        passwordTextField.isSecureTextEntry = true
        passwordTextField.borderStyle = .roundedRect
        passwordTextField.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(passwordTextField)
        
        greetingLabel = UILabel()
        greetingLabel.text = "Hi"
        greetingLabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(greetingLabel)
        
        enterButton = UIButton(type: .system)
        enterButton.setTitle("Enter", for: .normal)
        enterButton.isHidden = true
        enterButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(enterButton)
        enterButton.addTarget(self, action: #selector(onEnterAction), for: .touchUpInside)

        constraintsInit()
        
        flow.getStream().listen(listener: self)
        flow.doInit()
    }

    func constraintsInit() {
        NSLayoutConstraint.activate([
            enterButton.topAnchor.constraint(equalTo: loginButton.bottomAnchor, constant: 20),
            enterButton.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            enterButton.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),
            
            loginButton.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            loginButton.centerYAnchor.constraint(equalTo: view.centerYAnchor),

            passwordTextField.bottomAnchor.constraint(equalTo: loginButton.topAnchor, constant: -20),
            passwordTextField.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            passwordTextField.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),

            nameTextField.bottomAnchor.constraint(equalTo: passwordTextField.topAnchor, constant: -20),
            nameTextField.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            nameTextField.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),
            
            greetingLabel.bottomAnchor.constraint(equalTo: nameTextField.topAnchor, constant: -20),
            greetingLabel.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            greetingLabel.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),
            
        ])
    }

    @objc func handleLoginTouchUpInside() {
        onLogin(nameTextField.text ?? "", passwordTextField.text ?? "")
    }
    
    private let flow = LoginFactory(apiDep: LoginApi()).loginFlow()

    private var onLogin: (String, String) -> Void = {_,_ in }

    @objc func onEnterAction(sender: UIButton!) {
        let bookingController = BookingController()
        navigationController?.pushViewController(bookingController, animated: true)
    }

    func onNext(v: Any?) {
        if let s = v as? LoginPageUIState {
            updateLoginPage(state: s)
        }
    }

    func updateLoginPage(state: LoginPageUIState) -> Void {
        greetingLabel.text = state.greeting
        onLogin = state.onLogin
        if (state.success) {
            enterButton.isHidden = false
        }
    }

    func onDispose() {
        //do nothing
    }
}
