

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

int freq(v(v(int)) & A, int ch, int l, int r)
{
    int f = A[ch][r];
    if (l != 0)
        f -= A[ch][l - 1];
    return f;
}

void query(v(v(int)) & A, int l, int r, int k)
{
    int mx = 0;
    int sum = 0;
    for (int i = 25; i >= 0; i--)
    {
        int f = freq(A, i, l, r);
        mx = max(f, mx);
        sum += f;
    }

    if (mx > k or sum < k)
    {
        cout << "No";
        return;
    }

    v(char) Ans(r - l + 1);
    int n = Ans.size();
    int k_ = n - 1;
    for (int i = 0; i <= 25; i++)
    {
        int f = freq(A, i, l, r);

        while (f--)
        {
            Ans[k_--] = i + 'A';
        }
    }
    if (mx != k)
        reverse(Ans.begin() + n - k, Ans.end());
    cout << "Yes\n";
    for (int i = 0; i < n; i++)
        cout << Ans[i];
}

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    v(v(int)) F(26, v(int)(n, 0));

    for (int i = 0; i < n; i++)
    {
        int idx = s[i] - 'A';
        F[idx][i] = 1;
    }

    for (int i = 0; i < 26; i++)
        for (int j = 1; j < n; j++)
            F[i][j] += F[i][j - 1];

    int q;
    cin >> q;

    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        --l;
        --r;
        query(F, l, r, k);
        cout << endl;
    }
}

int32_t main()
{
    FastIO;

    w(T)
        solve();

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //