#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define fastio cin.tie(nullptr)->sync_with_stdio(false)
#define ll long long
#define endl "\n"

using namespace std;

ll divSum(int n)
{
    if (n == 1)
        return 1;

    ll result = 0;
    int f = sqrt(n);
    for (int i = 2; i <= f; i++)
    {
        if (n % i == 0)
        {
            if (i == (n / i))
                result += i;
            else
                result += (i + n / i);
        }
    }
    return (result + n + 1);
}

int32_t main()
{
    fastio;
    int t = 1;
    // Uncomment for multiple test cases
    cin >> t;
    while (t--)
    {
        // Code here
        ll x, a, b;
        cin >> x >> a >> b;

        ll temp = b * x;

        if (temp % a != 0)
        {
            cout << "-1" << endl;
        }

        else
        {
            ll n = temp / a;
            if (divSum(n) == x)
            {
                cout << n << endl;
            }
            else
                cout << "-1" << endl;
        }
    }
}