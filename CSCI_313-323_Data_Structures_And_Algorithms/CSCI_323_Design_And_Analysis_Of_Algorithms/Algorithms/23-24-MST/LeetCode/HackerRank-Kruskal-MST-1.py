#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'kruskals' function below.
#
# The function is expected to return an INTEGER.
# The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
#

#
# For the weighted graph, <name>:
#
# 1. The number of nodes is <name>_nodes.
# 2. The number of edges is <name>_edges.
# 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
#
#
# Implement a Union/Find DS
# Find set with path compression
class DS:
    def __init__(self, n):
        self.sets = [-1]*n

    def find(self, u):
        if (self.sets[u] < 0): return u
        
        s = self.find(self.sets[u])
        self.sets[u] = s
        return s
    
    def join(self, u, v):
        if u == v: return
        if (self.sets[u] < self.sets[v]):
            self.sets[u] += self.sets[v]
            self.sets[v] = u
        else:
            self.sets[v] += self.sets[u]
            self.sets[u] = v

    # Assumes that "u" is a valid set head
    def size(self, u):
        return -self.sets[u]

    def noSets(self):
        count = 0
        for i in range(len(self.sets)):
            if self.sets[i] < 0:
                count += 1        
        return count

def kruskals(g_nodes, g_from, g_to, g_weight):
    # Write your code here
    edges = []
    for i in range(len(g_from)):
        edges.append([g_weight[i], i])    
    edges.sort()
        
    ds = DS(g_nodes+1)
    totalCost = 0
    for weight, edgeIndex in edges:        
        set1 = ds.find(g_from[edgeIndex])
        set2 = ds.find(g_to[edgeIndex])
        if set1 != set2:
            totalCost += weight
            ds.join(set1, set2)
    return totalCost    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    g_nodes, g_edges = map(int, input().rstrip().split())

    g_from = [0] * g_edges
    g_to = [0] * g_edges
    g_weight = [0] * g_edges

    for i in range(g_edges):
        g_from[i], g_to[i], g_weight[i] = map(int, input().rstrip().split())

    res = kruskals(g_nodes, g_from, g_to, g_weight)

    # Write your code here.
    fptr.write(str(res))

    fptr.close()
