

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
#include <map>
// #include <set>
#include <queue>
#include <stack>
// #include <unordered_map>
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

#define int long long int
#define mod 1000000007ll
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

void solve()
{
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    v(int) A(n);

    for (int &x : A)
        cin >> x;
    bool ok = true;
    for (int x : A)
    {
        mp[x]++;
        ok &= (mp[x] <= k);
    }

    if (!ok)
    {
        cout << -1 << endl;
        return;
    }
    sort(all(A));

    if (k == 1)
    {
        for (int i = n - 1; i >= 0; i--)
            cout << A[i] << ' ';
        cout << endl;
        return;
    }
    v(int) LIS(n);

    for (int i = 0; i < k; i++)
        LIS[i] = i + 1;
    for (int i = k; i < n; i++)
    {
        int temp = A[i];
        LIS[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] <= A[i])
                LIS[i] = max(LIS[i], LIS[j] + 1);
        }
        if (LIS[i] <= k)
            continue;

        int j = i - 1;
        int idx = -1;
        for (int p = 0; p < i; p++)
        {
            if (A[p] == temp)
            {
                idx = p;
                break;
            }
        }
        if (idx == -1)
        {
            idx = i - 1;
        }
        else
        {
            idx--;
        }

        // cout << idx << endl;

        for (int j = i; j > idx; j--)
            A[j] = A[j - 1], LIS[j] = LIS[j - 1];

        // LIS idx
        LIS[idx] = 1;
        A[idx] = temp;
        for (int j = idx - 1; j >= 0; j--)
        {
            if (A[j] <= A[idx])
                LIS[idx] = max(LIS[idx], LIS[j] + 1);
        }
    }
    for (int x : A)
        cout << x << " ";
    cout << endl;
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //