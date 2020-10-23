
#include <iostream>
using namespace std;

void heapify(double arr[], int n, int i, int &count)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {

        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, count);
    }
}

void build_heap(double arr[], int n, int &count)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, count);
}

int heap_sort(double arr[], int n)
{
    cout << "Comparisons of build_heap:\n";
    int count = 0;
    build_heap(arr, n, count);
    cout << "Comparisons after build_heap:\n";

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, count);
    }
    return count;
}
void get_frequencies(double arr[], int n)
{

    heap_sort(arr, n);
    int count = 0;
    double cur = arr[0];

    for (int i = 0; i <= n; i++)
    {
        if (cur == arr[i])
        {
            count++;
        }
        else
        {
            cout << arr[i - 1] << "\t\t" << count << endl;
            cur = arr[i];
            count = 1;
        }

        // cout<<arr[i]<<"\t\t";
    }
}

int main()
{

    double arr[15] = {4, 3, 2, 1, 5, 5, 4, 5, 2, 1, 2, 2, 2, 2, 2};
    get_frequencies(arr, 15);
    return 0;
}