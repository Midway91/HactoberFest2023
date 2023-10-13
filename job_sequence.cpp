/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool cmp (Job a , Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort (arr,arr+n,cmp);
        int maxideadline = INT_MIN;
        for (int i=0; i<n; i++){
            maxideadline = max(maxideadline,arr[i].dead);
        }
        vector<int>schedule(maxideadline+1,-1);
        int count = 0;
        int maxprofit = 0;
        for (int i=0; i<n; i++){
            int currprofit = arr[i].profit;
            int currid = arr[i].id;
            int currdead = arr[i].dead;
            for (int k=currdead; k>0; k--){
                if (schedule[k] == -1){
                    count++;
                    maxprofit += currprofit;
                    schedule[k] = currid;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(maxprofit);
        return ans;
    } 
};