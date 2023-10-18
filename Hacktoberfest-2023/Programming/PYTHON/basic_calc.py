a = input("Enter the first number")
b = input("Enter the second number");
ch=-1

while ch !=0:
  print("--Menu--");
  print("\n1.Sum \n2.Diff \n3>Prod \n4.Division")
  ch = input("Enter your choice :")

  if ch == 1:
    print("Sum = ", (a+b))
  elif ch==2:
    print("Diff = ", (a-b))
  elif ch==3:
    print("Product =", (a*b))
  elif ch==4:
    print("Quotient=",(a/b))
  elif ch==0:
    print("Exiting")
    break
  else:
    print("Wrong choice.Please try again!")
    continue
