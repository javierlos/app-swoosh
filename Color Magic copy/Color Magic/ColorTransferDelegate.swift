//
//  ColorTransferDelegate.swift
//  Color Magic
//
//  Created by javier salgado on 12/6/17.
//  Copyright © 2017 javierSalgado. All rights reserved.
//

import Foundation
import UIKit

protocol ColorTransferDelegate {
    func userDidChose(color: UIColor, withName colorName: String)
}
