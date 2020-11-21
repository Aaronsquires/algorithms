#Sorting Algorithms - Aaron Squires

#Insertion sort
def insertionsort(list):
    for index in range(1, len(list)):
                       
        current = list[index]
        position = index
                       
        while position > 0 and list[position-1] > current:
            list[position] = list[position-1]
            position -= 1

        list[position] = current
    return list

#Quick Sort
def quicksort(list):
    if len(list) <=1:
        return list
    else:
        pivot = list[len(list) // 2]
        left = [x for x in list if x < pivot]
        middle = [x for x in list if x == pivot]
        right = [x for x in list if x > pivot]
        return quicksort(left) + middle + quicksort(right)


#List to Sort
sort_list = [9, 2, 1, 4, 7, 6, 5, 3, 8]
sort_list2 = [7, 4, 5, 2, 6, 1, 3, 9, 8]

alist = [54,26,93,17,77,31,44,55,20]
bubbleSort(sort_list)
print(sort_list)

#Print methods
print("sort list", sort_list, sort_list2)
print("insertion sort", insertionsort(sort_list2))
print("quick sort", quicksort(sort_list2))
print("bubble sort", bubbleSort(sort_list2))

class Sort_Algorithms(object):
    def __repr__(self):
        sort_list = [9, 2, 1, 4, 7, 6, 5, 3, 8]
        return 

if __name__ == "__main__":
    print(Sort_Algorithms())