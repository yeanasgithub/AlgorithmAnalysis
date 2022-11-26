## Algorithm Analysis Lab 09
## Yeana Bond


# Function to perform heapify operation
def do_heapify(A, n, i):
    
    largest = i
    left = 2 * i + 1 # left child
    right = 2 * i + 2 # right child
    # if left child exists and it is greater than its parent
    if left < n and A[i] < A[left]:
        largest = left
        
      
    # if right child exits and it is greater than its parent
    if right < n and A[largest] < A[right]:
        largest = right
       
       
    if largest != i:
        # swapping elements
        A[i],A[largest] = A[largest],A[i] 
        do_heapify(A, n, largest)
         
    


# Insert a new elem to the array
def insert_new(A, p): # insert_new_and_heapify_from_left_to_right
    A.append(p)
    heap_sort(A)  # swap the first and the last then starting from the firts elem, perform heapsort 

# Required heap_sort function
def heap_sort(A):
    
    n = len(A)
    # Creating max heap
    for i in range(n, -1, -1):
        do_heapify(A, n, i)
        
        print( A ) 
    
    ## Double checking if it is max heap one more time
    #for i in range(0, n, 1):
    #    do_heapify(A, n, i)
    ## Not necessary
    
    print(" \n  -------------------------Heap construction is done! ")
    # extracting the elements
    print( "\n  -------------------------Sorting starts here:")
    for i in range(n-1, 0, -1):
        # swapping elements
        A[i], A[0] = A[0], A[i] 
        print( A )
        do_heapify(A, i, 0)
        

# Driver code
#A = [1, 5, 4, 3, 10, 2, 6, 7, 9, 8, 11]
A = [1, 9, 4, 2, 7, 6, 10, 5, 3, 8, 12]
print(" Original Array: ", A)


# Calling heap sort function
heap_sort(A)


print( "-The array at the last line above shows that the sorted array BEFORE adding 12-")
## Given a Binary Heap and a new element to be added to the Heap
## Adding a new elem to the Heap should be done while maintaining
## the properties of Heap
print("\n=========================================================================================")
print("\n=========================================================================================")
A = [11, 10, 6, 9, 8, 2, 4, 7, 3, 1, 5, 12]

print(" \n\n Array after inserting 12 to the heapified original array: ", A)

heap_sort(A)

print( " ---- The array at the last line above shows that the sorted array AFTER adding 12 ---- ")

input("\nRun complete. Press the Enter key to exit.")

