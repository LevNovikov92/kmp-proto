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

class LoginController: UIViewController, Listener, LoginNavigator {

    private var loginButton: UIButton!
    private var enterButton: UIButton!
    private var nameTextField: UITextField!
    private var passwordTextField: UITextField!
    private var greetingLabel: UILabel!

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
        enterButton.addTarget(self, action: #selector(handleEnterTouchUpInside), for: .touchUpInside)

        constraintsInit()
        
        initFlow()
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
    
    @objc func handleEnterTouchUpInside(sender: UIButton!) {
        onEnter()
    }
    
    var flow: LoginFlow!
    private var onLogin: (String, String) -> Void = {_,_ in }
    private var onEnter: () -> Void = {}
    
    func initFlow() {
        let flow = LoginFactory(apiDep: LoginApi(), navigator: self).loginFlow()
        flow.getStream().listen(listener: self)
        flow.doInit()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        flow.dispose()
        flow.getStream().dispose(listener: self)
    }
    
    func showBookingFlow() {
        let bookingController = BookingController()
        present(bookingController, animated: true, completion: nil)
    }

    func onNext(v: Any?) {
        if let s = v as? LoginPageUIState {
            updateLoginPage(state: s)
        }
    }

    func updateLoginPage(state: LoginPageUIState) -> Void {
        onLogin = state.onLogin
        onEnter = state.onEnter
        
        greetingLabel.text = state.greeting
        if (state.success) {
            enterButton.isHidden = false
        }
    }

    func onDispose() {
        //do nothing
    }
}
