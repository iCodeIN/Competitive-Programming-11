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

struct Node
{
    int x;
    Node *next = NULL;

    Node(int x)
    {
        this->x = x;
    }
};

struct LinkedList
{
    Node *head = NULL;
    Node *tail = NULL;

    void insert(int x)
    {
        if (head == NULL)
        {
            head = tail = new Node(x);
        }
        else
        {
            tail->next = new Node(x);
            tail = tail->next;
        }
    }

    void insert(LinkedList L)
    {
        if (head == NULL)
        {
            head = L.head;
            tail = L.tail;
        }
        else
        {
            tail->next = L.head;
            tail = L.tail;
        }
    }
};

void solve()
{
    int n;
    cin >> n;

    map<int, LinkedList> mp;
    int i = 0;
    while (n--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int x;
            cin >> x;
            if (mp.count(x) == 0)
            {
                LinkedList l;
                mp[x] = l;
            }
            mp[x].insert(i++);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            // replace a by b
            if (a == b or mp.count(a) == 0)
                continue;
            if (mp.count(b) == 0)
            {
                mp[b] = mp[a];
            }
            else
            {
                mp[b].insert(mp[a]);
            }
            mp.erase(a);
        }
    }
    n = i;
    vector<int> A(n);

    for (auto itr : mp)
    {
        int v = itr.first;
        auto ptr = itr.second.head;
        while (ptr != NULL)
        {
            A[ptr->x] = v;
            ptr = ptr->next;
        }
    }
    for (int x : A)
        cout << x << " ";
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
// // //  // // //  // // //  // // // // // //  // // // // // //  // // //]