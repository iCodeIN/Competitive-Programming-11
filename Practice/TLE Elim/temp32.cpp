// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// #include <algorithm>
#include <bits/stdc++.h>
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

#define pii pair<int, int>
#define ff first
#define ss second

#define int long long
#define mod 1000000007ll
#define endl "\n"
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int solve(vector<int> perm, vector<pair<int, int>> costumes)
{
    map<int, int> mp;
    int cnt = 0;

    for (int i : perm)
    {
        cout << i << " ";
        if ((mp[costumes[i].first] & mp[costumes[i].second]) == 0)
        {
            cnt++;
        }
        mp[costumes[i].first] = 1;
        mp[costumes[i].second] = 1;
    }
    cout << " : ";
    return perm.size() - cnt;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<pii> vc(k);
    for (int i = 0; i < k; i++)
        cin >> vc[i].ff >> vc[i].ss;

    vector<int> arr(k);
    for (int i = 0; i < k; i++)
        arr[i] = i;

    do
    {
        cout << solve(arr, vc) << endl;

    } while (next_permutation(all(arr)));
}
int32_t main()
{
    FastIO;

    // w(T)
    {
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // //
