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
    int r, g, b;
    cin >> r >> g >> b;

    int n = r + g + b;
    v<char> color(n);
    v<int> blue(b);
    v<int> red(r);
    v<int> green(g);
    int i = 0;
    int j = 0;
    while (j < b)
    {
        blue[j++] = i;
        color[i++] = 'B';
    }
    j = 0;
    while (j < r)
    {
        red[j++] = i;
        color[i++] = 'R';
    }
    j = 0;
    while (j < g)
    {
        green[j++] = i;
        color[i++] = 'G';
    }
    v<pii> edge(n - 1);
    int loc[] = {1, 1, 1};

    edge[0] = {blue[0], green[0]};
    edge[1] = {green[0], red[0]};
    i = 2;
    if (b >= 2)
    {
        edge[2] = {red[0], blue[1]};
        loc[0] = 2;
        i++;
    }
    while (loc[0] < b)
    {

        if (loc[1] < r)
        {
            edge[i++] = {green[loc[2] - 1], red[loc[1]]};
            edge[i++] = {red[loc[1]], blue[loc[0]]};
            loc[1]++;
        }
        else if (loc[2] < g)
        {
            edge[i++] = {green[loc[2]], red[loc[1] - 1]};
            edge[i++] = {green[loc[2]], blue[loc[0]]};
            loc[2]++;
        }
        else
        {
            cout << "-1\n";
            return;
        }

        loc[0]++;
    }

    while (loc[1] < r)
    {
        edge[i++] = {red[loc[1] - 1], red[loc[1]]};
        loc[1]++;
    }

    while (loc[2] < g)
    {
        edge[i++] = {red[loc[1] - 1], green[loc[2]]};
        loc[2]++;
    }

    for (int i = 0; i < n; i++)
        cout << color[i];
    cout << endl;
    for (auto &e : edge)
    {
        if (e.ff > e.ss)
            swap(e.ff, e.ss);
        cout << ++e.ff << ' ' << ++e.ss;
        cout << endl;
    }
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