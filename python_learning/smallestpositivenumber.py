# Write a function:

# def solution(A)

# that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

# For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

# Given A = [1, 2, 3], the function should return 4.

# Given A = [−1, −3], the function should return 1.



def solution(A):
    # write your code in Python 3.6
    
    # get the max number in the array
    array_max_number = max(A)
    
    # checks if our array only has one element
    if len(A) == 1:
        if A[0] == 1:
            return 2
        else:
            return 1
            
    # checks if the array has negative elements
    if array_max_number < 1:
        return 1
            
    array_length = [0] * array_max_number
            
    for i in range(len(A)):
        if A[i] > 0:
            if array_length[A[i] - 1] != 1:
                array_length[A[i] - 1] = 1
    
    for i in range(len(array_length)):
        if array_length[i] == 0:
            return i + 1
    
    return i + 2
            