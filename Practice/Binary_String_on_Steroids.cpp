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

int check(string &s, int d, int sum)
{
    int n = s.length();
    n /= 2;
    int ans = n;
    for (int start = 0; start < d; start++)
    {
        int cur = 0;
        for (int i = start, j = 0; j < n / d; j++, i += d)
        {
            if (s[i] == '1')
                cur++;
        }
        int remove = sum - cur;
        int add = (n / d) - cur;
        ans = min(ans, add + remove);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // reverse(s.begin(), s.end());
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        s += s[i];
        sum += (s[i] == '1');
    }

    if (sum == 0)
        cout << 1;
    else
    {
        int ans = sum - 1;

        for (int d = 1; d * d <= n; d++)
        {
            if (n % d == 0)
            {
                ans = min(ans, check(s, d, sum));
                if ((n / d) <= (n / 2))
                    ans = ans = min(ans, check(s, n / d, sum));
            }
        }
        cout << ans;
    }
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
