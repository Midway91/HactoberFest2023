class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n==1 )
         return 0;
        int x = kthGrammar(n-1,ceil(k/2.0));
        cout<<x<<" "<<ceil(k/2)<<endl;
        if(k%2==1)
          return x;
        return (x==0)?1:0;
        
    }
};