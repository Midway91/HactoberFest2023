# Python program to check if the input number is odd or even.
# A number is even if division by 2 gives a remainder of 0.
# If the remainder is 1, it is an odd number.

'''
num = int(input("Enter a number: "))
if (num % 2) == 0:
   print(f"{num}is even")
else:
   print(f"{num  } is odd")
'''


'''
num=int(input("Enter the year"))
if (num%400 ==0) and (num%100 ==0) :
 print(f"{num} is a leap year")

elif(num%4==0) and (num%100!=0) :
 print(f"{num} is a leap year")

else:
   print(f"{num} is not a leap year")



prime number

num= int(input("Enter the number"))
if num > 1 :
 for i in range(2,num):
       if (num % i) == 0:
           print(i)  #first prime
           
           print(num,"is not a prime number")
           break  
 else:
       print(num,"is a prime number")


'''


lower=int(input("enter the lowerr range"))
upper=int(input("enter the upper range"))


print("Prime numbers between", lower, "and", upper, "are:")


for num in range(lower,upper+1):
 if num>1:
      for i in range(2, num):
 
           if (num % i) == 0:
               print(i)
               break
      else:
           print(num)

