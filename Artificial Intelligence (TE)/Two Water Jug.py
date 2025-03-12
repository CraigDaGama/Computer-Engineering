print("Two Water Jug Problem")
a = int(input("Enter capacity of jug A: "))
b = int(input("Enter capacity of jug B: "))

# set initial water in A
ai = 0
# set initial water in B
bi = 0
# final water in B
af = 2
# final water in B
bf = 0

print("List of operation you can perform are:")
print("1: Fill A completely")
print("2: Fill B completely")
print("3: Empty A onto the ground")
print("4: Empty B onto the ground")
print("5: Pour water form A to B till it is full")
print("6: Pour water form B to A till it is full")
print("7: Pour all water from jug A to B")
print("8: Pour all water from jug B to A")

print("Initial State")
print("A: ",ai,"\tB: ",bi)

while (ai != af or bi != bf):
    op = int(input("Enter operation number: "))
    if (op == 1):
        ai = ai
    elif (op == 2):
        bi = b
    elif (op == 3):
        ai = 0
    elif (op == 4):
        bi = 0
    
    elif (op == 5):
        if (b - bi > ai):
            bi = bi + ai
            ai = 0
        else:
            bi = b
            ai = ai - (b - bi)
    
    elif (op == 6):
        if (a - ai > bi):
            ai = ai + bi
            bi = 0
        else:
            bi = bi - (a - ai)
            ai = a
     
    elif (op == 7):
        bi = bi + ai
        ai = 0
    
    elif (op == 8):
        ai = ai + bi
        bi = 0
    
    print("A: ",ai,"\tB: ",bi)
    

print("Goal Found")

