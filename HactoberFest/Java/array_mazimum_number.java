class LargestNumber
{
public static void main(String args[])
{
int[] a = new int[] { 22, 3, 550, 4, 11, 100};
int max = a[0];
for(int i = 1; i < a.length;i++) { if(a[i] > max)
{
max = a[i];
}
}
 
System.out.println("The Given Array is:");
for(int i = 0; i < a.length;i++)
{
System.out.println(a[i]);
}
 
System.out.println("The Largest Number is:" + max);
}
}
