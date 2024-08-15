# vector addition, multiplication, subtraction and division
import numpy as np 
  
vector1 = np.array([4, 6, 8])
vector2 = np.array([2, 3, 4])
print("Vector 1: ", vector1)
print("Vector 2: ", vector2)
print("pick choice")

while(1):
    choice = input("1: Addition\n2: Subtraction\n3: Multiplication\n4: Division\n5: Exit\n")
    
    match choice:
        case "1":
            print("Addition of two vectors: ",vector1+vector2)
    
        case "2":
            print("Addition of two vectors: ",vector1-vector2)
    
        case "3":
            print("Addition of two vectors: ",vector1*vector2)
        
        case "4":
            print("Addition of two vectors: ",vector1/vector2)
    
        case "5":
            exit()
        case _:
            print("Invalid choice")
