
List = ["h","e","l","l","o"]
string = "hello"

def reverseStringArray(List) -> None:
    # In python you can call the reverse command to reverse a string         
    List.reverse()
    return List

def reverseString(List) -> None:
    temp = ""
    for i in List: 
      temp = i + temp
    return temp

# or you can use recursion to change the position of the characters
def reverseStringRecursion(left, right) -> None:
    # takes in two pointers left and right
    # if left is less than right then swap the left and right character
    if left < right:
        List[left], List[right] = List[right], List[left]
        left + 1, right - 1
    
    #pass in the head and tail index
    return List

if __name__ == "__main__":
    print("Reverse List: ", List)
    print(reverseStringArray(List))
    print(reverseString(string))