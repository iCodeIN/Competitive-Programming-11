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
class Node
{
public:
    int value = -1;
    Node *right = NULL;
    Node *left = NULL;

    Node(int val = -1)
    {
        this->value = val;
    }
};

class LinkedList
{
public:
    Node *head = NULL;
    Node *prev = NULL;
    int size = 0;

    void insertLeft(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
        {
            head = prev = temp;
        }
        else
        {
            temp->right = prev;
            temp->left = prev->left;
            if (temp->left)
                temp->left->right = temp;
            prev->left = temp;
            if (temp->left == NULL)
                head = temp;
        }
        size++;
        prev = temp;
    }

    void insertRight(int val)
    {
        Node *temp = new Node(val);

        temp->left = prev;
        temp->right = prev->right;
        if (temp->right)
            temp->right->left = temp;
        prev->right = temp;

        size++;
        prev = temp;
    }
};

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;
    LinkedList l;

    l.insertLeft(0);

    for (int i = 1; i <= n; i++)
        if (s[i - 1] == 'L')
            l.insertLeft(i);
        else
            l.insertRight(i);

    Node *ptr = l.head;
    while (ptr != NULL)
    {
        cout << ptr->value << " ";
        ptr = ptr->right;
    }
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