l = [1,2,4,7,9,10,14,16,18,30,60,80,82,84,86,91,97,102]



def binarySearchInt(array,left,right,value):
			
	while (left <= right):
		mid = (left + right) //2
		
		if (array[mid] == value):
			return mid
		
		elif(array[mid] > value):
			right = mid-1
		else:
			left = mid+1
	return -1
		 


def binarySearchRec(array,left,right,value):
	
	mid = (left + right)//2
	
	if (left > right):
		return -1
	
	elif(array[mid] == value):
		return mid
	
	elif(array[mid] > value):
		return binarySearchRec(array,left,mid-1,value)
	
	else:
		return binarySearchRec(array,mid + 1, right,value)
		


print(binarySearchRec(l,0,len(l)-1,9))
print(binarySearchInt(l,0,len(l)-1,9))
	
		

	
