# A dominant member in the array is one that occupies over half the positions in the array, for example:

# {3, 67, 23, 67, 67}

# 67 is a dominant member because it appears in the array in 3/5 (>50%) positions.

# provide a method that takes in an array and returns an index of the dominant member if one exists and -1 if there is none.

# Solve the problem with the following constraints:

# Expected time complexity is O(n)
# Expected space complexity is O(1)

array = [3, 67, 23, 67, 67]
array2 = [1,2,3,4,5,6,7,8]
array3 = [1, 3, 3, 4, 3]

def solution(array): 
    hash_map = {} 
    array_size = len(array)
    counter = 0

    for i in range(array_size): 
        if array[i] in hash_map: 
            hash_map[array[i]] += 1
        else: 
            hash_map[array[i]] = 1

    for key in hash_map: 
        if hash_map[key] > array_size / 2: 
            counter += 1
            return key

    if(counter == 0): 
        return -1
  
print(solution(array))
print(solution(array2))
print(solution(array3))

