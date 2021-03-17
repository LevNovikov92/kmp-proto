//
//  BookingController.swift
//  iosApp
//
//  Created by Lev Novikov on 17/3/21.
//  Copyright © 2021 orgName. All rights reserved.
//

import Foundation
import UIKit
import shared

class BookingController: UIViewController, Listener {

    var proceedButton: UIButton!
    var label: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        view.backgroundColor = .white

        label = UILabel()
        label.text = "Default"
        label.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(label)
        
        proceedButton = UIButton(type: .system)
        proceedButton.setTitle("Proceed", for: .normal)
        proceedButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(proceedButton)
        proceedButton.addTarget(self, action: #selector(onClick), for: .touchUpInside)

        constraintsInit()
        
        let flow = BookingFactory(appFactory: appFactory).bookingFlow()
        flow.getStream().listen(listener: self)
        flow.doInit()
    }

    func constraintsInit() {
        NSLayoutConstraint.activate([
            proceedButton.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            proceedButton.centerYAnchor.constraint(equalTo: view.centerYAnchor),

            label.bottomAnchor.constraint(equalTo: proceedButton.topAnchor, constant: -20),
            label.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            label.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),
        ])
    }
    
    
    @objc func onClick(sender: UIButton!) {
        print(">>> onClick")
        if (!appFactory.bookingStateMachine.completeStep()) {
            print(">>> New Booking")
            appFactory.bookingStateMachine.addNewBooking(id: 1, pickup: "Mall", stuff: "Food", dropOff: "Home")
        }
    }
    
    private let flow: BookingFlow! = nil
    
    func onNext(v: Any?) {
        print(">>> On next", v)
        switch v {
        case is IdleUIState:
            showIdle(state: v as! IdleUIState)
        case is PickUpUIState:
            showShowPickUp(state: v as! PickUpUIState)
        case is DropOffUIState:
            showDropOff(state: v as! DropOffUIState)
        default: break
        }
    }
    
    func onDispose() {
        
    }
    
    private func showIdle(state: IdleUIState) {
        label.text = "Idle"
    }
    
    private func showShowPickUp(state: PickUpUIState) {
        label.text = "PickUp"
    }
    
    private func showDropOff(state: DropOffUIState) {
        label.text = "DropOff"
    }
    
}
