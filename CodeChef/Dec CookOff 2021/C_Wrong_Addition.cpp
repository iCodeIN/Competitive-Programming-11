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
    string a;
    string s;
    cin >> a >> s;

    int n1 = a.size();
    int n2 = s.size();
    int i = n1 - 1;
    int j = n2 - 1;
    string ans = "";
    while (i >= 0 and j >= 0)
    {
        int sumDigit = s[j] - '0';
        int numDigit = a[i] - '0';

        if (numDigit <= sumDigit)
        {
            ans = to_string(sumDigit - numDigit) + ans;
        }
        else if (j > 0)
        {
            j--;
            sumDigit += 10 * (s[j] - '0');
            if (sumDigit - numDigit > 9 or sumDigit - numDigit < 0)
            {
                ans = "-1";
                break;
            }
            else
            {
                ans = to_string(sumDigit - numDigit) + ans;
            }
        }
        else
        {
            ans = "-1";
            break;
        }
        i--;
        j--;
    }
    if (i == -1)
        ans = s.substr(0, j + 1) + ans;
    else
        ans = "-1";

    cout << stoll(ans) << endl;
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