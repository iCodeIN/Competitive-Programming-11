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

    string s;
    cin >> s;

    map<char, int> mp;
    for (auto ch : s)
        mp[ch]++;

    priority_queue<pair<int, char>> pq;

    for (auto itr : mp)
        pq.push({itr.second, itr.first});

    int i = -1;
    int j = n;

    while (pq.size() > 0)
    {
        auto p1 = pq.top();
        pq.pop();

        if (pq.size() == 0)
        {
            cout << "NO" << endl;
            return;
        }

        auto p2 = pq.top();
        pq.pop();

        s[++i] = p2.second;
        s[--j] = p1.second;
        p1.first--;
        p2.first--;

        if (p1.first)
            pq.push(p1);
        if (p2.first)
            pq.push(p2);
    }
    cout << "YES" << endl;
    cout << s << endl;
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
