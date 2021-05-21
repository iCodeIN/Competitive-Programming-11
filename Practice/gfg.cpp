#include <iostream>
using namespace std;
void swap(char *&x, char *&y)
{
    char *t = x;
    x = y;
    y = t;
}
// char *x = "123";
int main()
{
    char *x = new char[100];
    char *y = new char[100];

    string temp1 = "geeksquiz";
    string temp2 = "geeksforgeeks";

    for (int i = 0; i < temp1.length(); i++)
        x[i] = temp1[i];

    x[temp1.length()] = '\0';

    for (int i = 0; i < temp2.length(); i++)
        y[i] = temp2[i];
    y[temp2.length()] = '\0';

    cout << "Intially : ";
    cout << x << " " << y << endl;
    char *t;

    swap(x, y);
    cout << "Swap fun : ";
    cout << x << " " << y << endl;
    t = x;
    x = y;
    y = t;
    cout << "Main fun : ";
    cout << " " << x << " " << y << endl;
    return 0;
}