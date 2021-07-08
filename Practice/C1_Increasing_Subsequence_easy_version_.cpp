

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

#include <algorithm>
// #include <bits/stdc++.h>
// #include <cmath>
#include <iostream>
// #include <map>
// #include <set>
// #include <queue>
// #include <stack>
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
    int n;
    cin >> n;
    v(int) A(n);
    for (int &x : A)
        cin >> x;
    int i = 0;
    int j = n - 1;
    int ans = 0;
    int prev = 0;
    string sans = "";
    while (i <= j)
    {
        int minI = min(A[i], A[j]);
        int maxI = max(A[i], A[j]);

        if (minI > prev)
        {
            ans++;
            prev = minI;
            if (minI == A[i])
                i++, sans += 'L';
            else
                j--, sans += 'R';
        }
        else if (maxI > prev)
        {
            ans++;
            prev = maxI;
            if (maxI == A[i])
                i++, sans += 'L';
            else
                j--, sans += 'R';
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    cout << sans << endl;
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //