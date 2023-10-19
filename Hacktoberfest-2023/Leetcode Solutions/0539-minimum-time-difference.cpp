class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        
        // creating an vector to store all value in integet format
        //convert time string into minutes iteger
        vector<int>minutes;
        
        
        for(int i=0;i<timePoints.size();i++)
        {
            string curr=timePoints[i];
            
            int hours= stoi(curr.substr(0,2));
            int min=stoi(curr.substr(3,2));
            int totalMinutes=hours*60 + min;
            minutes.push_back(totalMinutes);
        }
        
        // second step
        
        sort(minutes.begin(),minutes.end() );
            
            
        // step 3
            
        int mini=INT_MAX;
        int n=minutes.size();
        for( int i=0;i<n-1;i++)
        {
            int diff=minutes[i+1]-minutes[i];
                mini=min(mini,diff);
        }
        
        //something missing
        int lastDiff=(minutes[0]+1440)-minutes[n-1];
        mini=min(mini,lastDiff);
        
        return mini;
    }
};