class Solution {
public:

// making another matrix not changeing orignal matrix
    void setZeroes(vector<vector<int>>& matrix) {
      //creating two stes v1 and v2
        set<int> v1,v2;
      
    //using two fro loop we start traversing through matrix 
        for(int i=0; i<matrix.size();i++){           
            for(int j=0; j<matrix[i].size();j++){
              
             // if the element in the matrix is equal to zero then insert adjacent elements near value zero
                if(matrix[i][j]==0) {
                    v1.insert(i);
                    v2.insert(j);
                }
            }
        }

        for(int i=0; i<matrix.size();i++){           
            for(int j=0; j<matrix[i].size();j++){
              
                if(v1.count(i) || v2.count(j)) {
                    matrix[i][j]=0;
                }
            }
        }

    }
};
