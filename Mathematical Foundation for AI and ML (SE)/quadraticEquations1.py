# Program to solve ax + b = cx + d

def quadratic(a,b,c,d):
    print(a,"x +",b,"=",c,"x +",d)
    x=(d-b)/(a-c)
    return x
   
a=int(input("enter a: "))
b=int(input("enter b: "))
c=int(input("enter c: "))
d=int(input("enter d: "))
x=quadratic(a,b,c,d)

print("x=",x)
