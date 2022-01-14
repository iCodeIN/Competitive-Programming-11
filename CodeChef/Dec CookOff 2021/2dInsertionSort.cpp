#include <bits/stdc++.h>
using namespace std;

class Layer
{
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    vector<int> elements;
    int **A;
    int n;
    void convertTo1d()
    {
        if (startRow == endRow)
        {
            for (int j = startCol; j <= endCol; j++)
                elements.push_back(A[startRow][j]);
        }
        else if (startCol == endCol)
        {
            for (int i = startRow; i <= endRow; i++)
                elements.push_back(A[i][startCol]);
        }
        else
        {
            // startCol
            for (int i = startRow; i <= endRow; i++)
                elements.push_back(A[i][startCol]);
            // endRow
            for (int j = startCol + 1; j <= endCol - 1; j++)
                elements.push_back(A[endRow][j]);
            // endCol
            for (int i = endRow; i >= startRow; i--)
                elements.push_back(A[i][endCol]);
            // startRow
            for (int j = endCol - 1; j >= startCol + 1; j--)
                elements.push_back(A[startRow][j]);
        }
    }

    void updateIn2d()
    {
        int idx = 0;
        if (startRow == endRow)
        {
            for (int j = startCol; j <= endCol; j++)
                A[startRow][j] = elements[idx++];
        }
        else if (startCol == endCol)
        {
            for (int i = startRow; i <= endRow; i++)
                A[i][startCol] = elements[idx++];
        }
        else
        {
            // startCol
            for (int i = startRow; i <= endRow; i++)
                A[i][startCol] = elements[idx++];
            // endRow
            for (int j = startCol + 1; j <= endCol - 1; j++)
                A[endRow][j] = elements[idx++];
            // endCol
            for (int i = endRow; i >= startRow; i--)
                A[i][endCol] = elements[idx++];
            // startRow
            for (int j = endCol - 1; j >= startCol + 1; j--)
                A[startRow][j] = elements[idx++];
        }
    }

public:
    void print2d()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << A[i][j] << " ";
        cout << endl;
    }
    Layer(int **A, int n, int startRow, int endRow, int startCol, int endCol)
    {
        this->A = A;
        this->n = n;
        this->startRow = startRow;
        this->endRow = endRow;
        this->startCol = startCol;
        this->endCol = endCol;
        convertTo1d();
    }

    bool insertionSort(int i)
    {

        int m = elements.size();
        if (i >= m / 2)
            return true;
        int j = i - 1;
        int current = elements[i];
        while (j >= 0 and elements[j] > current)
        {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = current;
        j = i + (m / 2) - 1;
        if (j + 1 < m)
        {
            current = elements[j + 1];
            while (j >= m / 2 and elements[j] > current)
            {
                elements[j + 1] = elements[j];
                j--;
            }
            elements[j + 1] = current;
        }
        updateIn2d();
        return false;
    }

    bool mergingSort(int i)
    {

        int m = elements.size();
        if (i >= m)
            return true;
        int j = i - 1;
        int current = elements[i];
        while (j >= 0 and elements[j] > current)
        {
            elements[j + 1] = elements[j];
            j--;
        }
        elements[j + 1] = current;
        updateIn2d();
        return false;
    }
};

int main()
{
    int n;
    cin >> n;

    int **A = new int *[n];
    for (int i = 0; i < n; i++)
        A[i] = new int[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = n - 1;

    vector<pair<int, Layer>> Layers;
    while (startRow <= endRow and startCol <= endCol)
    {
        Layer l(A, n, startRow, endRow, startCol, endCol);
        Layers.push_back({1, l});
        startRow++;
        startCol++;
        endRow--;
        endCol--;
    }

    int m = Layers.size();

    while (true)
    {
        bool completed = true;

        for (auto &layer : Layers)
        {
            bool current = layer.second.insertionSort(layer.first);
            completed = current and completed;
            if (!current)
                layer.first++;
        }
        if (completed)
            break;
        Layers[0].second.print2d();
    }

    while (true)
    {
        bool completed = true;

        for (auto &layer : Layers)
        {
            bool current = layer.second.mergingSort(layer.first);
            completed = current and completed;
            if (!current)
                layer.first++;
        }
        if (completed)
            break;
        Layers[0].second.print2d();
    }
}
