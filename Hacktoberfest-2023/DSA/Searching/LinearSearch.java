class sol
{
	static int solu(int arr[],int num) {
		for(int i=0;i<arr.length;i++) 
		{
			if(arr[i]==num) {
				return i;
			}
		}
		return -1;
	}
}


public class LinearSearch {

	public static void main(String[] args) {
		int a[]= {1,4,6,7,3};
		int val=3;
		int c=sol.solu(a, val);
		System.out.println(c);

	}

}
