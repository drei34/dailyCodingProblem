class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        
        self.k = k
        self.data = [None for _ in range(k)]
        self.data_none = self.k
        self.f = None
        self.b = None
        

    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.f is None:
            self.f = 0
            self.b = 0
            self.data[self.f] = value
            self.data_none -= 1
            return True
        else:
            if (self.f - 1) % self.k == self.b:
                return False
            self.f = (self.f - 1) % self.k
            self.data[self.f] = value
            self.data_none -= 1
            return True

    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.b is None:
            self.f = 0
            self.b = 0
            self.data[self.b] = value
            self.data_none -= 1
            return True
        else:
            if (self.b + 1) % self.k == self.f:
                return False
            self.b = (self.b + 1) % self.k
            self.data[self.b] = value
            self.data_none -= 1
            return True
        

    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        
        if self.f is None:
            return False
        self.data[self.f] = None
        if self.b == self.f:
            self.f, self.b = None, None
        else:
            self.f = (self.f + 1) % self.k
        self.data_none += 1
        return True

    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        
        if self.b is None:
            return False
        self.data[self.b] == None
        if self.b == self.f:
            self.f, self.b = None, None
        else:
            self.b = (self.b - 1) % self.k
        self.data_none += 1
        return True
        

    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        if self.isEmpty():
            return -1
        return self.data[self.f]
        

    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        
        if self.isEmpty():
            return -1
        return self.data[self.b]
        

    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        """
        return self.data_none == self.k

    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        """
        return self.data_none == 0 
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
