# Iterative Deepening DFS

tree = {'A':['B','C'], 'B':['D','E'], 'C':['F','G'], 'D':[], 'E':[], 'F':[], 'G':[]}

start = input("Enter the start state: ").strip().upper()
goal = input("Enter the goal state: ").strip().upper()
max_depth = int(input("Enter the max depth: "))
path = []
level = 0
def dldfs (start,goal,tree,level,path,depth_limit):
    print("Current level is",level)
    path.append(start)
    if start == goal:
        print("Search ends")
        return path
    if level == depth_limit:
        return False
    print("Expanding current node",start)
    neighbour = tree[start]
    for i in neighbour:
        if dldfs(i,goal,tree,level+1,path,depth_limit):
            return True
        path.pop()
    return False
    
def idds(start,goal,tree,max_depth):
    for i in range(max_depth):
        print("iteraton",i)
        path = []
        if dldfs(start,goal,tree,level,path,i):
            print("Goal Exists")
            print("path: ",path)
            return True
    return False
idds(start,goal,tree,max_depth)
        
