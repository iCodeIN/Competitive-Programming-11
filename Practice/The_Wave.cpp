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
int binarySearch(v(int) & A, int x)
{
    int l = -1;
    int r = A.size();

    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        if (A[m] >= x)
            r = m;
        else
            l = m;
    }

    if (r != (int)A.size() and A[r] == x)
        return INT32_MAX;

    return A.size() - r;
}
void solve()
{
    int n, q;
    cin >> n >> q;

    v(int) A(n);
    for (int &x : A)
        cin >> x;
    sort(all(A));

    while (q--)
    {
        int r;
        cin >> r;
        int negatives = binarySearch(A, r);
        // cout << negatives << " " << endl;
        if (negatives == INT32_MAX)
            cout << '0';
        else if (negatives & 1)
            cout << "NEGATIVE";
        else
            cout << "POSITIVE";

        cout << endl;
    }
}

int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //