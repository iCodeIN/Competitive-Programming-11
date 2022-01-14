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
    string s;
    cin >> s;

    int n = s.size();

    v<int> open;
    v<int> closed;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            open.push_back(i);
        else
            closed.push_back(i);
    }
    int n1 = open.size();
    int n2 = closed.size();

    v<int> openPrefixSum(n1);
    v<int> closedPrefixSum(n2);

    openPrefixSum[0] = open[0];
    closedPrefixSum[0] = closed[0];

    for (int i = 1; i < n1; i++)
        openPrefixSum[i] += openPrefixSum[i - 1];
    for (int i = 1; i < n2; i++)
        closedPrefixSum[i] += closedPrefixSum[i - 1];

    int openIdx = -1;
    int closedIdx = -1;

    int o = 0;
    int cl = 0;
    for (int pos = 0; pos < n; pos += 2)
    {
        if (s[pos] == '(')
            ++openIdx, ++o;
        else
            closedIdx++, cl++;

        int openExp = pos / 2;
        int closedExp = pos - openExp;

        if (s[pos] == '(')
        {
            int closedReq = closedExp - cl;
            int closedCost = 0;
            if (n2 - closedIdx >= closedReq)
            {
                closedCost = closedPrefixSum[closedIdx + closedReq];
                if (closedIdx != -1)
                    closedCost -= closedPrefixSum[closedIdx];
                closedCost -= pos * closedReq;
                closedCost += ((closedReq) * (closedReq - 1)) / 2;
            }
            else
                continue;
            int openCost = 
        }
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