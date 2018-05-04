//
//  ViewController.swift
//  Color Magic
//
//  Created by javier salgado on 12/6/17.
//  Copyright © 2017 javierSalgado. All rights reserved.
//

import UIKit

class ColorPresenterVC: UIViewController, ColorTransferDelegate {

    @IBOutlet weak var ColorNameLbl: UILabel!
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    func userDidChose(color: UIColor, withName colorName: String) {
        view.backgroundColor = color
        ColorNameLbl.text = colorName
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?){
        if segue.identifier == "presentColorPickerVC"{
            guard let colorPickerVC = segue.destination as? ColorPickerVC else{ return }
            colorPickerVC.delegate = self
        }
    }
    
    

}

