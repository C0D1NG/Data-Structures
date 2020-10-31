class Heap:
    """
    simple implementation of the heap structure with 'insert' and 'removeMin'
    """
    def __init__(self,maxLength):
        self.maxLength = maxLength
        self.n = 0 # length of heap
        self.a = [None]*(maxLength+1)
         # Heap is stored on a[1] to a[n]

    def insert(self,x):
        if self.n>=self.maxLength:
            raise RuntimeError("Overflow")
        self.n += 1
        self.a[self.n] = x
        self.tooSmall(self.n)
    
    def removeMin(self):
        if self.n<=0:
            raise RuntimeError("Heap is empty")
        x = a[1]
        self.n -= 1
        if self.n>0:
            self.a[1] = self.a[self.n+1]
            self.tooBig(1)
        return x
    
    def isEmpty(self):
        return self.n==0
    
    def tooSmall(self, i):
        # a[i] is smaller then its predecessor.
        if i==1: return
        predecessor = i//2
        if self.a[i]<self.a[predecessor]:
            self.swap(i,predecessor)
            self.tooSmall(predecessor)
    
    def tooBig(self, i):
        # a[i] is bigger then its predecessor.
        if 2*i+1 <= self.n:
            if self.a[2*i]<self.a[2*i+1]: smallestSuccessor = 2*i
            else:                         smallestSuccessor = 2*i+1
        elif 2*i <= self.n:
            smallestSuccessor = 2*i
        else:
            return
        if self.a[i]>self.a[smallestSuccessor]:
            self.swap(i, smallestSuccessor)
            self.tooBig(smallestSuccessor)
            
    def swap(self, i, j):
        self.a[i],self.a[j] = self.a[j],self.a[i]
    
