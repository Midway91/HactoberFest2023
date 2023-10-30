#include <iostream>
#include <limits.h>
using namespace std;

class RodCut
{

private:
        int p[100],r[100];
        int n;
        int m;
public:
        void input_array();
        int Cut_rod_Bottom_up(int);
        int getN();
};

void RodCut::input_array()
{
   
    std::cout << "Enter the total length of the rod: " << std::endl;
    std::cin >> m;
    std::cout << "Enter the price of rod cuts one by one: " << std::endl;

    for (int i=0;i<m;i++)
    {
        std::cin >> p[i];
    }

    std::cout << "Enter the value of n: " << std::endl;
    std::cin >> n;
   
}

int RodCut::getN()
{
    return n;
}

int RodCut::Cut_rod_Bottom_up(int n)
{
    int q;
    
    r[0] = 0;

    for (int i=1;i<=n;i++)
    {
        q = INT_MIN;

        for (int j=0;j<i;j++)
        {
            int price = p[j]+r[i-j-1];

            if (price>q)
            {
                q = price;
            }
        }
        r[i] = q;
    }

    return r[n];
}

int main()
{
    RodCut obj;
    obj.input_array();
    int maxcost = obj.Cut_rod_Bottom_up(obj.getN());
    std::cout << "Maximum cost : " << maxcost << std::endl;

    return 0;
    
}