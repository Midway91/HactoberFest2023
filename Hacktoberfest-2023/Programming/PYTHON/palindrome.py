InputString = input("Enter a string or a number: ")
lengthOfString = len(InputString)
mid = int(lengthOfString / 2)
lengthOfString -= 1
s = 0
for i in range(mid):
    if InputString[i] != InputString[lengthOfString - i]:
        s = 1
        break
if s == 0:
    print("The input was a palindrome")
else:
    print("The input was not a palindrome")
