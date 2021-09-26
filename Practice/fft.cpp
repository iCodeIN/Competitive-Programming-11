#include <iostream>
#include <math.h>
#include <complex>
#include <vector>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert)
{
    int n = a.size();
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++)
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++)
    {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert)
        {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

string multiplyFFT(string &a, string &b)
{
    int n1 = a.size();
    int n2 = b.size();
    int n = 1;

    while (n < n1 + n2)
        n <<= 1;
    vector<cd> A(n);
    vector<cd> B(n);

    for (int i = 0, j = n1 - 1, k = n2 - 1; i < n; i++, j--, k--)
    {
        double a_ = (j >= 0) ? a[j] - '0' : 0;
        double b_ = (k >= 0) ? b[k] - '0' : 0;

        A[i] = {a_, 0.0};
        B[i] = {b_, 0.0};
    }

    fft(A, false);
    fft(B, false);

    vector<cd> C(n);
    for (int i = 0; i < n; i++)
        C[i] = A[i] * B[i];

    fft(C, true);

    vector<int> Ans(n);
    for (int i = 0; i < n - 1; i++)
        Ans[n - i - 1] = round(C[i].real());

    for (int i = n - 1; i > 0; i--)
    {
        Ans[i - 1] += Ans[i] / 10;
        Ans[i] %= 10;
    }

    string ans = "";
    ans.reserve(n + 1);
    int i = 0;

    while (i < n and Ans[i] == 0)
        i++;
    while (i < n)
        ans += to_string(Ans[i++]);

    return ans;
}

int main()
{

    string a, b;

    for (int i = 1; i <= 10000; i++)
    {
        a += ('1');
        b += ('9');
    }

    multiplyFFT(a, b);

    cout << a << endl;
}

