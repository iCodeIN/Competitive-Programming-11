#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct Node
{
    int a, b, c;
    Node() {}
    Node(int a, int b, int c)
    {
        this->a = min(a, min(b, c));
        this->c = max(a, max(b, c));
        this->b = a ^ b ^ c ^ this->a ^ this->c;
    }

    bool operator<(const Node &t) const
    {
        if (this->a != t.a)
            return this->a < t.a;
        if (this->b != t.b)
            return this->b < t.b;
        return this->c < t.c;
    }
};

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

    Node temp(A[0], A[1], A[2]);
    map<Node, int> myMap;
    myMap[temp] = md;

    for (int i = 4; i <= n; i++)
    {
        int l = 1;
        int r = A.size() - 1;
        int pos = -1;
        while (l <= r and pos == -1)
        {
            int m = (l + r) >> 1;
            Node temp(A[m], A[m - 1], i);

            if (myMap.count(temp) == 0)
            {
                cout << A[m] << " " << A[m - 1] << " " << i << endl;
                cin >> md;
                myMap[temp] = md;
            }
            else
                md = myMap[temp];

            if (md == i)
                pos = m;
            else if (md == A[m])
                l = m + 1;
            else
                r = m - 1;
        }

        if (pos == -1)
        {
            Node temp1(A[1], A[0], i);
            Node temp2(A[A.size() - 1], A[A.size() - 2], i);

            if (myMap.count(temp1) > 0)
            {
                if (myMap[temp1] == A[0])
                    pos = 0;
                else
                    pos = A.size();
            }
            else if (myMap.count(temp2) > 0)
            {
                if (myMap[temp2] == A[A.size() - 1])
                    pos = A.size();
                else
                    pos = 0;
            }
            else
            {
                cout << A[0] << " " << A[1] << " " << i << endl;
                cin >> md;
                myMap[temp1] = md;
                if (md == A[0])
                    pos = 0;
                else
                    pos = A.size();
            }
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