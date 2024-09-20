# Depth First Search
# programmer name: Craig Da Gama

graph = { 'A' : ['B','C'], 'B':['D','E'], 'C':['F','G'], 'D':[], 'E':[], 'F':[], 'G':[]}

start = input("Enter Start Node: ")

def dfs_traversal(graph):
    visited = []
    stack = [start]
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
        neighbours = graph[node]
        for i in neighbours:
            stack.append(i)
    return visited


print("\n Here's the nodes of the graph by depth first search: ", dfs_traversal(graph))
