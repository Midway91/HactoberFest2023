//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static bool cmp (pair<double,Item>a,pair<double,Item>b){
        return a.first>b.first;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>>v;
        for (int i=0; i<n; i++){
            double perunitval = (1.0*arr[i].value)/arr[i].weight;
            pair<double,Item>p=make_pair(perunitval,arr[i]);
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        double totalval = 0;
        for (int i=0; i<n; i++){
            if (v[i].second.weight > W){
                totalval += W*v[i].first;
                W = 0;
            }
            else{
                totalval += v[i].second.value;
                W = W-v[i].second.weight;
            }
        }
        return totalval;
    }
        
};