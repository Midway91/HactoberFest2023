
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int isWinner(vector<int>& player1, vector<int>& player2) {
//         // n turns, pins 10 
//      //   xi= hattrick milega agar 10 hai i se pehle
//         int n = player1.size();
        
//         for(int i=0;i<n;i++){
//            if(player1[i]==10||player1[i-1]==10)
            
//                player1[i+1]=2*player1[i+1];
//         }
//            for(int i=0;i<n;i++){
//            if(player2[i]==10||player2[i-1]==10)
            
//                player2[i+1]=2*player2[i+1];
            
            
        
        
//     }

//             int sum=0,rum=0;

//             for(int i=0;i<n;i++){
//                 sum=sum+player1[i];
//                 rum=rum+player2[i];
//             }
        
//         {if (sum>rum)
//             return 1;
//         else if( rum>sum)
//             return 2;
//             else
//      return 0;
// }
// };


class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int n = player1.size();
        
        for (int i = 0; i < n; i++) {
            if (player1[i] == 10) { // strike
                if (i+2 < n) {
                    player1[i+2] *= 2;
                }
            } else if (i > 0 && player1[i-1] + player1[i] == 10) { // spare
                if (i+1 < n) {
                    player1[i+1] *= 2;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (player2[i] == 10) { // strike
                if (i+2 < n) {
                    player2[i+2] *= 2;
                }
            } else if (i > 0 && player2[i-1] + player2[i] == 10) { // spare
                if (i+1 < n) {
                    player2[i+1] *= 2;
                }
            }
        }

        int sum = accumulate(player1.begin(), player1.end(), 0);
        int rum = accumulate(player2.begin(), player2.end(), 0);
        
        if (sum > rum) {
            return 1;
        } else if (rum > sum) {
            return 2;
        } else {
            return 0;
        }
    }
};
