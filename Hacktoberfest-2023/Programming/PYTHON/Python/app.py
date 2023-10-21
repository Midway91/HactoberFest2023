# Banking App with Text File Database

def load_data():
    data = {}
    with open("accounts.txt", "r") as file:
        for line in file:
            account_number, customer_name, balance = line.strip().split(", ")
            data[account_number] = {"customer_name": customer_name, "balance": float(balance)}
    return data

def save_data(data):
    with open("accounts.txt", "w") as file:
        for account_number, account_data in data.items():
            file.write(f"{account_number}, {account_data['customer_name']}, {account_data['balance']}\n")

def main():
    data = load_data()

    while True:
        print("\nBanking Terminal App")
        print("1. Check Balance")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            account_number = input("Enter your account number: ")
            if account_number in data:
                print(f"Balance for {data[account_number]['customer_name']}: ${data[account_number]['balance']:.2f}")
            else:
                print("Account not found.")
        elif choice == "2":
            account_number = input("Enter your account number: ")
            if account_number in data:
                amount = float(input("Enter the deposit amount: "))
                data[account_number]['balance'] += amount
                save_data(data)
                print(f"Deposit of ${amount:.2f} successful.")
            else:
                print("Account not found.")
        elif choice == "3":
            account_number = input("Enter your account number: ")
            if account_number in data:
                amount = float(input("Enter the withdrawal amount: "))
                if amount <= data[account_number]['balance']:
                    data[account_number]['balance'] -= amount
                    save_data(data)
                    print(f"Withdrawal of ${amount:.2f} successful.")
                else:
                    print("Insufficient funds.")
            else:
                print("Account not found.")
        elif choice == "4":
            print("Thank you for using our banking app.")
            break
        else:
            print("Invalid choice. Please choose a valid option.")

if __name__ == "__main__":
    main()
