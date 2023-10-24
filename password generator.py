import secrets  # Import the secrets module for secure random number generation
import string  # Import the string module for string constants

def generate_password(length=12):
    characters = string.ascii_letters + string.digits + string.punctuation  # Define the characters to be used in the password
    secure_random = secrets.SystemRandom()  # Create a secure random object
    password = ''.join(secure_random.choice(characters) for _ in range(length))  # Generate a password of specified length using secure random choices from the characters
    return password

# Example usage
generated_password = generate_password()
print("Generated Password:", generated_password)  # Print the generated password
