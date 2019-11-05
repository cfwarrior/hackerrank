#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumSum function below.
long maximumSum(vector<long> a, long mod)
{
    long maxi = 0;
    set<long> s;
    s.insert(0);
    long cur = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        cur = (cur + a[i]) % mod;
        maxi = max(maxi, cur);
        auto it = s.upper_bound(cur);
        if (it != s.end())
        {
            maxi = max(maxi, cur - (*it) + mod);
        }
        s.insert(cur);
    }
    return maxi;
}