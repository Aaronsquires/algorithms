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
    
    # checks that n is at the last element
    if a[-1] != len(a):
        return len(a)

    # then the missing number is on the range (0, n)
    for i in range(1, len(a)):
        missing_number = a[i-1] + 1
        if a[i] != missing_number:
            return missing_number




array1 = [1,2,3,5]
array2 = [9,6,4,2,3,5,7,0,1]
array3 = [1,3,5,2,4,4]
array4 = [0, 1]
array5 = [0]

# solution(array4)

print(solution(array1))
print(solution(array2))
print(solution(array3))
print(solution(array4))
print(solution(array5))
