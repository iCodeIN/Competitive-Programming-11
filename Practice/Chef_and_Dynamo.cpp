#include <iostream>
using namespace std;

#define int long long

int pow(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans *= x;
        x *= x;
        n >>= 1;
    }
    return ans;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a;
        cin >> a;
        int temp = 2 * pow(10, n);
        int s = temp + a;
        cout << s << endl;
        fflush(stdout);
        int b;
        cin >> b;
        cout << temp / 2 - b << endl;
        fflush(stdout);
        int d;
        cin >> d;
        cout << temp / 2 - d << endl;
        fflush(stdout);
        int status;
        cin >> status;

        if (status == 1)
            continue;
        else
            exit(0);
    }
}