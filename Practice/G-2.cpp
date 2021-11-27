#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007ll
const int N = 1e6;
vector<bool> isPrime(N + 1, true);

void pre()
{
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++)
        if (isPrime[i])
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
}

int64_t solve(string &s, int pos)
{
    int n = s.length();
    vector<int64_t> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        
        int64_t cur = 0;
        for (int j = 1; j <= min(i, 6); j++)
        {
            int64_t p = stoll(s.substr(i - j, j));

            if (s[i - j] != '0' and p <= N and isPrime[p])
                cur = (cur + dp[i - j]) % mod;
        }
        dp[i] = (cur + dp[i]) % mod;
    }
    return dp[n];
}

int countPrimeStrings(char *s)
{
    pre();
    string x = "";
    for (int i = 0; s[i] != 0; i++)
        x += s[i];
    int64_t ans = solve(x, 0);
    return ans;
}

int main()
{

    char s[100];
    cin >> s;

    cout << countPrimeStrings(s);
}