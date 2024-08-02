//
//  SwiftUIView.swift
//  Contact List App
//
//  Created by NING on 26/7/24.
//

import SwiftUI
import Foundation

struct Contact: Identifiable, Decodable{
    var id = Int
    var name : String
    var email : String
    var phone : String
    var imageName : String
    var image : Image {Image (imageName)}
}


