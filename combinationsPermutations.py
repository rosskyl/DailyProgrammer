"""
https://www.reddit.com/r/dailyprogrammer/comments/4ijtrt/20160509_challenge_266_easy_basic_graph/
"""



def createGraph(numNodes):
    graph = []
    for i in range(numNodes):
        row = []
        for j in range(numNodes):
            row.append(0)
        graph.append(row)
    return graph


print(createGraph(3))