# You are given a list of n-1 integers and these integers are in the range of 1 to n. 
# The list can have duplicates and/or be unsorted or sorted

#  Write an efficient code to find the missing integer.

def solution(a):
    array = a
    duplicate = False

    print(array)
    # check if the list is sorted if not sort the array
    if (array != sorted(array)):
        array.sort() #sort array

    # check if the array has duplicate numbers
    if len(array) == len(set(array)):
        duplicate = False
    else:
        duplicate = True

    if duplicate == True:
        array = list(set(array))

    # calculated using the formula (n+1)*(n+2)/2
    total = (len(array) + 1) * (len(array) + 2) / 2
    # calculate the sum of all the numbers in the array
    array_total = sum(array)

    # take away the total and the current array total
    print(total - array_total)
    





array = [1,2,3,5]
array2 = [1,3,5,2,6]
array3 = [1,3,5,2,4,4]

solution(array3)

