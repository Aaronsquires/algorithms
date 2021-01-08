# A binary gap within a positive integer N is any maximal sequence of
#  consecutive zeros that is surrounded by ones at both ends in the binary
#  representation of N.

# For example, number 9 has binary representation 1001 and contains a binary gap
#  of length 2. The number 529 has binary representation 1000010001 and contains
#  two binary gaps: one of length 4 and one of length 3. The number 20 has binary
#  representation 10100 and contains one binary gap of length 1.
#  The number 15 has binary representation 1111 and has no binary gaps.

# Write a function:
# def solution(N)
# that, given a positive integer N, returns the length of its longest binary gap.
#  The function should return 0 if N doesn't contain a binary gap.

# For example, given N = 1041 the function should return 5, because N has binary
#  representation 10000010001 and so its longest binary gap is of length 5.
# Number 9 has binary representation 1001 and contains a binary gap of length 2.
# The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
# The number 20 has binary representation 10100 and contains one binary gap of length 1.
# The number 15 has binary representation 1111 and has no binary gaps.
# The number 32 has binary representation 100000 and has no binary gaps.

# Assume that:
# N is an integer within the range [1..2,147,483,647].

# Complexity:
# expected worst-case time complexity is O(log(N));
# expected worst-case space complexity is O(1).

def solution1(N):
    counter = 0
    result = 0
    found_one = False

    while N:
        
        if N & 1 == 1:
            if (found_one is False):
                found_one = True
            else:
                result = max(result, counter)
            counter = 0
        else:
            counter += 1
        N >>= 1

    return result


def solution2(N):
    # convert the input number to a binary format
    # binary calculation
    Number_to_binary = str(bin(N))[2:]
    binary_number = Number_to_binary
    # check the binary number
    # print(binary_number)
    # check if found a gap in the binary nunber
    found_gap = False
    # biggest gap found
    biggest_gap = 0
    counter = 0

    # loop through the Binary number 
    for char in binary_number:
        if char == '1':
            # check if the counter is bigger than current biggest gap
            if biggest_gap < counter:
                # set the new biggest gap as the size of the counter
                biggest_gap = counter
            # set the found gap to true
            found_gap = True
            # reset the counter
            counter = 0
        elif found_gap:
            counter += 1
            # print(str(counter))

    # print(str(biggest_gap))
    return biggest_gap



# Run 
print(solution1(1041))
print(solution2(29210))

