#Quadratic Equation Solver
import cmath
print("ax^2 + bx + c")
a=int(input("a:"))
b=int(input("b:"))
c=int(input("c:"))
print("your equation looks like :")
print(a,"x^2","+",b,"x","+",c)
d = (b**2) - (4*a*c)
print("sol1:",(-b + cmath.sqrt(d))/(2 * a))
print("sol2:",(-b - cmath.sqrt(d))/(2 * a))
