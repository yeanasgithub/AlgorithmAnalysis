#------------------------------------------------------------------------
# Program name: Lab 07_01 - Depth of a Binary Tree
# Author: Yeana Bond
# Date: 03/14/2021
# Purpose: Using the concept of "Divide and Conquer", find out the height
#          of a binary tree
# Height of a node: number of vertices(nodes) in the longest path from
#                  the node to the farthest leaf node
# Height of a tree means height of the root node of the tree
# Height of the root node means the number of "vertices" from the root
# node to the farthest leaf node ( Read Discrete Mathematics and its 
#                       Applications, 7th edition, MacGraw Hill, p.355 )
# 
# Height of a tree with one node that is the root node is zero while
# Height of a tree with one node that has one child is one.
# Depth of a node: the number of "edges" in path to reach that node from
#                 the root node or vice versa
# Depth of a tree with one node is also zero
#------------------------------------------------------------------------


treeMatrix = [[1,0,2],
                [2,3,0],
                [3,4,0],
                [4,5,6],
                [5,7,8],
                [7,9,0],
                [9,10,0],
                [10,11,12],
                [11,13,14],
                [13,15,0],
                [15,0,16],
                [16,0,0],
                [14,0,17],
                [17,0,0],
                [12,0,18],
                [18,19,0],
                [19,0,0],
                [8,20,0],
                [20,21,0],
                [21,22,0],
                [22,0,0],
                [6,0,23],
                [23,0,0]]
def main():
    
    leaf_Array = find_leaf_number(treeMatrix, treeMatrix[0][0])  #initial node number to start = sparseMatrix[0][0]
    maxDepth = 0
    for i in range (len(leaf_Array)):
        
        if  count_edges(leaf_Array[i], 0) > maxDepth:
            maxDepth = count_edges(leaf_Array[i], 0)
    print("\nThe max depth of the tree is: ", maxDepth)
    print("\nTherefore, max height of the tree is: ", maxDepth + 1)
    
                

def find_leaf_number(treeMatrix, nodeNum):
    ##countLeaf = 0
    # Create an empty list to collect node number of leaves in this binary tree
    nodeNumber = []
    for nodeNum in range(len(treeMatrix)):
        # Find leaves with this if condition
        if treeMatrix[nodeNum][1] == 0 and treeMatrix[nodeNum][2] == 0:
            # nodeNumber is a list that consists of node number of leaves
            nodeNumber.append(treeMatrix[nodeNum][0])
            ##----comments kept for reviewing
            ##print(sparseMatrix[nodeNum][0])
            ##countLeaf = countLeaf + 1
    ##for i in range(countLeaf):
    ##    print(nodeNumber[i])
    return nodeNumber

def count_edges(n, countE):
   
    for i in range(n-1, -1, -1): # to get the final, max depth of each leaf, range had to be reversed
        
         # In this for loop, it counts edges from bottop to up
         # since depth can be measured by counting the number of edges from a leaf
         # Recursively, this fn is called for seeking a parent of a leaf
         # by making a found parent a new leaf while counting the edge this way

         # n = leaf_Aarray[i] which also determines the range of for loop above
         if treeMatrix[i][1] == n: 
             countE = countE + 1
             n = treeMatrix[i][0] 
             count_edges(n, countE)
             
         elif treeMatrix[i][2] == n:
             countE = countE + 1
             n = treeMatrix[i][0]
             count_edges(n, countE)

  
    return countE 
                    



main()

input("\nRun complete. Press the Enter key to exit.")
