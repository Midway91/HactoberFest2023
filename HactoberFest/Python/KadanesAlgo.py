a = [1,2,3,-2,5]
def maxSum(a):
    max = 0
    cur = 0
    for i in range(0,len(a)):
        cur = cur + a[i]
        if(cur > max):
            max = cur
        if(cur <0):
            cur = 0
    return max
print(maxSum(a))
