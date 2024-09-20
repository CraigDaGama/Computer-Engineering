graph = { 'A' : ['B','C'], 'B':['D','E'], 'C':['F','G'], 'D':[], 'E':[], 'F':[], 'G':[]}

start = input("Enter Start Node: ")

def bfs_connected_component(graph):
    visited = []
    queue = [start]
    while queue:
        node = queue.pop(0)
        if node not in visited:
            visited.append(node)
            neighbours = graph[node]
            for neighbour in neighbours:
                queue.append(neighbour)
    return visited

print("\n Here's the nodes of the graph by breadth first search: ", bfs_connected_component(graph))