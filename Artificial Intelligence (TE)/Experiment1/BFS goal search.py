# BFS goal search
print("Breadth First Search")
tree = {'A':['B','C'],'B':['D','E'],'C':['F','G'],'D':[],'E':[],'F':[],'G':[]}
start = input("Enter the start state: ").strip().upper()
goal = input("Enter the goal state: ").strip().upper()
def bfs_goal(tree):
	Open = [start]
	close = []
	if start == goal:
    	print("start state itself is the goal state")
	close.append(start)
	while Open:
    	node = Open.pop(0)
    	neighbour = tree[node]
    	for i in neighbour:
        	if i not in close:
            	close.append(i)
            	Open.append(i)
            	if i == goal:
                	return close
	print("goal node not found")
print("Traversal is",bfs_goal(tree))
