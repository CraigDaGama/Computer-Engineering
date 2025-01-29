# BFS traversal
tree = {
  'A':['B','C'],'B':['D','E'],'C':['F','G'],'D':[],'E':[],'F':[],'G':[]
}

start = input("Enter the start state: ").strip().upper()

def bfs_traversal(tree):
  Open = [start]
  close = []
  while Open:
	node = Open.pop(0) #pop the first element
	if node not in close:
  	close.append(node) #adding the popped node
  	neighbour = tree[node]
  	for i in neighbour:
    	Open.append(i)
  return close
print ("Traversal is",bfs_traversal(tree))
