#include <iostream>
using namespace std;

// row : optional
// col : mandatory

// void solve(int A[][], int row, int col)
// {
//     cout << "i am in solve";
// }
#define add(x) cout << "address of " << #x << " " << &x << endl;
#define print(x) cout << x << endl;

int main()
{

    // int A[10][10];

    // solve(A, 10, 10);
    int x = 1;
    int *A = &x;
    int **B = &A;

    // cout << "address of x"
    //      << " " << &x << endl;

    // cout << "address of A"
    //      << " " << &A << endl;

    // cout << "address of B"
    //      << " " << &B << endl;
    add(A);
    add(B);
    cout << "------\n";

    print(A);  // &x
    print(*A); // 1

    print(B);   // &A
    print(*B);  // &x
    print(**B); // 1

    // int ***C = &B;
}

// C -> B -> A -> x 