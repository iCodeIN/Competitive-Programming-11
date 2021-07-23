

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

struct node
{
    int *ptr = new int[5];
    int len;
    node()
    {
        for (int i = 0; i < 5; i++)
            ptr[i] = 0;
        len = 0;
    }
};

int calc(v(node) & A, int j)
{
    int pre = 0;
    int i = 0;
    int n = A.size();
    while (i < n)
    {
        if ((2 * A[i].ptr[j]) - A[i].len + pre > 0)
            pre += (2 * A[i].ptr[j]) - A[i].len;
        else
            return i;
        i++;
    }
    return n;
}
void solve()
{
    int n;
    cin >> n;
    v(node) A(n);

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (char x : s)
        {
            A[i].ptr[x - 'a']++;
        }
        A[i].len = s.length();
    }

    int ans = 0;
    int i = 0;

    sort(A.begin(), A.end(), [](node a, node b)
         { return ((2 * a.ptr[0]) - a.len) > ((2 * b.ptr[0]) - b.len); });
    ans = max(ans, calc(A, 0));

    sort(A.begin(), A.end(), [](node a, node b)
         { return ((2 * a.ptr[1]) - a.len) > ((2 * b.ptr[1]) - b.len); });
    ans = max(ans, calc(A, 1));

    sort(A.begin(), A.end(), [](node a, node b)
         { return ((2 * a.ptr[2]) - a.len) > ((2 * b.ptr[2]) - b.len); });
    ans = max(ans, calc(A, 2));

    sort(A.begin(), A.end(), [](node a, node b)
         { return ((2 * a.ptr[3]) - a.len) > ((2 * b.ptr[3]) - b.len); });

    ans = max(ans, calc(A, 3));

    sort(A.begin(), A.end(), [](node a, node b)
         { return ((2 * a.ptr[4]) - a.len) > ((2 * b.ptr[4]) - b.len); });

    ans = max(ans, calc(A, 4));

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