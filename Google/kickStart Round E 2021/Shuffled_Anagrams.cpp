// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

/* author : pasricha_dhruv */

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //

// #include <algorithm>
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

bool f(string &s, string &t, int F[], int i)
{
    // 'a' + k -> j
    //  t[j] -> i
    // cout << i << ' ';
    char ch = 0;
    for (int j = 0; j < i; j++)
    {
        for (int k = 0; k < 26; k++)
        {

            if (F[k] > 0 and s[i] != t[j] and (k + 'a') != t[j] and s[j] != 'a' + k)
            {

                F[k]--;
                t[i] = t[j];
                t[j] = 'a' + k;
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    string s;
    cin >> s;

    int n = s.length();

    int F[26] = {0};
    bool ans = true;
    string t;
    for (char x : s)
        F[x - 'a']++, t += '-';

    for (int i = 0; i < n; i++)
    {
        char ch = 0;

        for (int j = 0; j < 26; j++)
        {
            if (F[j] > 0 and s[i] != j + 'a')
            {
                // cout << "found " << s[i] << " " << (char)(j + 'a') << endl;
                ch = 'a' + j;
                break;
            }
        }

        if (ch > 0)
        {

            F[ch - 'a']--;
            t[i] = ch;
        }
        else
        {

            ans = f(s, t, F, i);

            if (ans == false)
                break;
        }

        // cout << t << endl;
    }

    if (ans)
        cout << t;
    else
        cout << "IMPOSSIBLE";

    cout << endl;
}

int32_t main()
{
    FastIO;
    int test = 1;
    w(T)
    {
        cout << "Case #" << test++ << ": ";
        solve();
    }
    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //