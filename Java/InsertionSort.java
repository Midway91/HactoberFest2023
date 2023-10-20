public class InsertionSort {

	static void result(int a[])
	{
		for(int i=1;i<a.length;i++)
		{
			int temp =a[i];
			int j=i-1;
			
			while(j>=0 && a[j]>temp)
			{
				a[j+1]=a[j];
				j=j-1;
			}
			a[j+1]=temp;
		}
	}
	
	
	public static void main(String[] args) {
		int a[]= {12,45,1,5,18,2,3};
		
		InsertionSort.result(a);
		for(int x:a) {
			System.out.print(x+" ");
		}

	}

}
