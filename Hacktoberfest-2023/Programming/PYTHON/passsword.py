import random

print("Welcome to password generator")

chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@$#%&^().1234567890"

number = int(input("Amount of password need to be generated:"))


length = int(input("Password length"))


print("Your Password:")

for pwd in range(number):
    passwords = ""
    for c in range(length):
        passwords += random.choice(chars)
    print(passwords)
