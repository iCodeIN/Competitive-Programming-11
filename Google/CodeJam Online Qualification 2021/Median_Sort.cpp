#include <iostream>
#include <vector>
using namespace std;

void solve(int &n, int &q)
{
    vector<int> A(3);
    for (int i = 0; i < 3; i++)
        A[i] = i + 1;
    for (int i = 0; i < 3; i++)
        cout << A[i] << " ";
    cout << endl;
    int md;
    cin >> md;
    swap(A[md - 1], A[1]);
    for (int i = 4; i <= n; i++)
    {
        int l = 1;
        int r = A.size() - 1;
        int pos = -1;
        while (l <= r and pos == -1 and q > 0)
        {
            q--;
            int m = (l + r) >> 1;
            cout << A[m] << " " << A[m - 1] << " " << i << endl;
            cin >> md;

            if (md == i)
                pos = m;
            else if (md == A[m])
                l = m + 1;
            else
                r = m - 1;
        }
        if (q == 0)
            exit(0);
        if (pos == -1)
        {
            cout << A[0] << " " << A[1] << " " << i << endl;
            cin >> md;
            q--;
            if (md == A[0])
                pos = 0;
            else
                pos = A.size();
        }
        A.insert(A.begin() + pos, i);
    }
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;
    int status;
    cin >> status;
    if (status == 1)
        return;
    else
        exit(0);
}

int main()
{
    int t, n, q;
    cin >> t >> n >> q;

    while (t--)
        solve(n, q);
}