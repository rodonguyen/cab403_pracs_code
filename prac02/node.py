

class Node:
    def __init__(self, value, next_node=None):
        self.value = value
        self.next = next_node


node1 = Node(1)
node2 = Node(2)
node3 = Node(3)

node1.next = node2


print((node1.next).value)
