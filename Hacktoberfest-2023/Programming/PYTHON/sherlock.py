d = input("Enter the String\n")
if d =='':
    print("Invalid string")
print(d.replace("+-","").count("+"))
