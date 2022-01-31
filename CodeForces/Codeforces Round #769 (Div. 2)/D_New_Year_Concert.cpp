// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
/* author : pasricha_dhruv */
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#include <bits/stdc++.h>
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
using namespace std;
using LL = long long int;
using LD = long double;
using vi = vector<LL>;
using pii = pair<LL, LL>;
const LL mod = 1e9 + 7;
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
#define all(x) x.begin(), x.end()
#define double LD
#define endl "\n"
#define ff first
#define int LL
#define ss second
#define v vector
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
// To store segment tree
int *st;

/*  A recursive function to get gcd of given
    range of array indexes. The following are parameters for
    this function.

    st    --> Pointer to segment tree
    si --> Index of current node in the segment tree. Initially
               0 is passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment
                 represented by current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
int findGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return st[si];
    int mid = ss + (se - ss) / 2;
    return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
                 findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}

// Finding The gcd of given Range
int findRangeGcd(int ss, int se, int arr[], int n)
{
    if (ss < 0 || se > n - 1 || ss > se)
    {
        cout << "Invalid Arguments"
             << "\n";
        cout << ss << ' ' << se << endl;
        return -1;
    }
    return findGcd(0, n - 1, ss, se, 0);
}

// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
int constructST(int arr[], int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si] = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                   constructST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}

/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
int *constructSegmentTree(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, height) - 1;
    st = new int[size];
    constructST(arr, 0, n - 1, 0);
    return st;
}

void solve()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    constructSegmentTree(arr, n);

    v<int> dp(n);
    int prevChanged = -1;
    for (int i = 0; i < n; i++)
    {
        int l = prevChanged;
        int r = i + 1;
        while (r - l > 1)
        {
            int m = (l + r) / 2;

            if (findRangeGcd(m, i, arr, n) >= i - m + 1)
                r = m;
            else
                l = m;
        }
        if (r != i + 1 and findRangeGcd(r, i, arr, n) == i - r + 1)
        {
            // cout << "changed" << i << endl;
            prevChanged = i;
            dp[i]++;
        }
        if (i > 0)
            dp[i] += dp[i - 1];
    }
    for (int i = 0; i < n; i++)
        cout << dp[i] << " ";
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //
int32_t main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //