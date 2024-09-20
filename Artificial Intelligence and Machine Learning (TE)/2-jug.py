jugA =  int(input("Enter the maximum capacity of jug A: "))
jugB =  int(input("Enter the maximum capacity of jug B: "))
goal = int(input("Enter the goal state in jug B"))

def pour(jug1, jug2, visited):
    # Print the current step
    print(jug1, "\t\t", jug2)

    # Check if the current state is the goal state
    if jug1 == goal or jug2 == goal:
        return True
    
    # Mark this state as visited
    visited.add((jug1, jug2))

    # Generate all possibe next states
    possible_moves = [
        (jugA, jug2),   # Fill jug1
        (jug1, jugB),   # Fill jug1
        (0, jug2),   # Fill jug1
        (jugA, 0),   # Fill jug1
        (0, jugA + jug2) if jug1 + jug2 <= jugB else (jug1 - (jugB - jug2), jugB),
        (jugA + jug2, 0) if jug1 + jug2 <= jugA else (jugA, jug2 - (jugA - jug1))
    ]

    for next_state in possible_moves:
        if next_state not in visited:
            if pour(next_state[0], next_state[1], visited):
                return True
            
    return False
print ("JUG1/JUG2")
if not pour(0, 0, set()):
    print("No Solution Found")