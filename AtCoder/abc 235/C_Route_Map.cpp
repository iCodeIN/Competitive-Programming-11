#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fastio cin.tie(nullptr)->sync_with_stdio(false)
#define int long long
#define endl "\n"

using namespace std;

bool binarySearch(vector<string> &arr, string &x, int n)
{
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (x == (arr[m]))
            return true;
        else if (x > (arr[m]))
            l = m + 1;
        else
            r = m - 1;
    }
    return false;
}

int32_t main()
{
    fastio;
    int t = 1;
    // Uncomment for multiple test cases
    // cin >> t;
    while (t--)
    {
        // Code here
        int n, m;
        cin >> n >> m;

        vector<string> s;
        vector<string> T;

        for (int i = 0; i < n; i++)
        {
            string temp;
            cin >> temp;
            s.push_back(temp);
        }

        for (int j = 0; j < m; j++)
        {
            string temp;
            cin >> temp;
            T.push_back(temp);
        }

        sort(T.begin(), T.end());
        for (int i = 0; i < n; i++)
        {
            // if(binarySearch(T, s[i], s.size())){
            if (binarySearch(T, s[i], m))
                cout << "Yes" << endl;

            else
                cout << "No" << endl;
        }
    }
}