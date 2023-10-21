//Create the Kth Factor of n.
class Solution {
    public int kthFactor(int n, int k) {
        List<Integer> l=new ArrayList<Integer>();//Creating ArrayList
        for(int i=1;i<n;i++)
        {
            if(n%i==0)//Checks for the factors 
            l.add(i);
        }
        l.add(n);//Adds the number as it is also its own factor
        if(k>l.size())
        return -1;//Returns -1 as there is no K number of factors 
        else{
            return l.get(k-1);//Returns the kth factor
        }
    }
}