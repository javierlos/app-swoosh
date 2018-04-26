//
//  LeagueVCViewController.swift
//  app-swoosh
//
//  Created by javier salgado on 4/25/18.
//  Copyright © 2018 javier salgado. All rights reserved.
//

import UIKit

class LeagueVC: UIViewController {
	
	var player: Player!

	@IBOutlet weak var nextBtn: BorderButton!
	
	override func viewDidLoad() {
        super.viewDidLoad()
		nextBtn.isHidden = true
        player = Player()
    }
	
	
	
	
	
	@IBAction func onNextTapped(_ sender: Any) {
		performSegue(withIdentifier: "skillVCSegue", sender: self)
	}
	
	@IBAction func onMenTapped(_ sender: Any) {
		selectLeague(leagueType: "men")
	}
	
	@IBAction func onWomenTapped(_ sender: Any) {
		selectLeague(leagueType: "women")
	}
	
	@IBAction func onCoedTapped(_ sender: Any) {
		selectLeague(leagueType: "coed")
	}

	
	
	func selectLeague(leagueType: String){
		player.desiredLeague = leagueType
		nextBtn.isHidden = false
		nextBtn.isEnabled = true
	}
}
