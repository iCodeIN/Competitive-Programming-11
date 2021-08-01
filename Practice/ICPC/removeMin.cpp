#include <bits/stdc++.h>
using namespace std;

void solve()
{
}

int main()
{
}

vector<int> pq;

int removeMin()
{
    // Write your code here
    if (pq.size() == 0)
    {
        return 0;
    }
    int ans = pq[0];
    pq[0] = pq[pq.size() - 1];
    pq[pq.size() - 1] = ans;
    pq.pop_back();
    // 5 0...4          pq.size() = 5
    // 4 0...3          pq.size() = 4
    int parentIndex = 0;
    int childIndex1 = (parentIndex * 2) + 1;
    int childIndex2 = (parentIndex * 2) + 2;

    // parent = 5
    // child1 = 3
    // child2 = 6

    while (childIndex1 < pq.size())
    {
        int minIndex = childIndex1;
        int minvalue = pq[childIndex1];

        if (childIndex2 < pq.size() and pq[childIndex2] < minvalue)
        {
            minvalue = pq[childIndex2];
            minIndex = childIndex2;
        }

        if (minvalue < pq[parentIndex])
        {
            swap(pq[minIndex], pq[parentIndex]);
            parentIndex = minIndex;
        }
        else
        {
            break;
        }

        // if (childIndex1 <= pq.size() - 1 && childIndex2 <= pq.size() - 1 && pq[parentIndex] > pq[childIndex1] && pq[parentIndex] > pq[childIndex2])
        // {
        //     int minvalue = min(pq[childIndex1], pq[childIndex2]);
        //     if (minvalue == pq[childIndex1])
        //     {
        //         minIndex = childIndex1;
        //         int temp = pq[childIndex1];
        //         pq[childIndex1] = pq[parentIndex];
        //         pq[parentIndex] = temp;
        //     }
        //     else
        //     {
        //         minIndex = childIndex2;
        //         int temp = pq[childIndex2];
        //         pq[childIndex2] = pq[parentIndex];
        //         pq[parentIndex] = temp;
        //     }
        // }

        // if (childIndex1 <= pq.size() - 1 && childIndex2 > pq.size() - 1 && pq[parentIndex] > pq[childIndex1])
        // {
        //     int temp = pq[childIndex1];
        //     pq[childIndex1] = pq[parentIndex];
        //     pq[parentIndex] = temp;
        //     minIndex = childIndex1;
        // }

        // // if (childIndex1 > pq.size() - 1 && childIndex2 < pq.size() - 1 && pq[parentIndex] > pq[childIndex2])
        // // {
        // //     int temp = pq[childIndex2];
        // //     pq[childIndex2] = pq[parentIndex];
        // //     pq[parentIndex] = temp;
        // //     minIndex = childIndex2;
        // // }

        // // if (childIndex1 > pq.size() - 1 && childIndex2 > pq.size() - 1)
        // // {
        // //     break;
        // // }

        // // if (pq[parentIndex] < pq[childIndex1] && childIndex2 > pq.size() - 1)
        // // {
        // //     break;
        // // }

        // // if (pq[parentIndex] < pq[childIndex2] && childIndex1 > pq.size() - 1)
        // // {
        // //     break;
        // // }

        // // if (pq[parentIndex] < pq[childIndex1] && pq[parentIndex] < pq[childIndex2])
        // // {
        // //     break;
        // // }

        // parentIndex = minIndex;
    }
    return ans;
}
