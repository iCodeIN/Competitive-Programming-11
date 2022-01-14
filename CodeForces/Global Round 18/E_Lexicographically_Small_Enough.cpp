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

    v<int> diff(n + 1);
    string s;
    string t;
    cin >> s >> t;

    int ans = 0;

    bool done = false;
    map<char, set<int>> mp;

    for (int i = 0; i < n; i++)
        mp[s[i]].insert(i);

    int swapsDone = 0;

    for (int i = 0; i < n; i++)
    {
        int closest = INT_MAX;
        char choosen = 0;
        for (char ch = 'a'; ch < t[i]; ch++)
            if (mp[ch].size() > 0)
            {
                int idx = *mp[ch].begin();
                if (idx < closest)
                {
                    closest = idx;
                    choosen = ch;
                }
            }
        if (choosen == 0)
        {
            if (mp[t[i]].size() > 0)
            {
                closest = *mp[t[i]].begin();
                choosen = t[i];
            }
            else
                break;
        }

        cout << closest << " " << choosen << endl;

        if (closest + swapsDone > i)
        {

            closest += swapsDone;
            ans += (closest - i);
            swapsDone++;
        }
        cout << ans << endl;
        mp[choosen].erase(mp[choosen].begin());

        if (choosen < t[i])
        {
            done = true;
            break;
        }
    }

    if (!done)
        ans = -1;
    cout << ans << endl;
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