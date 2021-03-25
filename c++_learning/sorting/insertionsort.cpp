#include<iostream>  
using namespace std;

/*

Algorithm Structure

1. Assume the first element is already sorted
2. Select each element one by one
3. value = selected element. Index = index to insert the element in sorted sub-array
4. index = index of selected element
5. Compare it with elements in the sorted sub-array
6. shift all the elements greater than the selected element one place to the right

*/

// void insertion_sort(int UnsortedArray[])
// {
//     int i, value, index;
//     int n = sizeof(UnsortedArray);

//     for(i=1; i<n; i++)
//     {
//         value = UnsortedArray[i];
//         index = i;

//         while(index > 0 && UnsortedArray[index -1]> value)
//         {
//             UnsortedArray[index] = UnsortedArray[index -1];
//             index = index -1;

//         }
    
//     UnsortedArray[index] = value;

//     }

// }

// int main ()
// {
//     int UnsortedArray[5] = {4, 2, 5, 3, 1};

//     insertion_sort(UnsortedArray);

//     cout << UnsortedArray;

//     return 0;
// }