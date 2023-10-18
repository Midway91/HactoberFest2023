# input vlaue from the user
n=int(input('enter no: '))

# take flag, f=1
f=1

# loop until the user input value
for i in range(n):
    f=f*(i+1)

# print the output/factorial
print ('Factorial: ',f)