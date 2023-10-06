import java.util.* ;
import java.io.*; 
public class Solution {
	public static ArrayList<Integer> findNonRepeating(ArrayList<Integer> a) {
		ArrayList<Integer> b=new ArrayList<Integer>();
		//calculating the xor of all the numbers
		int xor=0;
		for (int i=0;i<a.size();i++){
			xor=xor^a.get(i);
		}
		//getting the right most set bit
		int rb=xor & ~(xor-1);
		int x=0;
		int y=0;
		//dividing them into two arrays depending upon the right most set bit
		for (int i=0;i<a.size();i++){
			if ((a.get(i)&rb)!=0){
				y=y^a.get(i);
			}
			else{
				x=x^a.get(i);
			}
		}
		b.add(x);
		b.add(y);
		return b;

	}
}
