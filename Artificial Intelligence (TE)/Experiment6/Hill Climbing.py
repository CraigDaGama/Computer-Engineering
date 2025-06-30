graph = {
    'A': [('B', 3), ('C', 4), ('K', 10)],
    'B': [('D', 1), ('E', 0)],
    'C': [('F', 2), ('G', 3)],
    'D': [],
    'E': [],
    'F': [],
    'G': [],
    'K': []
}

start = input("Enter start node: ")
goal = input("Enter goal node: ")

def hill_climb(start, goal, graph):
    Open = []
    close = []
    Open.append(start)
    
    while Open:
        node = Open.pop(0)
        if node == goal:
            print("Goal found")
            close.append(node)
            print(close)
            return True
        
        close.append(node)
        neighbour = graph[node]
        
        for i in neighbour:
            if i[0] not in Open:
                Open.append(i[0])
                break

    print("Goal not found")

hill_climb(start, goal, graph)
