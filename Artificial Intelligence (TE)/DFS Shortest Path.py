# DFS Shortest Path
tree = { 'A':['B', 'C'], 'B':['D', 'E'], 'C':['F', 'G'], 'D':[], 'E':[], "F":[] }

start = input("Enter the start: ").strip().upper()
goal = input("Enter the goal: ").strip().upper()

def dfs_shortest_path(tree):
	Open = [start]
	close = []
    
	if start == goal:
    	print("start state itself is the goal state")
    	return Open

	while Open:
    	path = Open.pop()
    	node  = path[-1]
    	if node not in close:
        	close.append(node)
    	neighbour = tree[node]
    	for i in neighbour:
        	new_path = list(path)
        	new_path.append(i)
        	Open.append(new_path)
        	if i == goal:
            	return new_path
	print("Goal not found")
print("Traversal is ", dfs_shortest_path(tree))
