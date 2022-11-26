#---------------------------------------------------------------------------------------------------------------
# Program name: Lab 14 - Minimum number of coins with any denomination system when making change
#                      - It is called abnormal coin change problem. -
# Author: Yeana Bond
# Date: 05 / 20 / 2021
# Purpose: To apply dynamic programming to find the minimum number of coins (of certain denominations)
#        that add up to a given amount of money.
# Note: Numpy is imported as np in this lab ONLY to display the matrix neatly  
#---------------------------------------------------------------------------------------------------------------

# python 3

import numpy as np

def _change_matrix(coin_set, change_amount):
    
    m = [[0 for row in range(change_amount + 1)] for column in range(len(coin_set) + 1)]

    for i in range(change_amount + 1):
        m[0][i] = i

    return m

def change_making(coins, change):
    m = _change_matrix(coins, change)

    for c in range(1, len(coins) + 1):
        for r in range(1, change + 1):
            # Base case: if one of the denominations matches with the change amount, 
            # then that one coin is all we need
            if coins[c-1] == r:
                m[c][r] = 1
                
            # Larger denomination does not help because the r(total change) is less than the given denomination
            # so, take the previous solution(one row above)
            elif coins[c-1] > r:
                m[c][r] = m[c-1][r]

            # Within this for loop, constantly check if the value above or one plus
            # the value that is denomination away toward left is better
            else:
                m[c][r] = min(m[c-1][r], 1 + m[c][r - coins[c-1]])
                
    print("Denomination: ", coins)
    print(np.matrix(m))
    return m[-1][-1]

print("\nCase #1, change = 15c")
print("Minimum ", change_making([11,5,1], 15), " coins are required for 15c")

print("\nCase #2, change = 1231c")
print("Minimum ", change_making([11,5,1], 1231), " coins are required for 1231c")
              
input("\n Run complete. Press the Enter key to exit.")
    
