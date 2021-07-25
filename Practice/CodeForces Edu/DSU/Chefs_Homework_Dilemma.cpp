#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<pair<pair<int, int>, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({{times[i][0], times[i][1]}, i});
        }
        sort(v.begin(), v.end());
        vector<int> friends(n + 1), chair(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (chair[j] <= v[i].first.first)
                {
                    friends[v[i].second] = j;
                    chair[j] = v[i].first.second;
                    break;
                }
            }
        }
        return friends[targetFriend];
    }
};
 