#include <bits/stdc++.h>
using namespace std;

struct BinaryTreeNode
{

    BinaryTreeNode *left;
    int data;
    BinaryTreeNode *right;

    BinaryTreeNode(int val)
    {
        data = val;
        left = right = NULL;
    }
};

struct BinaryTree
{

    BinaryTreeNode *root;

    BinaryTree()
    {
        root = NULL;
    }

    BinaryTree(int val)
    {
        root = new BinaryTreeNode(val);
    }

    void preOrder()
    {
        preOrder(root);
        cout << endl;
    }

    void inOrder()
    {
        inOrder(root);
        cout << endl;
    }

    void postOrder()
    {
        postOrder(root);
        cout << endl;
    }

private:
    void preOrder(BinaryTreeNode *root)
    {

        if (root == NULL)
            return;

        cout << root->data << ' ';
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(BinaryTreeNode *root)
    {
        if (root == NULL)
            return;

        inOrder(root->left);
        cout << root->data << ' ';
        inOrder(root->right);
    }

    void postOrder(BinaryTreeNode *root)
    {
        if (root == NULL)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
    }
};

struct data
{
    int t;
    int d;
    int idx;
    int ans;
};

bool comp1(data a, data b)
{

    if (a.d != b.d)
    {
        return a.d < b.d;
    }

    if (a.t != b.t)
    {
        return a.t < b.t;
    }

    return a.idx < b.idx;
}

bool comp2(data a, data b)
{
    return a.idx < b.idx;
}

void insert(vector<data> &A, int &Time, int &i, int &prev, int x)
{
    A[i].ans = A[i].t;
    Time = A[i].t + 1;
    i++;
    prev = x;
}

vector<int> getTimes(int numCustomers, vector<int> arrTime, vector<int> direction)
{

    int &n = numCustomers;
    vector<data> A(n);

    for (int i = 0; i < n; i++)
    {
        A[i].idx = i;
        A[i].d = direction[i];
        A[i].t = arrTime[i];
    }

    sort(A.begin(), A.end(), comp1);

    int i = 0;
    int j = 0;
    while (j < n and A[j].d == 0)
    {
        j++;
    }
    int mid = j;
    // using two pointer
    // i -> first 0
    // j -> first 1

    int prev = -1;
    int Time = 0;
    while (i < j and j < n)
    {

        A[i].t = max(A[i].t, Time);
        A[j].t = max(A[j].t, Time);

        if (A[i].t < A[j].t)
            insert(A, Time, i, prev, 0);

        else if (A[j].t < A[i].t)
            insert(A, Time, j, prev, 1);
        else
        {
            if (prev == -1 or prev == 1)
                insert(A, Time, j, prev, 1);
            else
                insert(A, Time, i, prev, 0);
        }
    }

    while (i < mid)
    {
        A[i].t = max(A[i].t, Time);
        insert(A, Time, i, prev, 0);
    }

    while (j < n)
    {
        A[j].t = max(A[j].t, Time);
        insert(A, Time, j, prev, 1);
    }
    sort(A.begin(), A.end(), comp2);

    vector<int> Ans(n);

    for (int i = 0; i < n; i++)
        Ans[i] = A[i].ans;

    return Ans;
}

int main()
{

    int n;
    cin >> n;

    vector<int> A(n), B(n);

    for (int &x : A)
        cin >> x;

    for (int &x : B)
        cin >> x;

    A = getTimes(n, A, B);

    for (int x : A)
        cout << x << " ";
}
