#!/usr/bin/python3
class Node:
    def __init__(self,data=None,next=None):
        self.data = data
        self.next = next
        

class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0
    
    def add_start(self,data):
        ptr = Node(data,self.head)
        self.head = ptr
        self.size += 1
    
    def add_end(self,data):
        if not self.head:
            # If there is no element then add at start
            self.add_start(data)
            return
        # Creating a temp node and then traversing to the end node and adding the new node
        temp = self.head
        while(temp.next):
            temp = temp.next
        temp.next = Node(data,None)
        self.size += 1 

    def add(self,index,data):
        assert not (index > self.size or index < 0), "Index out of range"
        
        # Traversing to the index and adding a new node and poiting the new node to the next elemnt
        if index == 0:
            self.add_start(data)
            return
        temp = self.head
        for i in range(self.size):
            if i == index-1:
                temp.next = Node(data,temp.next)
                break
            temp = temp.next
        
        self.size += 1
  
    def remove(self,index):
        assert not (index > self.size-1 or index < 0), "Index out of range"
        # Traversing to the index before the entered index and poiting it to the next element skipping the current index
        temp = self.head
        if index == 0:
            self.head = self.head.next
        else:
            for i in range(self.size-1):
                if i == index-1:
                    temp.next = temp.next.next
                    break
                temp = temp.next
            
        self.size -= 1
  
    def length(self):
        return self.size

    def display(self):
        if self.head:
            temp = self.head
            while(temp.next):
                print(temp.data,"->",end=" ")
                temp = temp.next
            print(temp.data,"->",end=" ")
            print("*")
        
    def getdata(self,index):
        assert not ( index > self.size-1 or index < 0), "Index out of range"
        
        temp = self.head
        for i in range(self.size):
            if i == index:
                return temp.data
            temp = temp.next
        
class Iterator:
    def __init__(self,n):
        self.node = n.head
        self.head = n.head
        self.size = n.length()
        self.current = 0
        
    def has_next(self):
        if self.current < self.size:
            return True
        else:
            self.current = 0
            self.node = self.head
            return False
        
    def data(self):
        temp = self.node.data
        self.node = self.node.next
        self.current += 1
        return temp
    
l = LinkedList()
l.display()
l.add_end(0)
l.add_start(10)
l.add_end(80)
l.add_start(20)
l.add_start(30)
l.add_start(40)
l.add_end(50)
l.add_start(130)
l.display()
l.add(5,100)
l.display()
l.remove(3)
l.display()
l.remove(7)
l.display()
print(l.getdata(1))
Iter = Iterator(l)

while Iter.has_next():
    print(Iter.data())