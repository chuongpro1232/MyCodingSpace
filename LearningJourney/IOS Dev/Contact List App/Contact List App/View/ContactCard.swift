//
//  ContactCard.swift
//  Contact List App
//
//  Created by NING on 26/7/24.
//

import SwiftUI

struct ContactCard: View {
    var contact: Contact
    var body: some View {
        ZStack{
            Color(red:38/255,green:70/255,blue:83/255)
                .edgesIgnoringSafeArea(.all)
        }
        VStack{
           
            Text(contact.name)
                .font(.system(size: 40))
                .bold()
                .foregroundColor(.white)
            
        }
    }
}

#Preview {
    ContactCard()
}
