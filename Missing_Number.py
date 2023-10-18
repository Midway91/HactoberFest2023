#Problem link and solution for Missing Number in CSES
#https://cses.fi/problemset/task/1083/

n=int(input())
arr=input().split()
arr=[int(each) for each in arr]
arr=sorted(arr)
if(1 not in arr):
    print(1)
elif(n not in arr):
    print(n)
else:
    for i in range(len(arr)):
        if(i+1!=arr[i]):
            print(i+1)
            break
