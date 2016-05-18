"""
https://www.reddit.com/r/dailyprogrammer/comments/4ijtrt/20160509_challenge_266_easy_basic_graph/
"""


lines = """16
1 2
1 3
2 3
1 4
3 4
1 5
2 5
1 6
2 6
3 6
3 7
5 7
6 7
3 8
4 8
6 8
7 8
2 9
5 9
6 9
2 10
9 10
6 11
7 11
8 11
9 11
10 11
1 12
6 12
7 12
8 12
11 12
6 13
7 13
9 13
10 13
11 13
5 14
8 14
12 14
13 14
1 15
2 15
5 15
9 15
10 15
11 15
12 15
13 15
1 16
2 16
5 16
6 16
11 16
12 16
13 16
14 16
15 16"""



def createGraph(numNodes):
    graph = []
    for i in range(numNodes):
        row = []
        for j in range(numNodes):
            row.append(0)
        graph.append(row)
    return graph

def printGraph(graph):
    for row in graph:
        for node in row:
            print(node, end=" ")
        print()

def addToGraph(lines, graph):
    for line in lines:
        line = line.split()
        line[0] = int(line[0])
        line[1] = int(line[1])
        graph[line[0]-1][line[1]-1] += 1
        graph[line[1]-1][line[0]-1] += 1

def printNodes(graph):
    node = 1
    for row in graph:
        degree = sum(row)
        print("Node", node, "has a degree of",degree)
        node += 1


lines = lines.split("\n")

graph = createGraph(int(lines.pop(0)))
addToGraph(lines, graph)
printNodes(graph)
printGraph(graph)