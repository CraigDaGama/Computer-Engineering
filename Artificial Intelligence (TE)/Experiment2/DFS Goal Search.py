# DFS goal search
tree = { 'A':['B', 'C'], 'B':['D', 'E'], 'C':['F', 'G'], 'D':[], 'E':[], "F":[] }

start = input("Enter the start: ")
goal = input("Enter the goal: ")

def dfs_traversal(tree):
	Open = [start]
	close = []
    
	if start == goal:
    	print("start state itself is the goal state")
    	return open

	while Open:
    	node = Open.pop()
    	if node not in close:
        	close.append(node)
    	neighbour = tree[node]
    	for i in neighbour:
        	Open.append(i)
        	if i == goal:
            	close.append(i)
            	return close
	print("Goal not found")
	return close
print("Traversal is ", dfs_traversal(tree))
