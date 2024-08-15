# Program to solve ax + b = c

def quadratic(a,b,c):
    print(a,"x+ ",b,"=",c)
    x=(c-b)/a
    return x
   
a=int(input("enter a: "))
b=int(input("enter b: "))
c=int(input("enter c: "))
x=quadratic(a,b,c)

print(x)
