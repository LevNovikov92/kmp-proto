//
// Created by Lev Novikov on 20/3/21.
// Copyright (c) 2021 orgName. All rights reserved.
//

import Foundation
import UIKit
import shared

class OfferController: UIViewController, OfferNavigator, Listener {

    private var offerDetailsLabel: UILabel!
    private var confirmButton: UIButton!
    private var rejectButton: UIButton!

    override func viewDidLoad() {
        super.viewDidLoad()
        initUI()
        layoutViews()
        initFlow()
    }

    override func viewDidDisappear(_ animated: Bool) {
        flow.dispose()
        flow.getStream().dispose(listener: self)
    }

    private func initUI() {
        view.backgroundColor = .cyan

        confirmButton = UIButton()
        confirmButton.setTitle("Confirm", for: .normal)
        confirmButton.setTitleColor(.blue, for: .normal)
        confirmButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(confirmButton)
        confirmButton.addTarget(self, action: #selector(onConfirm), for: .touchUpInside)

        rejectButton = UIButton()
        rejectButton.setTitle("Reject", for: .normal)
        rejectButton.setTitleColor(.blue, for: .normal)
        rejectButton.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(rejectButton)
        rejectButton.addTarget(self, action: #selector(onConfirm), for: .touchUpInside)

        offerDetailsLabel = UILabel()
        offerDetailsLabel.text = "Offer data"
        offerDetailsLabel.translatesAutoresizingMaskIntoConstraints = false
        view.addSubview(offerDetailsLabel)
    }

    private func layoutViews() {
        NSLayoutConstraint.activate([
            confirmButton.centerXAnchor.constraint(equalTo: view.centerXAnchor),
            confirmButton.centerYAnchor.constraint(equalTo: view.centerYAnchor),

            rejectButton.bottomAnchor.constraint(equalTo: confirmButton.topAnchor, constant: -20),
            rejectButton.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            rejectButton.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),

            offerDetailsLabel.bottomAnchor.constraint(equalTo: rejectButton.topAnchor, constant: -20),
            offerDetailsLabel.leadingAnchor.constraint(equalTo: view.readableContentGuide.leadingAnchor, constant: 20),
            offerDetailsLabel.trailingAnchor.constraint(equalTo: view.readableContentGuide.trailingAnchor, constant: -20),
        ])
    }

    private var confirm: () -> Void = {
    }
    private var reject: () -> Void = {
    }

    @objc func onConfirm() {
        print(">>> confirm clicked")
        confirm()
    }

    @objc func onReject() {
        print(">>> reject clicked")
        reject()
    }

    private var flow: OfferFlow!

    private func initFlow() {
        flow = OfferFactory(appFactory: appFactory, navigator: self).offerFlow()
        flow.getStream().listen(listener: self)
        flow.doInit()
    }

    func finishOffer() {
        print(">>> finish offer")
        willMove(toParent: nil)
        view.removeFromSuperview()
        removeFromParent()
    }

    func onDispose() {

    }

    func onNext(v: Any?) {
        print(">>> OfferController: state received: \(v ?? "nil")")
        if let s = v as? OfferUIState {
            updateOffer(state: s)
            confirm = s.confirm
            reject = s.reject
        }
    }

    private func updateOffer(state: OfferUIState) {
        offerDetailsLabel.text = "Delivery from \(state.pickUp) tp \(state.dropOff)"
    }
}
