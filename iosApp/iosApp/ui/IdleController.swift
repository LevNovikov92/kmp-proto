//
// Created by Lev Novikov on 20/3/21.
// Copyright (c) 2021 orgName. All rights reserved.
//

import Foundation
import UIKit
import shared

class IdleController: UIViewController, IdleNavigator, Listener {

    private var driverStatusButton: UIButton!
    private var ordersCompletedLabel: UILabel!

    override func viewDidLoad() {
        super.viewDidLoad()
        initUI()
        layoutViews()
        initFlow()
    }

    private func debugTriggerOfferAfterDelay() {
        DispatchQueue.main.asyncAfter(deadline: .now() + 0.5) {
            self.appFactory.offerListener.post(offer: Offer(id: 1, pickUp: "KFC", dropOff: "JLT"))
        }
    }

    override func viewDidDisappear(_ animated: Bool) {
        flow.dispose()
        flow.getStream().dispose(listener: self)
    }

    private func initUI() {
        view.backgroundColor = .white

        driverStatusButton = UIButton()
        driverStatusButton.setTitle("No status", for: .normal)
        driverStatusButton.setTitleColor(.blue, for: .normal)
        driverStatusButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(driverStatusButton)
        driverStatusButton.addTarget(self, action: #selector(onStatusTouch), for: .touchUpInside)

        ordersCompletedLabel = UILabel()
        ordersCompletedLabel.text = "0"
        ordersCompletedLabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(ordersCompletedLabel)
    }

    private func layoutViews() {
        NSLayoutConstraint.activate([
            driverStatusButton.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            driverStatusButton.centerYAnchor.constraint(equalTo: view.centerYAnchor),

            ordersCompletedLabel.bottomAnchor.constraint(equalTo: driverStatusButton.topAnchor, constant: -20),
            ordersCompletedLabel.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            ordersCompletedLabel.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),
        ])
    }

    private var onStatusChanged: (DriverStatus) -> Void = { _ in }

    @objc func onStatusTouch() {
        driverStatusButton.isEnabled = false
        onStatusChanged(DriverStatus.onDuty)
        debugTriggerOfferAfterDelay()
    }

    private var flow: IdleFlow!

    private func initFlow() {
        flow = IdleFactory(appFactory: appFactory, idleNavigator: self).idleFlow()
        flow.getStream().listen(listener: self)
        flow.doInit()
    }

    func onNext(v: Any?) {
        print(">>> IdleController: state received: \(v ?? "nil")")
        if let s = v as? IdleUiState {
            updateIdle(state: s)
            onStatusChanged = s.onStatusChanged
        }
    }

    private func updateIdle(state: IdleUiState) {
        driverStatusButton.setTitle(state.driverStatus, for: .normal)
        ordersCompletedLabel.text = state.ordersCompleted
    }

    func showOffer() {
        let offerController = OfferController()
        offerController.view.bounds = view.bounds
        addChild(offerController)
        view.addSubview(offerController.view)
        offerController.didMove(toParent: self)
    }

    func showOrder() {
        let controller = OrderController()
        present(controller, animated: true, completion: nil)
    }
}