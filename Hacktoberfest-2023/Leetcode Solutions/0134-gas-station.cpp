class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       //kitn petorl kam padh gya h
       int deficit=0;

       // kitna pertorl bacha h
       int balance=0;

       //circut kaha se start krre ho phel
        int start=0; 

        for(int i=0;i<gas.size();i++)
        {
            balance += gas[i]-cost[i];

            if(balance<0)
            {
                deficit +=balance;
                start=i+1;
                balance=0;
            }
        }

        if(deficit + balance>=0)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
};