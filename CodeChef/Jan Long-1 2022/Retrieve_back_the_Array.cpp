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

void addGroups(v<int> &A, set<int> &ignore)
{
    int i = ignore.size();
    int n = A.size();
    int val = 0;
    while (i < n)
    {
        bool ok = true;
        for (int j = 0; j < 4; j++)
            if (ignore.count(j + val))
                ok = false;
        if (ok)
            for (int j = 0; j < 4; j++)
                A[i++] = j + val;
        val += 4;
    }
}

void solve()
{
    int n;
    cin >> n;

    int x;
    cin >> x;

    v<int> Ans(n);
    set<int> ignore;

    int m = n % 4;

    if (m == 1 or m == 2)
    {
        Ans[0] = x;
        ignore.insert(x);
    }

    if (m == 2)
    {
        Ans[1] = 0;
        ignore.insert(0);
    }

    if (m == 3 or m == 0)
    {
        while (true)
        {
            int a = rand() % (500000) + 1;
            int b = rand() % (500000) + 1;

            if (a != b and a != x and b != x)
            {
                int c = a ^ b ^ x;
                if (c != 0 and c != a and c != b and c <= 500000)
                {
                    ignore.insert(a);
                    ignore.insert(b);
                    ignore.insert(c);
                    Ans[0] = a;
                    Ans[1] = b;
                    Ans[2] = c;
                    break;
                }
            }
        }
    }

    if (m == 0)
    {
        Ans[3] = 0;
        ignore.insert(0);
    }

    addGroups(Ans, ignore);

    for (int &x : Ans)
        cout << x << " ";

    cout << endl;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    srand(time(0));
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
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //