#include <iostream>
using namespace std;

int main()
{
    int i = 3;

    (*(&i))++;
    cout << *(&i) << endl;
    cout << &i << endl;

    *(&i) = 100;
    cout << *(&i) << endl;
    cout << &i << endl;
}