
//------------------------------------------------------------------------------
// #include <iostream>
// #include <vector>
#include <bits/stdc++.h>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include <map>
// #include <set>
// #include <unordered_set>
//------------------------------------------------------------------------------
using namespace std;
//------------------------------------------------------------------------------
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define v(Type) vector<Type>
#define w(T)  \
    int T;    \
    cin >> T; \
    while (T--)
#define int long long int
#define mod 1000000007ll
#define endl "\n"
//------------------------------------------------------------------------------
// Any fucntion can be called using Math.function_name();
//------------------------------------------------------------------------------
class Math
{
public:
    //Returns gcd of two numbers
    int gcd(int a, int b)
    {
        return (a % b == 0) ? b : gcd(b, a % b);
    }

    //Returns lcm of two numbers
    int lcm(int a, int b)
    {
        return a * (b / gcd(a, b));
    }

    // Returns flag array isPrime
    // isPrime[i] = true (if i is Prime)
    // isPrime[i] = false (if i is not Prime)
    vector<bool> *seiveOfEratosthenes(const int N)
    {
        vector<bool> *isPrime = new vector<bool>(N + 1, true);
        (*isPrime)[0] = (*isPrime)[1] = false;
        for (int i = 2; i * i <= N; ++i)
            if ((*isPrime)[i])
                for (int j = i * i; j <= N; j += i)
                    (*isPrime)[j] = false;

        return isPrime;
    }

    //Returns (x ^ n)
    int pow(const int &x, int n)
    {
        if (n == 0)
            return 1;
        int h = pow(x, n / 2);
        return (n & 1) ? h * h * x : h * h;
    }

    //Returns (x ^ n) % M
    int pow(const int &x, int n, const int &M)
    {
        if (n == 0)
            return 1;
        int h = pow(x, n / 2) % M;
        return (n & 1) ? (h * h * x) % M : (h * h) % M;
    }

    //Returns all Primes <= N
    vector<int> *primesUptoN(const int N)
    {
        vector<bool> *isPrime = seiveOfEratosthenes(N);
        vector<int> *Primes = new vector<int>;
        if (2 <= N)
            (*Primes).push_back(2);
        for (int i = 3; i <= N; i += 2)
            if ((*isPrime)[i])
                (*Primes).push_back(i);
        return Primes;
    }

} Math;
//------------------------------------------------------------------------------
int calcGcdRangeRec(int *st, int segL, int segR, int L, int R, int currNode)
{
    if (L <= segL && R >= segR)
        return st[currNode];
    if (segR < L || segL > R)
        return 0;
    int mid = (segL + (segR - segL) / 2);
    int GcdL = calcGcdRangeRec(st, segL, mid, L, R, 2 * currNode + 1);
    int GcdR = calcGcdRangeRec(st, mid + 1, segR, L, R, 2 * currNode + 2);
    return Math.gcd(GcdL, GcdR);
}
void updateArrayValueRec(int *st, int L, int R, int index, int diff, int currNode)
{
    if (index < L || index > R)
        return;
    st[currNode] = st[currNode] + diff;
    if (R != L)
    {
        int mid = (L + (R - L) / 2);
        updateArrayValueRec(st, L, mid, index, diff, 2 * currNode + 1);
        updateArrayValueRec(st, mid + 1, R, index, diff, 2 * currNode + 2);
    }
}
void updateArrayValue(int arr[], int *st, int n, int index, int newVal)
{
    if (index < 0 || index > n - 1)
        cout << "Invalid Input";
    else
    {
        int diff = newVal - arr[index];
        arr[index] = newVal;
        updateArrayValueRec(st, 0, n - 1, index, diff, 0);
    }
}
int calcGcdRange(int *st, int n, int L, int R)
{
    if (L < 0 || R > n - 1 || L > R)
    {
        cout << "Invalid Input";
        return -1;
    }
    return calcGcdRangeRec(st, 0, n - 1, L, R, 0);
}
int constructGcdST(int arr[], int L, int R, int *st, int currNode)
{
    if (L == R)
    {
        st[currNode] = arr[L];
        return arr[L];
    }
    int mid = (L + (R - L) / 2);
    int GcdL = constructGcdST(arr, L, mid, st, currNode * 2 + 1);
    int GcdR = constructGcdST(arr, mid + 1, R, st, currNode * 2 + 2);
    st[currNode] = Math.gcd(GcdL, GcdR);
    return st[currNode];
}

void solve()
{
    int n, q;
    cin >> n >> q;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int v = (int)(ceil)(log2(n));

    int size = 2 * Math.pow(2, v) - 1;
    int *st = new int[size];
    constructGcdST(arr, 0, n - 1, st, 0);

    while (q--)
    {
        int i, x;
        cin >> i >> x;
        i--;

        updateArrayValue(arr, st, n, i,(x * arr[i]) - arr[i]);

        cout << calcGcdRange(st, n, 0, n - 1) << endl;
    }
}

//------------------------------------------------------------------------------
int32_t main()
{
    FastIO;

    // w(T)
    solve();

    return 0;
}
//------------------------------------------------------------------------------
