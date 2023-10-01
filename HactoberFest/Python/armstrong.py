n=(int)(input("Enter a number: "))
sum=0
num=n

while(n!=0):
    d=n%10
    sum+=d**3
    n//=10

if(num==sum):
    print("It is an Armstrong Number.")
else:
    print("It is not an Armstrong Number.")