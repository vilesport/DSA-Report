#include <bits/stdc++.h>
using namespace std;
#define N (long long)(1e6)

string s;
double a, b, c;
double arr[N + 5];

int main(int argc, char* argv[])
{
    s = argv[1];
    s = "./Testcase/input" + s + ".inp";
    mt19937 mt(time(nullptr));
    freopen(s.c_str(), "w", stdout);
    for(int i = 1; i <= N; i++)
    {
        a = mt();
        b = mt();
        c = mt();
        arr[i] = (a * b) / c;
    }
    if(s == "./Testcase/input1.inp")
        sort(arr + 1, arr + N + 1);
    if(s == "./Testcase/input2.inp")
        sort(arr + 1, arr + N + 1, greater<double>());
    for(int i = 1; i <= N; i++)
        cout << fixed << setprecision(2) << arr[i] << " ";
}