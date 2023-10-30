class Heap:

    def __init__(self) -> None:
        self.size = 0
        self.arr = [-1]

    def insert(self,  val):

        self.size+=1
        index = self.size
        self.arr.append(val)

        # place val at right position
        while index > 1:

            parentIndex = index // 2

            if self.arr[index] > self.arr[parentIndex]:
                self.arr[index], self.arr[parentIndex] = self.arr[parentIndex], self.arr[index]
                index = parentIndex

            else:
                break
    
    def delete(self):
        
        # replace root val with last val
        self.arr[1] = self.arr[-1]
        self.size-=1

        # place root val to uts right position
        index = 1

        while index < self.size:
            
            left = index*2
            right = left + 1
            largest = index

            if left < self.size and self.arr[largest] < self.arr[left]:
                largest = left
            
            if right < self.size and self.arr[largest] < self.arr[right]:
                largest = right

            if largest == index:
                return
            else:
                self.arr[index], self.arr[largest] = self.arr[largest], self.arr[index]
                index = largest


def heapify(arr, n, index):

    left = index*2
    right = left + 1
    largest = index

    if left <= n and arr[largest] < arr[left]:
        largest = left

    if right <= n and arr[largest] < arr[right]:
        largest = right
    
    if largest != index:
        arr[index], arr[largest] = arr[largest], arr[index]
        index = largest
        heapify(arr, n, index)


def buildHeap(arr, n):

    start = n // 2

    for i in range(start, 0, -1):
        heapify(arr, n, i)


def heapSort(arr, n):

    while n != 1:

        arr[1], arr[n] = arr[n], arr[1]
        n-=1
        heapify(arr, n, 1)


h = Heap()
h.insert(50)
h.insert(30)
h.insert(70)
h.insert(40)
h.insert(80)
h.insert(100)
print(h.arr)

h.delete()
print(h.arr)

arr = [-1, 12, 56, 43, 6, 78, 87, 5, 44, 3, 23, 32]
print("\nCreating heap from array........")
buildHeap(arr, 11)
print(arr[1:])

print("\nheap sort........")
heapSort(arr, 11)
print(arr[1:])

