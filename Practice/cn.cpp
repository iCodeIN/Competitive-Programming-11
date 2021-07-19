#include <bits/stdc++.h>
#define int long long int
using namespace std;

int f(int x)
{
    return (x * (x + 1)) / 2;
}

int32_t main()
{
    int k;
    cin >> k;

    vector<int> A;
    int i = 1;

    do
    {
        A.push_back(f(i));
        i++;
    } while (A.back() <= k);

    i = 0;
    int j = A.size() - 1;
    bool ans = false;

    while (i <= j)
    {
        int sum = A[i] + A[j];

        if (sum == k)
        {
            ans = true;
            break;
        }
        else if (sum < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    if (ans == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}