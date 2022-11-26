#---------------------------------------------------------------------------------------------------------------
# Program name: Lab 15 - Selecting coin-stack(row)s to maximize the amount of coin
# Author: Yeana Bond
# Date: 05 / 20 / 2021
# Purpose: To implement a program that picks the most optimal set of coin-row(stack)s to have maximized amount
#          of coins
# Note: The goal is to pick up the maximum amount of money subject to the constraint that no two coins
#     adjacent in the initial row can be picked up.
#----------------------------------------------------------------------------------------------------------------



def fetch_maximum_sum(coin_list):
    """

    :param coin_list:
    :return: maximum amount of money that can be collected from the given
    coin list or print it depending on the deisgn of code 
    
    """
    coin_row = coin_list
    print("\n\nCoin row: ", coin_row)
    # Let F(n) be maximum money that can be picked up from the row of
    # n coins.If we choose to pick up C(n) , than the largest amount we can get from the group
    # that includes C(n) is equal to C(n) + F(n-2) i.e value from nth coin plus the value we could
    # get from first n-2 coins.If we do not pick Cn, than the maximum amount of money we could get
    # is F(n-1).
    selected_stacks = []
    coin_amount = [coin_list[0]]                           # choosing first element of "coin_amount" set
    coin_amount.append(max(coin_amount[0], coin_list[1]))  # choosing second element of "coin_amount" set

    # Determine the first element of "selected_stacks" set in this if-else block first
    # because of the case when the first coin list(row) is selected and there are two jumps
    # which means it has to skip two stacks and pick the fourth one like in instance # 2
    # So, the instance # 02 demonstrates a "irregular" case where there are two jumps between selected coin stacks
    if coin_amount[1] == coin_amount[0]:
        selected_stacks.append(coin_amount[0])

    else:
        selected_stacks.append(coin_list[1])

    # "coin_amount" set is composed of accumulated total corresponding to each coin stack in the list
    for i in range(2, len(coin_list)):
        coin_amount.append(max(coin_amount[i - 1], coin_amount[i - 2] + coin_list[i]))  ## this is the main algorithm to calculated max amount of coins

    ## below while loop is the algorithm to trace what element of selected from the given coin row
    i = 3   # Remember that we have determined the first picked list in the above if-else block 
    while i <= len(coin_list) -1 :
         
        if coin_amount[i-1] < coin_amount[i-2] + coin_list[i]:
           
            selected_stacks.append(coin_list[i])
            
        elif coin_amount[i-1] >= coin_amount[i-2] + coin_list[i]:
             
            selected_stacks.append(coin_list[i-1])
        
             
        i += 2  # When comparing you have to make 2 jumps so there is no redundancy of grabbing a pair of element at a time
            
    
    print("Selected stacks: ", selected_stacks)    
    print("Coin total accumulated: ", coin_amount)
    print("Maximum coin total amount: ", coin_amount[len(coin_list) -1])


if __name__ == '__main__':
    """
    main method to test the above method
    """
    # instance # 01
    fetch_maximum_sum([5, 10, 7, 12, 6, 5, 8, 9, 12, 14])
    

    # instance # 02
    fetch_maximum_sum([15, 12, 3, 7, 6, 5, 9, 19, 2, 21, 12, 5, 9, 6, 14, 20, 1, 3, 7, 12, 14, 7, 3, 21, 15])
    input("\n Run complete. Press the Enter key to exit.")
