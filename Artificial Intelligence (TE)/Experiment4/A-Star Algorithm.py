graph = [['A','B',1,2],['A','C',2,4],['A','H',7,0],['B','D',4,2],['B','E',6,6],['C','F',3,3],['C','G',2,2],['D','E',7,6],['D','H',5,0],['G','H',2,0],['F','H',1,0]]

start = input("Enter the start node: ").strip().upper()
goal = input("Enter the goal state: ").strip().upper()

temp = [] # TO store heads
temp1 = [] # store the Tails

for i in graph:
    temp.append(i[0])
    temp1.append(i[1])

nodes = set(temp).union(set(temp1))
Cost = dict()
Path = dict()
Open = set()
Close = set()

# stores as cost ['A':9999, 'B':9999,'C':9999,'D':9999,'E':9999,'F':9999,'G':9999,'H':9999,]
# stores as path ['A':'', 'B':'','C':'','D':'','E':'','F':'','G':'','H':'',]

for i in nodes:
    Cost[i] = 9999
    Path[i] = ''
   
Open.add(start)
Cost[start] = 0
Path[start] = start

def astar(graph,Open,Close,Cost,Cur_node):
    if Cur_node in Open:
        Open.remove(Cur_node)
    Close.add(Cur_node)
   
    for i in graph:
        if(i[0]== Cur_node and Cost[i[0]] + i[2] + i[3] < Cost[i[1]]):
            Open.add(i[1])
            Cost[i[1]] = Cost [i[0] ]+ i[2] + i [3]
            Path[i[1]] = Path[i[0]] + '->' + i[1]
    Cost[Cur_node] = 9999
    smallest = min(Cost, key=Cost.get)
    if smallest not in Close:
        astar(graph,Open,Close,Cost,smallest)
       
astar(graph,Open,Close,Cost,start)
print("Path is",Path[goal])
print("Cost is",Cost[goal])
