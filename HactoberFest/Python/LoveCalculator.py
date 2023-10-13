print('Welcome to the Love Calculator')

# Get input from the user
name1 = str(input('What is your Name?\n'))
name2 = str(input('What is their name?\n'))

# Convert the input to lowercase to make it case-insensitive
name1_new = name1.lower()
name2_new = name2.lower()

# Combine the two names and count the number of times the letters in the words 'TRUE' and 'LOVE' appear
name_total = name1_new + name2_new
num_total1 = str(name_total.count("t") + name_total.count("r") +
                 name_total.count("u") + name_total.count("e"))
num_total2 = str(name_total.count("l") + name_total.count('o') +
                 name_total.count('v') + name_total.count('e'))
num_total = num_total1 + num_total2
num_total_new = int(num_total)

# Determine the love score and provide a message based on the score
if (num_total_new < 10) or (num_total_new > 90):
    print('Your Love score is ' + num_total +
          ', you go together like coke and mentos')
elif 40 <= num_total_new <= 50:
    print('Your love score is ' + num_total + ', you are alright together')
else:
    print('The percentage of which you love each other is ' + num_total + '%')