#include <bits/stdc++.h>
using namespace std;

int Select(vector<int> &store, int k)
{
    if(store.size()<=5){
        sort(store.begin(),store.end());
        return store[k-1];
    }
    int min = *min_element(store.begin(), store.end());
    int max = *max_element(store.begin(), store.end());
    vector<int> medians;
    for (int i = 0; i < store.size(); i += 5)
    {
        vector<int> temp(store.begin() + i, (i + 5 < store.size() ? store.begin() + i + 5 : store.end()));
        sort(temp.begin(), temp.end());

        medians.push_back(temp[(temp.size() / 2)]);
    }
    int mainMedian = medians[medians.size() / 2];
    vector<int> s;
    vector<int> l;
    for (int i = 0; i < store.size(); i++)
    {
        if (store[i] <= mainMedian)
        {
            s.push_back(store[i]);
        }
        else
        {
            l.push_back(store[i]);
        }
    }
    if (s.size() < k)
    {
        return Select(l, k - (s.size()));
    }
    else
    {
        return Select(s, k);
    }
}
int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> store;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        store.push_back(l);
    }
    cout << Select(store, n-k+1) << endl;
    int rank = 0;
    for (auto i : store)
        rank += (i < m);
    cout << rank + 1<<endl;

    return 0;
}
