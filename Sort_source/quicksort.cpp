#include <bits/stdc++.h>
using namespace std;
#define M (long long)(1e6)
 
void quickSort(double arr[], int l, int r) 
{
    double p = arr[(l + r) / 2];
    int i = l, j = r;
    while (i < j) 
    {
        while (arr[i] < p) i++;
        while (arr[j] > p) j--;
        if (i <= j) 
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (i < r)
        quickSort(arr, i, r);
    if (l < j)
        quickSort(arr, l, j);
}
 
string file_name;
double arr[M + 5], c;

int main(int argc, char* argv[])
{
    file_name = argv[1];
    freopen(file_name.c_str(), "r", stdin);
    int i = 0;
    while(cin >> c)
    {
        arr[i] = c;
        i++;
    }
    int n = sizeof(arr) / sizeof(arr[0]); 
    auto start = chrono::steady_clock::now();
    quickSort(arr, 0, n - 1);
    auto end = chrono::steady_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(end - start);
    string s = file_name;
    while(s[0] != 'i')
        s.erase(0, 1);
    cout << s << ": " << dur.count() << "|\n";
    exit(0);
}