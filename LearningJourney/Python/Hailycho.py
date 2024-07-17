price = {'milk': 2.50, 'bread': 1.98, 'egg':0.70,'flour':1.18, 'oil': 4.00,'cheese': 2.68}
class Store():
    def __init__(self, name="", location=""):
        self.name = name
        self.location = location
    
    def set_name(self, name):
        self.name = name
    
    def set_location(self, location):
        self.location = location
    
    def display(self):
        print(f"User placed order from: {self.name} at address: {self.location}")


class Cart():
    def __init__(self, product="", quantity=0):
        self.product = product
        self.quantity = quantity
        self.receipt = 0
    
    def add_item(self):

        self.receipt += price[self.product]*self.quantity
    
    def remove_item(self):
            self.receipt -= price[self.product] *self.quantity
    
 
    def display(self):
        print('Order in cart is :')
        print(f'{self.product} with quantity: {self.quantity}')
        print(f'Total receipt is ${self.receipt}')


name = input("Good morning! Which store you want to use today?\n>>> ")
location = input("Which location you want to use?\n>>> ")


store=Store(name,location)

print("Products as follow:")
print("milk: $2.50\nbread: $1.98\negg: $0.70\nflour: $1.18\noil: $4.00\ncheese: $2.68")


product = input("Enter name of your product\n>>> ")
quantity = int(input("Enter quantity\n>>> "))



cart=Cart(product, quantity)
cart.add_item()
cart.display()


remove = input("Do you want to remove an item(Yes/No)\n>>> ")
if remove.lower() == "yes":
    product = input("Enter name of your product\n>>> ")
    quantity = int(input("Enter quantity\n>>> "))
    cart.remove_item()
    cart.display()


add_more = input("Do you want to add another product (yes/no)\n>>> ")
if add_more.lower() == "yes":
    product = input("Enter name of your product\n>>> ")
    quantity = int(input("Enter quantity\n>>> "))
    cart1 = Cart(product,quantity)
    cart1.add_item( )
    cart1.display()
    


remove = input("Do you want to remove an item(Yes/No)\n>>> ")
if remove.lower() == "yes":
    product = input("Enter name of your product\n>>> ")
    quantity = int(input("Enter quantity\n>>> "))
    cart1.remove_item()
    cart.remove_item()
    cart1.display()


add_more = input("Do you want to add another product (yes/no)\n>>> ")
if add_more.lower() == "yes":
    product = input("Enter name of your product\n>>> ")
    quantity = int(input("Enter quantity\n>>> "))
    cart2 = Cart(product,quantity)
    cart2.add_item()
    cart2.display()
    



