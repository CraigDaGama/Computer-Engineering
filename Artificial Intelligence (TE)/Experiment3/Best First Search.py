graph = {
    'A': [('B', 12), ('C', 4)],
    'B': [('D', 7), ('E', 3)],
    'C': [('F', 8), ('G', 2)],
    'D': [],
    'E': [('H', 0)],
    'F': [('H', 0)],
    'G': [('H', 0)],
    'H': []
}

start = input("Enter start node: ")
goal = input("Enter goal node: ")

def best_first_search(start, goal, graph, open=[], close=[]):
    if start not in close:
        print(start)
        close.append(start)

        for x in graph[start]:
            if x[0] not in open:
                open.append(x)

        open.sort(key=lambda x: x[1])  # Sort by heuristic value

        if open[0][0] == goal:
            print(open[0][0])
        else:
            node = open[0][0]
            open.remove(open[0])
            best_first_search(node, goal, graph, open, close)

best_first_search(start, goal, graph)
