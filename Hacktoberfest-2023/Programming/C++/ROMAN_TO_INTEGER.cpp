class Solution {
public:
    int romanToInt(string s) {
       int a=0;
        for(int i=0;i<s.length();i++)
        { if(s[i]=='I'&&s[i+1]=='V')
        {
            a+=4;
            i++;
        }
        else if(s[i]=='I'&&s[i+1]=='X')
        {
            a+=9;
            i++;
        }
         else if(s[i]=='X'&&s[i+1]=='L')
        {a+=40;
        i++;}
         else if(s[i]=='X'&&s[i+1]=='C')
         {
             a+=90;
             i++;
         }
          else if(s[i]=='C'&&s[i+1]=='D')
          {a+=400;
          i++;

          }
           else if(s[i]=='C'&&s[i+1]=='M')
           {
               a+=900;
               i++;
           }
            else if(s[i]=='I')
         a++;
        else if(s[i]=='V')
            a+=5;
        else if(s[i]=='X')
            a+=10;
        else if(s[i]=='L')
            a+=50;
        else if(s[i]=='C')
            a+=100;
        else if(s[i]=='D')
            a+=500;
        else if(s[i]=='M')
            a+=1000;
        }
        return a;
    }
};
