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

class OrderController: UIViewController, Listener, OrderNavigator {

    private var proceedButton: UIButton!
    private var label: UILabel!

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
        proceedButton.addTarget(self, action: #selector(onProceed), for: .touchUpInside)
        
        constraintsInit()

        initFlow()
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
    
    
    @objc func onProceed(sender: UIButton!) {
        proceed()
    }

    private var proceed: () -> Void = {}

    private var flow: OrderFlow!
    
    func initFlow() {
        flow = OrderFactory(appFactory: appFactory, orderNavigator: self).bookingFlow()
        flow.getStream().listen(listener: self)
        flow.doInit()
    }
    
    override func viewDidDisappear(_ animated: Bool) {
        flow.dispose()
        flow.getStream().dispose(listener: self)
    }
    
    func onNext(v: Any?) {
        print(">>> OrderController: state received: \(v ?? "nil")")
        switch v {
        case is PickUpUIState:
            let state = v as! PickUpUIState
            proceed = state.onPickup
            showShowPickUp(state: state)
        case is DropOffUIState:
            let state = v as! DropOffUIState
            proceed = state.onDropOff
            showDropOff(state: state)
        default: break
        }
    }

    private func showShowPickUp(state: PickUpUIState) {
        label.text = "Picking up '\(state.stuff)' from '\(state.pickup)'"
    }
    
    private func showDropOff(state: DropOffUIState) {
        label.text = "Driving to \(state.dropOff)"
    }

    func dismiss() {
        appFactory.driverService.incrementCompletedOrderCounter()
        dismiss(animated: true)
    }
}
