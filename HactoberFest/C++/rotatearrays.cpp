#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
    }
};

void disp(vector<int> temp)
{
    for (int i=0;i<temp.size();i++)
    {
        cout<<temp[i]<<" ";

    }
    cout<<endl;
}

int main(){

    Solution solution;
    vector<int> v1 = {1,2,3,4,5};
    int k1 = 3;
    solution.rotate(v1,k1);
    disp(v1);
}