

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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
    int count = 0;
    int idx_sum = 0;
};

char s[1000001];
void solve()
{
    int n;
    cin >> n;
    cin >> s;

    v(node) pre(n), suf(n);

    pre[0].count = (s[0] == '*');
    suf[n - 1].count = (s[n - 1] == '*');

    if (suf[n - 1].count == 1)
        suf[n - 1].idx_sum = n - 1;

    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1];
        if (s[i] == '*')
            pre[i].idx_sum += i, pre[i].count++;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if (s[i] == '*')
            suf[i].idx_sum += i, suf[i].count++;
    }

    int ans = INT64_MAX;
    for (int i = 0; i < n; i++)
    {

        // int temp = INT32_MAX;
        if (s[i] == '*')
        {
            int left = 0;
            int right = 0;
            int idx_sum = pre[i].idx_sum;
            int c = pre[i].count;

            left = (c * i) - (idx_sum) - ((c * (c - 1)) / 2);

            idx_sum = suf[i].idx_sum;
            c = suf[i].count;

            right = (idx_sum) - (c * i) - ((c * (c - 1)) / 2);
            int ans1 = left + right;
            // cout << left << " " << right << endl;
            if (left >= 0 and right >= 0)
                ans = min(ans, ans1);
        }
        else
        {
            int l1 = 0;
            int l2 = 0;
            int r1 = 0;
            int r2 = 0;

            int idx_sum = pre[i].idx_sum;
            int c = pre[i].count;

            l1 = (c * i) - (idx_sum) - ((c * (c - 1) / 2));

            if (i > 0)
                l2 = (c * (i - 1)) - (idx_sum) - ((c * (c - 1) / 2));

            idx_sum = suf[i].idx_sum;
            c = suf[i].count;

            if (i < n - 1)
                r1 = (idx_sum) - (c * (i + 1)) - ((c * (c - 1) / 2));

            r2 = (idx_sum) - (c * i) - ((c * (c - 1) / 2));

            // cout << l1 << " " << l2 << " " << r1 << " " << r2 << endl;
            int ans1 = l1 + r1;
            int ans2 = l2 + r2;
            if (l1 >= 0 and l2 >= 0 and r1 >= 0 and r2 >= 0)
                ans = min(ans, min(ans1, ans2));
        }

        // cout << ans << endl;
    }

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