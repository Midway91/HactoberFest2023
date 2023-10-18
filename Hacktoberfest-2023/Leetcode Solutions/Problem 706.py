
class MyHashMap:

    def __init__(self):
        # better to be a prime number, less collision
        # store (key, value) in the bucket
        self.size = 2069
        self.buckets = [[] for _ in range(self.size)]

    def put(self, key: int, value: int) -> None:
        bucket, index = self.getIndex(key)
        if index < 0:
            bucket.append((key,value))
        else:
            bucket[index] = (key, value)

    def get(self, key: int) -> int:
        bucket, index = self.getIndex(key)
        if index < 0:
            return -1
        else:
            return bucket[index][1]

    def remove(self, key: int) -> None:
        bucket, index = self.getIndex(key)
        if index < 0:
            return
        else:
            bucket.remove(bucket[index])
    
    def hashKey(self, key):
        return key % self.size
    
    # find the target bucket and index of the key
    # if index > 0, then (key, value) exist
    # if index < 0, then (key, value) not exist
    def getIndex(self, key):
        hashResult = self.hashKey(key)
        bucket = self.buckets[hashResult]
        
        for i, (k, v) in enumerate(bucket):
            if k == key:
                return bucket, i
        
        return bucket, -1
        


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
