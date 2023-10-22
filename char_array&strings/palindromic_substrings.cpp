class Solution {
public:

 int expandindex(string s,int i,int j ){
     int count=0;
     while(i>=0 && j<s.length()  && s[i]==s[j]){
         
           count++;
         i--;
         j++;
       
     }
     return count;
     
 }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
              int odd=expandindex(s,i,i);
            count=count+odd;

        
        int even=expandindex(s,i,i+1);
            count=count+even;

        
       
        }
       
      return count; 
    }
};
