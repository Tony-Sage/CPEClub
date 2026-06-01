def prompt():
    print("\n=== MENU ===")
    print("1. Make a call \n2. Send an SMS \n3. View current bill \n4. Pay bill \n5. Exit")
    while True:
        try:
            return int(input("Enter the number of your desired option: "))
        except ValueError:
            print("Invalid input!")


def call():
    rate = 4
    timeInMins = int(input("How many mins will your call last? "))
    bill = rate * timeInMins
    print(f"\nYour call of {timeInMins} cost will cost ₦{bill}. Place call?")
    choice = input("Enter y for yes. Input any other value for no: ")
    if choice == "y":
        print(f"\nCall placed. Cost was ₦{bill}")
        return bill
    else:
        print("Call not placed.")
        
    

def sendMessage():
    bill = 4
    print(f"Message sent! Total cost was ₦{bill}")
    return bill

def viewBill(name, phoneNumber, bill):
    print(f"\nName: {name} \nNumber: {phoneNumber} \nBill: ₦{bill}")

def payBill(bill):
    if bill > 0:
        payment = int(input("How much would you like to pay? Enter an amount: "))
        
        if payment > bill:
            newBill = 0
        else:
            newBill = bill - payment
        
        print(f"Your new bill is ₦{newBill}")
        return newBill
    else:
        print("Your bill is ₦0. Nothing to pay.")

def run():
    name = input("Enter your name: ")
    phoneNumber = input("Enter your phone number: ")
    print(f"Welcome, {name}")
    action = 0
    bill = 0
    
    while action != 5:
        action = prompt()
        
        match action:
            case 1:
                bill = call()
            case 2:
                bill = sendMessage()
            case 3:
                viewBill(name, phoneNumber, bill)
            case 4:
                bill = payBill(bill)
            case 5:
                break
            case _:
                print("Invalid option!")
    
    print("Exiting...")

run()