class Node:
  def __init__(self, value, next_node=None):
    self.value = value
    self.next_node = next_node
    
  def get_value(self):
    return self.value
  
  def get_next_node(self):
    return self.next_node
  
  def set_next_node(self, next_node):
    self.next_node = next_node



# Our LinkedList class
class LinkedList:
  def __init__(self, value=None):
    self.head_node = Node(value)
  
  def get_head_node(self):
    return self.head_node
  
# Add your insert_beginning and stringify_list methods below:
  def insert_beginning(self, new_value):
    new_node = Node(new_value)
    new_node.set_next_node(self.head_node)
    self.head_node = new_node

  # Define your remove_node method below:
  def remove_node(self, value_to_remove):
    current_node = self.head_node
    if current_node.get_value() == value_to_remove:
      self.head_node = current_node.get_next_node()
    else:
      while current_node:
        next_node = current_node.get_next_node()
        if next_node.get_value() == value_to_remove:
          current_node.set_next_node(next_node.get_next_node())
          current_node = None
        else:
          current_node = next_node

  def get_list(self):
    string_list = ""
    current_node = self.get_head_node()
    while current_node:
      if current_node.get_value() != None:
        string_list += str(current_node.get_value()) + "\n"
      current_node = current_node.get_next_node()
    return string_list

  def get_list_value(self, get_value):
    list_value = ""
    value = get_value
    current_node = self.get_head_node()

    while current_node:
      if current_node.get_value() == get_value:
        list_value += str(current_node.get_value())
      current_node = current_node.get_next_node()
    # return list_value

    if list_value == "":
      return print("No Value: " + str(value))
    else:
      return list_value

  def removeNthFromEnd(self, n: int):
          list_length = 1
          head = self.get_head_node()
          node = head
          
          while(node!=None):
              list_length +=1 
              node = node.get_next_node()
              
          node_to_remove = list_length - n
          
          if(node_to_remove == 1):
              head = head.get_next_node()
          else:
              node = head
              i = 1
              while((i+1)!=node_to_remove):
                  i+=1
                  node = node.get_next_node()
              node.next = node.get_next_node().get_next_node()
          
          return head


ll = LinkedList()
ll.insert_beginning(70)
ll.insert_beginning(5675)
ll.insert_beginning(90)
print(ll.get_list())
print("value: " + ll.get_list_value(90))

ll.removeNthFromEnd(1)
print(ll.get_list())




