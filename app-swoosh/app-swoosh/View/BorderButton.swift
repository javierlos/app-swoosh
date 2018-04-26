//
//  BorderButton.swift
//  app-swoosh
//
//  Created by javier salgado on 4/25/18.
//  Copyright © 2018 javier salgado. All rights reserved.
//

import UIKit

class BorderButton: UIButton {

	override func awakeFromNib() {
		super.awakeFromNib()
		layer.borderWidth = 3.0
		layer.borderColor = UIColor.white.cgColor
	}

}
