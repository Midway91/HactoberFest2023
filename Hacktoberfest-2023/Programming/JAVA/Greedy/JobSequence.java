/*problem
Given a set of N jobs where each jobi has a deadline and profit associated with it. Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit if and only if the job is completed by its deadline. The task is to find the number of jobs done and the maximum profit.

Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.
Example 1:

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Since at deadline 1 Job3 can give the maximum profit and for deadline 4 we left with only Job1 hence Job1 and Job3 can be done with maximum profit of 60 (20+40).*/

class Solution
{
    //Function to find the maximum profit and the number of jobs done.
    int[] JobScheduling(Job arr[], int n)
    {
        // Your code here
         Arrays.sort(arr, (a, b) -> Integer.compare(b.profit, a.profit));
        
        //store deadlines
        Map<Integer, Integer> map=new HashMap<>();
        int totalProfits=0;
        int totalJobs=0;
        
        for(int i=0; i<n; i++){
            int profit=arr[i].profit;
            int deadline=arr[i].deadline;
            
            for(int j=deadline; j>=1; j--){
                //check if deadline is stored
                if(map.containsKey(j)==false){
                    totalProfits=totalProfits+profit;
                    totalJobs=totalJobs+1;
                    
                    map.put(j, 1);
                    break;
                }
            }
        }
        
        //make res
        int[] res=new int[2];
        res[0]=totalJobs;
        res[1]=totalProfits;
        
        return res;
    }
}