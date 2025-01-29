# DFS traversal
tree = {'A': ['B', 'C'], 'B': ['D', 'E'], 'C': ['F', 'G'], 'D': [], 'E': [], 'F': [], 'G': []}
start = input("Enter start node: ").strip().upper()

def dfs_traversal(tree):
	Open = [start]
	close = []
	while Open:
    	node = Open.pop()
    	if node not in close:
        	close.append(node)
        	neighbour = tree[node]
    	for i in neighbour:
        	Open.append(i)
	return close

print("Traversal is ", dfs_traversal(tree))
