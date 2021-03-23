#include <iostream>
#include <algorithm>
#define inf INT32_MAX
#define int long long
using namespace std;

const int N = 1e5 + 1;
const int N_ = 2 * 1e5 + 1;
const int M = 1e9 + 7;
int fact[N];
int invFact[N];
int A[N_];

int pow(int x, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = (ans * x) % M;
        x = (x * x) % M;
        n >>= 1;
    }
    return ans;
}

void precompute()
{
    invFact[0] = fact[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        fact[i] = (i * fact[i - 1]) % M;
        invFact[i] = -1;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int sum = 0;
        for (int i = 0; i < 2 * n; sum += A[i++])
            cin >> A[i];
        int ans = 0;
        if (sum % (n + 1) == 0)
        {
            sum /= (n + 1);
            int f = 0;
            for (int i = 0; i < 2 * n and f < 2; i++)
                if (A[i] == sum)
                    A[i] = inf, f++;
            if (f == 2)
            {
                bool check = true;
                sort(A, A + 2 * n);
                for (int i = 0, j = 2 * n - 3; i < j and check; i++, j--)
                    if (A[i] + A[j] != sum)
                        check = false;
                if (check)
                {
                    n--;
                    ans = fact[n];
                    int same = 0;
                    for (int i = 0; i < n; i++)
                    {
                        int j = i;
                        int cur = 0;
                        while (j < n and A[j] == A[i])
                            j++, cur++;
                        if (invFact[cur] == -1)
                            invFact[cur] = pow(fact[cur], M - 2);
                        ans = (ans * invFact[cur]) % M;
                        if (A[i] * 2 == sum)
                            same = cur;

                        i = j - 1;
                    }

                    ans = (ans * pow(2, n - same)) % M;
                }
            }
        }
        cout << ans << endl;
    }
}