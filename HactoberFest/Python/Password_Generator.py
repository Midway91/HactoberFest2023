import random

# Define the possible characters to be used in the password
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '@', '$', '%', '&', '(', ')', '+', '*', '`', '~', '^']

# Print welcome message and get user input for the length of the password
print('Welcome to the PyPassword Generator!')
letters_input = int(input('How many letters would you like in your password?\n'))
symbols_input = int(input('How many symbols would you like in your password?\n'))
numbers_input = int(input('How many numbers would you like in your password?\n'))

# Create an empty list to store the characters of the password
password_list = []

# Add random letters, symbols, and numbers to the password list
for char in range(1, letters_input + 1):
    password_list.append(random.choice(letters))
for char in range(1, symbols_input + 1):
    password_list.append(random.choice(symbols))
for char in range(1, numbers_input + 1):
    password_list.append(random.choice(numbers))

# Shuffle the password list to mix up the characters
random.shuffle(password_list)

# Combine the characters in the password list to create the password
password = ''
for char in password_list:
    password += char

# Print the password to the user
print(f'Here is your Password: {password}')