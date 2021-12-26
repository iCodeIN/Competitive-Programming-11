#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n, 0);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end());
        int opt1 = (arr[n - 2] - arr[0]) * arr[n - 1];
        int opt2 = (arr[n - 1] - arr[0]) * arr[n - 2];

        cout << max(opt1, opt2) << endl;
    }
}