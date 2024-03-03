#include <bits/stdc++.h>
using namespace std;
#define M (long long)(1e6)

void heapify(double arr[], int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(double arr[], int N)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
// A utility function to print array of size n
void printArray(double arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver's code
string file_name;
double arr[M + 5], c;

int main(int argc, char* argv[])
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    file_name = argv[1];
    freopen(file_name.c_str(), "r", stdin);
    int i = 0;
    while(cin >> c)
    {
        arr[i] = c;
        i++;
    }
    int N = sizeof(arr) / sizeof(arr[0]); // Number of elements read

    auto start = chrono::steady_clock::now();
    heapSort(arr, N);
    auto end = chrono::steady_clock::now();
    auto dur = chrono::duration_cast<chrono::milliseconds>(end - start);
    string s = file_name;
    while(s[0] != 'i')
        s.erase(0, 1);
    cout << s << ": " << dur.count() << "|\n";
    exit(0);
}
