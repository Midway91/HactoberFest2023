import random
import string

def generate_strong_password(length=12):
    characters = string.ascii_letters + string.digits + string.punctuation
    strong_password = ''.join(random.choice(characters) for _ in range(length))
    return strong_password

# Example usage: Generate a strong password with default length (12 characters)
password = generate_strong_password()
print("Generated Strong Password:", password)
