//
//  ContactRow.swift
//  Contact List App
//
//  Created by NING on 26/7/24.
//

import SwiftUI

struct ContactRow: View {
    var contact: Contact
    var body: some View {
        HStack{
            contact.image
                .resizable()
                .frame(width: 50,height: 50)
            Text(contact.name)
        }
            }
}

#Preview {
    ContactRow()
}
