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
struct marks
{
    int dsa, toc, dm;

    void input()
    {
        cin >> dsa >> toc >> dm;
    }

    bool operator==(const marks &b)
    {
        return dsa == b.dsa and toc == b.toc and dm == b.dm;
    }

    bool operator>(const marks &b)
    {
        if (dsa + toc + dm < b.dsa + b.toc + b.dm)
            return false;

        if (dsa + toc + dm > b.dsa + b.toc + b.dm)
            return true;

        if (dsa < b.dsa)
            return false;

        if (dsa > b.dsa)
            return true;

        return toc > b.toc;
    }
};

void solve()
{
    marks d;
    marks s;

    d.input();
    s.input();

    if (d > s)
        cout << "DRAGON";
    else if (d == s)
        cout << "TIE";
    else
        cout << "SLOTH";

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
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //