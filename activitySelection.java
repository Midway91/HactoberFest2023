import java.util.*;
// time complexity == O(n)
/*activity are done such that the ending of the first must be  */
public class ActivitySelection{
    public static void main(String[] args) {
        int start[] = {1,3,0,5,8,5};
        Integer end[] = {2,4,6,7,9,9};

        //here end sort is sorted
        

        int maxAct = 0;
        ArrayList<Integer> ans = new ArrayList<>();  //to save the idx of the works performed
        //1st Activity
        maxAct = 1;
        ans.add(0);
        int lastEnd = end[0];//to track end time of the activity choosen
        for(int i =1; i<end.length ;i++){
            if(start[i] >= lastEnd){
                maxAct++;
                ans.add(i);
                lastEnd =end[i];
                System.out.println(ans);
            }
        }
        System.out.println("Max activities = " + maxAct);
        for(int i =0;i<ans.size();i++){
            System.out.print("A" + ans.get(i) + "  ");
        }
        System.out.println();
    }
}
