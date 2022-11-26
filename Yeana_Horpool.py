
#------------------------------------------------------------------------
# Program name: Lab 10 - String searching with Horspool's method
# Author: Yeana Bond
# Date: 05/04/2021
# Note: A space, ' ', is considered "everything else" other than capital
#     alphabet letters
#------------------------------------------------------------------------

capital_Letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ "


def make_shift_table(text, pattern):
  
    global capital_Letters 
    
    shift_table = {}
    
    for i in range(len(capital_Letters)):
        shift_table[capital_Letters[i]] = len(pattern)
    #print(shift_table) # to test

    #updating the dictionary with new values 
    for i in range(len(pattern) - 1):
        shift_table[pattern[i]] = len(pattern) - i - 1
    return (shift_table)


def search(text, pattern):
 
    m = len(pattern)
    n = len(text)

    # call to bring the info of shift_table
    shift_table = make_shift_table(text, pattern) 
    print(shift_table)

    # we need to keep track of below 3 :
    found = 0    # how many matches found?
    index = 0    # where was it found?
    counter = 0  # how many comparisons where there?
    

    while index <= n - 1:
        counter = counter + 1
        k = m - 1
        while index + k < n and pattern[k] == text[index + k]:
            k = k - 1
            counter = counter + 1
        # ref indicates number of jumps in the text with respect to text
        ref = index + k
        if ref < n:
            
            # To locate the pattern in the text string,
            # ref + 1 should be the sum of previous ref values if k < 0 
            if k < 0:
                found = found + 1
                print("Number of matches so far: ", found)
                print("Pattern found at the index of: ", ref + 1)
                print("Number of comparisons: ", counter)
                index += m
            else:
                #print("reference: ", shift_table[text[ref]]) # to test
                index = index + int(shift_table[text[ref]])
        else:
            
            break


def main():
    # test case 1
    txt = "THIS IS A TEST TEXT"
    pat = "TEST"
    print("TEXT = ", txt, ' vs  Pattern = ', pat)
    
    search(txt, pat)
    print("Case #1 is done!") 

    # test case 2
    txt = "AAAAAAAAAAAAAAAAAB"
    pat = "AAAAB"
    print("\nTEXT = ", txt, ' vs  Pattern = ', pat)
       
    search(txt, pat)
    print("Case #2 is done!") 

    # test case 3
    txt = "THIS IS A SIMPLE EXAMPLE"
    pat = "EXAMPLE"
    print("\nTEXT = ", txt, ' vs  Pattern = ', pat)
       
    search(txt, pat)
    print("Case #3 is done!") 


if __name__ == '__main__':
    main()
