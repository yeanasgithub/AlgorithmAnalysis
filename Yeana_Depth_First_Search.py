#------------------------------------------------------------------------
# Program name: Lab 08 - Topological sorting using DFS
# Author: Yeana Bond
# Date: 04/04/2021
# Purpose: Use the DFS method to find out the topological sort result for
#         the graph 
#------------------------------------------------------------------------

from __future__ import absolute_import, print_function, division
import sys

if len(sys.argv) < 2:
    print("Usage: $python3 [filename] [starting node]")

# dictionary
graph = {1:[9],
         2:[3],
         3:[4],
         4:[6],
         5:[6],
         6:[8],
         7:[2,8,9],
         8:[11],
         9:[],
         10:[],
         11:[10]}

# empty sets
parents = {}
a = []
visited = []
toposorted = []

def flip_a(a):
    for i in range(0,len(a)):
        b = a.pop()
        toposorted.append(b)

def dfs(graph, vertex):
    if vertex not in parents:
        parents[vertex] = None
        dfs_visit(graph, vertex, parents)
    for i in graph.keys():
        if i not in parents:
            visited.append(i)
            dfs_visit(graph,i,parents)

def dfs_visit(graph, vertex, parents):
    for n in graph[vertex]:
        if n not in parents:
            if n not in visited:
                visited.append(n)
            parents[n] = vertex
            dfs_visit(graph, n, parents)
    if vertex not in a:
        a.append(vertex)

print("Start from: ",int(sys.argv[1]))
dfs(graph, int(sys.argv[1]))
print("visited:",visited)
flip_a(a)
print("Topological sort:",toposorted)


