class Student:
    def __init__(self, name, esc190mark): # declare characteristics
        self.name = name # initialize the characteristics s.name = "Jack"
        self.esc190mark = esc190mark #s.esc190mark = 98
    def print(self):
        print(self.name, self.esc190mark)

s = Student("Jack",98)
s.print() # Student.print(s) is the function declared by the Student class

'''
Stack operations
push(elem): add elem to the top of the stack
pop(): return the elem from the top of the stack, and remove it
isEmpty(): return True if the stack is empty, False otherwise
'''
'''
class Stack:
    def __init__(self):
        self.stack = []
    def is_empty(self):
        return len(self.stack) == 0
    
    def push(self, elem):
        self.stack.append(elem) # O(n) where n is len(self.stack)

    def pop(self):
        # warning
        if self.is_empty():
            print("Cannot pop from an empty stack")
        else:
            return self.stack.pop() # O(1)

s = Stack()
s.stack # is the empty list, []

s.push(52)
s.push(125)
print(s.stack)
print(s.pop())
print(s.stack)

'''
# Implement a linked list class in Python
# Use it to implement a stack with O(l) push and pop
# head->n1->n2-> .. nk

class LL:
    def __init__(self):
        self.head = None

    def insert(self, loc, element):
        new_node = Node(element) # data: element, next: None
        if loc == 0:
            new_node.next = self.head.next
            self.head = new_node
        else:
            cur = self.head # current node
            for i in range(loc):
                cur = cur.next
            new_node.next = cur.next # used to be cur.next but now
            cur.next = new_node # set cur.next to the new_node
    def delete(self, loc):
        if loc == 0:
            self.head = self.head.next
            cur = self.head
        else:
            for i in range(loc-1):
                cur = cur.next
            # cur is the node before the node that we want to delete
            cur.next = cur.next.next

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.stack = LL() # self.stack is not a linked list with head==None

    # push: insert at 0
    # pop: get 0th element, and then delete 0th element
    def push(self, elem):
        self.stack.insert(0, elem)

    def pop(self, elem):
        cur_node = self.stack.head
        self.stack.delete(0)
        return cur_node.data

n = Node(52)
# n.data is 52, n.next is None

