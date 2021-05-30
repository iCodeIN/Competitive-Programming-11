// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

/* 
    // solvedUsing : binarySearch + slidingWindow + map

    // Time Complexity : O(logN*(N)) where N is the size of the Given Array

    // l = length of the longest subArray such that after removing it from the
    given Array, The remaining Array contains all the integers
    in the interval : [1,N]

   // So, The ans will be =  Array.size() - l
*/

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
#include <unordered_map>
// #include <unordered_set>
#include <vector>

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

using namespace std;

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)

#define FastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define v(Type) vector<Type>
#define all(x) x.begin(), x.end()

// #define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

bool isGood(v(int) & A, int k, int n)
{
    unordered_map<int, int> mp;
    int m = A.size();
    for (int i = k; i < m; i++)
        mp[A[i]]++;
    bool ans = (mp.size() == n);
    for (int l = 1, r = k; r < m and ans == false; l++, r++)
    {
        mp[A[l - 1]]++;
        if (mp[A[r]] == 1)
            mp.erase(A[r]);
        else
            mp[A[r]]--;
        ans = (mp.size() == n);
    }
    return ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    v(int) A(m);
    for (int &x : A)
        cin >> x;

    int l = -1;
    int r = m + 1;

    while (r - l > 1)
    {
        int mid = (l + r) >> 1;

        if (isGood(A, mid, n))
            l = mid;
        else
            r = mid;
    }

    int ans = m - l;

    cout << ans << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //