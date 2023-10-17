# Python code to check if a string is a palindrome
s=input()
if s==s[::-1]:     #[::-1] does the reversal
  print("Palindrome")
else:
  print("Not a Palindrome")
