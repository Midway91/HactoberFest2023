class Solution {
public:
    string reorganizeString(string s) {
        int hash[26]={0};
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }

    // find most occuring character
    char maxfreqChar;
    int maxfreq=INT_MIN;

    for(int i=0;i<26;i++)
    {
        if(hash[i]>maxfreq)
        {
            maxfreq=hash[i];
            maxfreqChar=i+'a';
        }
    }

    int index=0;

        while(maxfreq>0 && index<s.size())
        {
            s[index]=maxfreqChar;
            maxfreq--;
            index +=2;
        }
 
        if(maxfreq !=0)
         {
           return "";
          }

        hash[maxfreqChar-'a']=0;

        // Let's place rest of character

        for(int i=0;i<26;i++)
        {
            while(hash[i]>0)
            {
            index=index>=s.size() ? 1: index;
            s[index]=i+'a';
  
            hash[i]--;
            index=index+2;
        }
    }
    return s;
 
    }
};