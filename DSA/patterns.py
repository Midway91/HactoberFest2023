# Prime Number
def prime(n):
    if n>1:
        for i in range(2,n):
            if n%i==0:
                return "Non-Prime"
            else:
                return 'Prime'
    return "Non-Prime"
# print(prime(13))

#Print star xrow * ycolumn
def star_pattern():
    row = int(input("Enter the Row"))
    column = int(input("Enter the Column"))
    i=0
    while (i<row):
        print("*"*column)
        i+=1

# print(star_pattern())

# Number of nrow * ncolumn like --->111 222 333
def number_pattern():
    n = int(input("Enter the number"))
    i=1
    while i<=n:
        print(str(i)*n)
        i=i+1
    
# print(number_pattern())

# Print Number Pattern
def number_pattern():
    n = int(input("Number:"))
    for x in range(n):
        for x in range(n):
            print(x+1, end="")
        print()
  

# print(number_pattern()) 123,456,789

def incrementing_number():
    n = int(input("Number:"))
    a = 0
    n = list(range(1,n*n+1))
    for i in n:
        if a == 3:
            print()
            a = 0
        print(str(i), end='')
        a += 1
    
# print(incrementing_number())


#Reverse Incrementing number 987,654,321
def reverse_incrementing_number():
    n = int(input("Number"))
    a=0
    n1 = list(range(1,n*n+1))
    n2 = sorted(n1, reverse=True)
    for i in n2:
        if a==n:
            print()
            a=0
        print(i, end=' ')
        a+=1
    
# print(reverse_incrementing_number())


# Star
def star():
    n  = int(input("star:"))
    i=0
    while i<=n:
        print(i*'*')
        i+=1
    
# print(star())


#Number -->1,22,333
def number():
    n = int(input("Num:"))
    i=0
    while i<=n:
        print(str(i)*i)
        i+=1

# print(number())


#Increment number according to row-->1,23,456
def inc_num():
    n = int(input("Num:"))
    c=1
    for i in range(1, n+1):
        for j in range(1,i+1):
            print(c,end=" " )
            c+=1
        print()

# print(inc_num())

