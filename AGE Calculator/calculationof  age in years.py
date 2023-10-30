from datetime import datetime, timedelta

# Get the current date
now = datetime.now()

# Ask the user for their date of birth
print("Enter your date of birth (YYYY-MM-DD):")
dob_input = input()

# Parse the user's input into a datetime object
birthday = datetime.strptime(dob_input, "%Y-%m-%d")

# Calculate the difference between the current date and the birthday
difference = now - birthday

# Calculate the person's age in years
age_in_years = difference.days // 365

print(f"You are {age_in_years} years old.")