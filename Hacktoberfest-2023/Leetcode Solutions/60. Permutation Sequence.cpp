class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr(n);
        for(int i=1;i<=n;i++)
        arr[i-1]=i;
        int counter=1;
        do{
            if(counter == k)
            break;
            counter++;
        }while(next_permutation(arr.begin(),arr.end()));
        string ans ="";
        for(int i=0;i<n;i++){
            ans.push_back(arr[i]+'0');
        }
        return ans;
    }

};