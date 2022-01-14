#include <bits/stdc++.h>
using namespace std;

#define int long long int

#define v vector

class Solution
{
public:
    int insert(map<int, int> &mp, int x)
    {

        auto itr = mp.upper_bound(x);

        if (itr != mp.begin())
            itr--;
        int cur = 1 + itr->second;

        if (itr != mp.end())
            itr++;

        if (itr != mp.end())
        {
            if (itr->second == cur)
                mp.erase(itr);
        }

        return mp[x] = cur;
    }

    int lengthOfLIS(vector<int> &nums)
    {

        map<int, int> mp;
        int ans = 0;
        mp[INT_MIN] = 0;
        for (int num : nums)
        {
            ans = max(ans, insert(mp, num));
        }
        return ans;
    }

    int f(v<int> &A)
    {
        int n = A.size();
        int ans = n - lengthOfLIS(A);
        return ans;
    }

    int kIncreasing(vector<int> &arr, int k)
    {
        int n = arr.size();
        v<v<int>> A;
        v<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;
            v<int> current;
            int j = i;
            int prev = 1;
            while (j < n)
            {
                visited[j] = true;
                current.push_back(arr[j]);
                j += k;
            }
            A.push_back(current);
        }
        n = A.size();
        for (int i = 0; i < n; i++)
        {
            ans += f(A[i]);
        }
        return ans;
    }
};

int32_t main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int &x : A)
        cin >> x;

    int k;
    cin >> k;

    Solution ans;
    cout << ans.kIncreasing(A, k) << endl;
}