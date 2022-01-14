// Author: Tushar Khanduri
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <bitset>
#include <algorithm>
#define int long long
#define endl "\n"
#define pb push_back
#define vec vector
using namespace std;

//==============================================================================
class Math
{
public:
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int lcm(int a, int b)
    {
        return a * (b / gcd(a, b));
    }

    void set_sieve(vector<bool> &sieve, int n)
    {
        for (int i = 2; i * i <= n; i++)
            if (sieve[i])
                for (int j = i * i; j <= n; j += i)
                    sieve[j] = false;
    }

    int pow(int x, int n)
    {
        int ans = 1;
        while (n > 0)
        {
            if (n & 1)
                ans *= x;
            x *= x;
            n = n >> 1;
        }
        return ans;
    }

    int pow(int x, int n, int m)
    {
        int ans = 1;
        while (n > 0)
        {
            if (n & 1)
                ans = (ans * x) % m;
            x = (x * x) % m;
            n = n >> 1;
        }
        return ans;
    }

    int modinv(int x, int p)
    {
        return pow(x, p - 2);
    }

} Math;
//=============================================================================

void solve()
{
    string a, b;
    cin >> a >> b;
    int x = b.size(), y = a.size();
    string ans = "";
    int i = 1;

    while (y || x)
    {
        // cout<<"in iteration "<<i++<<endl;
        if (y > x)
        {
            // cout<<"-1 from y>x"<<endl;
            cout << -1 << endl;
            return;
        }
        if (y == 0)
        {
            ans += b[--x];
            continue;
        }
        if (b[x - 1] >= a[y - 1])
        {
            ans += '0' + b[x - 1] - a[y - 1];
            x--;
            y--;
        }
        else
        {
            int num1 = (b[x - 2] - '0') * 10 + (b[x - 1] - '0');
            int num2 = a[y - 1] - '0';
            int diff = num1 - num2;
            if (diff < 0 || diff > 9)
            {
                // cout<<"-1 from diff"<<endl;
                // cout<<num1<<"-"<<num2<<" = "<<diff<<endl;
                // cout<<"ans so far: "<<ans<<endl;
                cout << -1 << endl;
                return;
            }
            ans += diff + '0';
            x -= 2;
            y--;
        }
    }
    int idx = 0;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans[i] != '0')
        {
            idx = i;
            break;
        }
    }
    for (int i = idx; i >= 0; i--)
        cout << ans[i];
    cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}