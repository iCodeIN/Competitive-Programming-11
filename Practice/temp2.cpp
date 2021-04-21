#include <iostream>
#include <climits>
using namespace std;

int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = -1;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int firstVertex, secondVertex, weight;
        cin >> firstVertex >> secondVertex >> weight;
        edges[firstVertex][secondVertex] = weight;
        edges[secondVertex][firstVertex] = weight;
    }

    int *parent = new int[n];

    bool *visited = new bool[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    weight[0] = 0;
    for (int count = 0; count < n; count++)
    {
        int temp, minWeight = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && minWeight > weight[i])
            {
                minWeight = weight[i];
                temp = i;
            }
        }
        visited[temp] = true;
        for (int i = 0; i < n; i++)
        {
            if (edges[temp][i] != -1)
            {
                if (weight[i] >= edges[temp][i] && !visited[i])
                {
                    weight[i] = edges[temp][i];
                    parent[i] = temp;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
            continue;
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " ";
        }
        else
        {
            cout << i << " " << parent[i] << " ";
        }
        cout << weight[i] << endl;
    }
}