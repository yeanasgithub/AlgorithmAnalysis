#---------------------------------------------------------------------------------------------------------------
# Program name: Lab 16 - Coin-collecting Robot
# Author: Yeana Bond
# Date: 05 / 20 / 2021
# Purpose: To implement genetic algorithm to solve the max amount coins that the robot could collect using 
#         dynamic programming
# Note: Numpy is imported as np in this lab ONLY to display the csv file in a 9 by 9 matrix form.
#      This program only calculates the max amount of coins by transforming the given matrix. It also shows
#      a transformed matrix from the previous one for the viewer to figure out the number of optimal ways to
#      collect max amount of coins by providing the matrix with negative ones visualizing where the sub-sections 
#      are along with a starting point and an ending point of them. starting[i][j] and ending[m][n]
#      of a sub-section could be used for calculating combinations to calculate the number of optimal ways.
# Note: If there are inaccessible blocks from the given data, '-1' is used to indicate the blocks that the robot
#      should not proceed 
################################################################################################################
# Number of optiomal ways: (m-i)+(n-j) C (m-1) = (m-i)+(n-j) C (n-j)  
################################################################################################################
# Download a file: coins.csv should be downloaded to test this lab file successfully. 
################################################################################################################

import csv
import numpy as np




def load_data(filename):
    data = []
    try : 
        thisFile = open(filename, 'rb')
    except IOError :
        print( "\n\nError - coins.csv does not exist!\n" )
        print( "Please, download the attached csv file from my lab submission" )
        print( "in order to test this lab file. Thank you.\n\n" )
    else :
        with open (filename, newline='') as csvfile:
            datum = csv.reader(csvfile)
            
            for row in datum:
                data.append(row)

            for i in range(0, len(data)):
                for j in range(0, len(data)):
                    data[i][j] = int(data[i][j])
        print("Given data: ")
        print(np.matrix(data))
        return data

 

def explore_matrix():
    data = load_data("coins.csv")
    new_data = [[0 for i in range(len(data))] for j in range(len(data))]

    #print(np.matrix(new_data))
    new_data[0][0] = data[0][0] # starting point
    first_row = []
    first_column = []


    for i in range(1):    # only first row
        for j in range(1, len(data)):
            new_data[i][j] = data[i][j] + new_data[i][j-1] 
             
    for i in range(1, len(data)):   # only first column
        for j in range(1):
            new_data[i][j] = data[i][j] + new_data[i-1][j] 
              

    for i in range(1,len(data)):
        for j in range(1,len(data)):
            new_data[i][j] = max(new_data[i-1][j], new_data[i][j-1]) + data[i][j]

    print("\nInitial matrix is transformed into the below matrix to find the max coin amount:\n")
    print(np.matrix(new_data))
    print("\nAccording to the transformed matrix above, the max coin amount is " + str(new_data[len(new_data) -1 ][len(new_data) -1 ]) + ".")


    # this for loop determines where to put negative ones
    # since the robot could move only rightward and downward, if two spots' added up value is less than the current spot,
    # the spot from left or spot from above becomes inaccessbile. 
    for i in range(1, len(data)):
        for j in range(1, len(data)):
            if new_data[i][j-1] + data[i][j] < new_data[i][j]:
                new_data[i][j-1] = -1
            if new_data[i-1][j] + data[i][j] < new_data[i][j]:
                new_data[i-1][j] = -1 
                
    print("\nAfter applying the algorithm to find the number of optimal ways to get the max coins:\n")
    print(np.matrix(new_data))


    
explore_matrix()
input("\n Run complete. Press the Enter key to exit.")
