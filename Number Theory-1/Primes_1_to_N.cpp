#include <bits/stdc++.h>
using namespace std;

void primeSeive(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
        }
    }

    cout << endl;
}

bool checkPrimeSqrtN(int n)
{
    int f = 0;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            f++;
            if (i * i != n)
            {
                f++;
            }
        }
    }
    return f == 2;
}

void primeSqrtN(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (checkPrimeSqrtN(i))
        {
            cout << i << ' ';
        }
    }
    cout << endl;
}


int main()
{
    int n;
    cin >> n;

    primeSqrtN(n); // O (N * N^(1/2))
    primeSeive(n); // O (N * Log(Log(N))) => O(N)

    return 0;
}