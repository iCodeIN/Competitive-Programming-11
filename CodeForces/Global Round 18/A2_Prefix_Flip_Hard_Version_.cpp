// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
void solve()
{
    int n;
    cin >> n;

    string a;
    string b;
    cin >> a >> b;

    v<int> Ans;
    int op = 0;
    int l = 0;
    int r = n - 1;

    for (int i = n - 1; i >= 0; i--)
    {

        bool given = a[r] == '1';
        bool expected = b[i] == '1';

        if (op & 1)
            given = not given;

        if (given != expected)
        {
            if (i > 0)
            {
                bool first = a[l] == '1';
                if (op & 1)
                    first = not first;
                if (first == expected)
                {
                    Ans.push_back(1);
                }
            }
            op++;
            Ans.push_back(i + 1);
            swap(l, r);
        }
        if (l < r)
            r--;
        else
            r++;
    }
    cout << Ans.size() << " ";
    for (int x : Ans)
        cout << x << " ";
    cout << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //\

// 0100110
// 1000110

// 8 7 5 3