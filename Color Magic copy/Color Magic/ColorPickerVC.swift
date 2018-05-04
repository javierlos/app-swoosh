//
//  ColorPickerVC.swift
//  Color Magic
//
//  Created by javier salgado on 12/6/17.
//  Copyright © 2017 javierSalgado. All rights reserved.
//

import UIKit

class ColorPickerVC: UIViewController {

    var delegate: ColorTransferDelegate? = nil
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
    }
    
    

    @IBAction func colorBtnWasPressed(sender: UIButton) {
        if delegate != nil{
            delegate?.userDidChose(color: sender.backgroundColor!, withName: sender.titleLabel!.text!)
            self.navigationController?.popViewController(animated: true)
        }
    }
    
    
    
    
}
