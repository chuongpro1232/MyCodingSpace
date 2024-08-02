//
//  ContactList.swift
//  Contact List App
//
//  Created by NING on 26/7/24.
//

import SwiftUI

struct ContactList: View {
    var body: some View {
        NavigationView{
            List (contacts){
                contact in
                NavigationLink{
                    ContactCard (contact: contact)
                }
            label: {
                ContactRow (contact: contact)
            }
            .navigationTitle("Contact")
            }
        }
    }
    
    struct ContactList_Previews: PreviewProvider {
        static var previews: some View {
            ContactList()
        }
    }
    
}
