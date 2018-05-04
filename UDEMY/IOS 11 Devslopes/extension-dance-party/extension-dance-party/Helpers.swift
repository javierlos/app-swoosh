//
//  Helpers.swift
//  extension-dance-party
//
//  Created by javier salgado on 4/20/18.
//  Copyright © 2018 javierSalgado. All rights reserved.
//

import UIKit


func generate3RandomNumbers(quantity: Int) -> [CGFloat] {
    var randomNumberArray = [CGFloat]()
    for _ in 1...quantity {
        let randomNumber = CGFloat(arc4random_uniform(255))
        randomNumberArray.append(randomNumber)
    }
    return randomNumberArray
}
