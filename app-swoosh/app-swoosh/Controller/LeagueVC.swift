//
//  LeagueVCViewController.swift
//  app-swoosh
//
//  Created by javier salgado on 4/25/18.
//  Copyright © 2018 javier salgado. All rights reserved.
//

import UIKit

class LeagueVC: UIViewController {

	
	override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

	@IBAction func onNextTapped(_ sender: Any) {
		performSegue(withIdentifier: "skillVCSegue", sender: self)
	}

}
