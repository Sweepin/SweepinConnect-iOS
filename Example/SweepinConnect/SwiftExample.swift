//
//  test.swift
//  SweepinConnect_Example
//
//  Created by Alexis Barat on 24/05/2018.
//  Copyright © 2018 Alexis Barat. All rights reserved.
//

import Foundation
import SCSDKProximityServiceKit

@objc public class SwiftExample: NSObject{
    
    @objc func getUserCampaigns(){
        
        SCSDKProximityService.sharedInstance().getCampaignsByUserAction(kUserActionReceived, withSuccessHandler: { (_ object: Any) -> Void in
            let objCArray = object as! NSArray
            if objCArray.count > 0{
                let campaign = objCArray.object(at: 0) as! SCSDKCampaign
                self.displayCampaign(campaign: campaign)
            }
            
        }) { (_error: Error?) -> Void in
            
        }
    }
    
    @objc func displayCampaign(campaign: SCSDKCampaign){
        DispatchQueue.main.async {
            SCSDKProximityService.sharedInstance().display(campaign)
        }
    }
}
