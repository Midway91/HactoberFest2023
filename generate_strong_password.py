import random
import string

def generate_strong_password(length):
    characters = string.ascii_letters + string.digits + string.punctuation + string.ascii_uppercase
    strong_password = ''.join(random.choice(characters) for _ in range(length))
    return strong_password

# Example usage: Generate a strong password with default length (12 characters)
# password = generate_strong_password()
# print("Generated Strong Password:", password)

#Generating password according to given length.
while True:
    try:
        length = int(input("Enter the length of password: "))
        if(length > 0):
            print(generate_strong_password(length))
        else:
            print("Please Check your input.")
    except Exception as e:
        print(e)
