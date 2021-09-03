

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
// #define all(x) x.begin(), x.end()

// #define int long long int
#define endl "\n"

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007ll
const int N = 1e6;
vector<bool> isPrime(N + 1, true);
const int N2 = 1e5;
long long int dp[N2 + 10];

void pre()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
}

long long int solve(char *s)
{

    int len = strlen(s);
    for (int j = len; j >= 0; j--)
    {

        if (j == len)
        {
            dp[j] = 1;
        }
        else
        {

            long long int n = 0;
            long long int ans = 0;
            for (int i = 0; i <= 6 and j + i < len; i++)
            {
                int d = s[j + i] - '0';
                n = (n * 10) + d;

                if (n <= N and isPrime[n])
                    ans = (ans + dp[j + i + 1]) % mod;
            }

            dp[j] = ans;
        }
    }

    return dp[0];
}

int countPrimeStrings(char *s)
{
    pre();
    long long int ans = solve(s);

    return ans;
}

int32_t main()
{
    FastIO;

    // w(T)
    char *s = new char[10000];
    cin >> s;
    cout << countPrimeStrings(s);

    return 0;
}

// // //  // // //  // // //  // // // // // //  // // // // // //  // // //