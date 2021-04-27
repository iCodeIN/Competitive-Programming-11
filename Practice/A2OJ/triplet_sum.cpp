#include <iostream>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

int check(int arr[], int start, int end)
{

    if (start > end)
    {
        return 0;
    }

    if (start == end)
    {
        return start;
    }

    int mid = (start + end) / 2;

    if (arr[start] <= arr[mid] && arr[mid] <= arr[end])
    {
        return start;
    }
    if (arr[mid] < arr[end])
    {
        return check(arr, start, mid - 1);
    }

    return check(arr, mid + 1, end);
}

int main()
{

    int arr[] = {7, 9, 11, 12, 5};
    int result = check(arr, 0, 5);
    cout << result << endl;
}
