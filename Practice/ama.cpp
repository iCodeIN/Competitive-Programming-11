#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007ll
const int N = 1e6;
vector<bool> isPrime(N + 1, true);
const int N2 = 1e5;
int64_t dp[N + 1];

void pre()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
}

int64_t solve(char s[], int pos)
{
    if (s[pos] == 0)
        return 1;

    if (dp[pos] != -1)
        return dp[pos];

    if (s[pos] == '0')
        return solve(s, pos + 1);
    int64_t n = 0;
    int64_t ans = 0;
    for (int i = 0; i < 6 and s[pos + i] != 0; i++)
    {
        int d = s[pos + i] - '0';
        n = n * 10 + d;

        if (n <= 1000000 and isPrime[n])
            ans = (ans + solve(s, pos + i + 1)) % mod;
    }
    return dp[pos] = ans;
}

int countPrimeStrings(char *s)
{
    pre();
    memset(dp, -1, sizeof(dp));
    int ans = solve(s, 0);

    return ans;
}