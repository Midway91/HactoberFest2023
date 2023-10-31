 bool isSafe(int &row , int &col, int &n, vector<vector<int>> &check){
        //checked if any prev row had queen in this col
        for(int i=0;i<row;i++){
            if(check[i][col]==1){
                return false;
            }
        }
        //checking front diagonal-row decreases-col increases
        int startrow=row;
        int startcol=col;
        while(startrow>=0 && startcol<n){
            if(check[startrow][startcol]==1){
                return false;
            }
            startrow--;
            startcol++;
            
        }
        //checking for back diagonal
        startrow=row;
        startcol=col;
        while(startrow>=0 && startcol>=0){
            if(check[startrow][startcol]==1){
                return false;
            }
            startrow--;
            startcol--;
        }
        
        return true;
    }


   void nqueen(vector<int> temp,vector<vector<int>> &ans,vector<vector<int>> &check,int &n,int row){
       //base case
       if(row==n){
           
           return;
       }
       
       
       //placing in each col
       for(int i=0;i<n;i++){
           if(isSafe(row,i,n,check)){
            //   cout<<row<<" "<<i<<" is safe"<<endl;
               check[row][i]=1;
            //   cout<<"pushing "<<row<<" "<<i<<endl;
               temp.push_back(i+1);
               nqueen(temp,ans,check,n,row+1);
               //backtrack
               temp.pop_back();
                // cout<<"popping "<<row<<" "<<i<<endl;
               check[row][i]=0;
           }
       }
       
       return;
       
   }
   
   
    vector<vector<int>> nQueen(int n) {
       
        vector<vector<int>> ans;
        vector<vector<int>> check( n , vector<int> (n, 0)); 
        vector<int> temp;
        nqueen(temp,ans,check,n,0);
        return ans;
        
    }
