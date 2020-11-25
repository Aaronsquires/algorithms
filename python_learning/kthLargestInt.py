"""
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Returns the element representing the kth largest element in the stream.

EXAMPLE 1 -
Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8
"""

class KthLargest:

    # set the initialisers
    def __init__(self, k: int, nums: list):
        # nums is an array
        self.array = nums
        # k is a single int
        self.k = k

    def add(self, val: int) -> int:
        # add the value to the array
        self.array.append(val)
        # sort the array 
        self.array.sort()
        # returns the array 
        return self.array[len(self.array)-self.k]
        
Kth = KthLargest(3, [4,5,8,2])
print(Kth.add(3))
print(Kth.add(5))
print(Kth.add(10))
print(Kth.add(9))
print(Kth.add(4))