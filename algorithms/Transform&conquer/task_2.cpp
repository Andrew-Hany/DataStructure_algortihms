#include <iostream>
#include <vector>
#include <fstream>
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

    int count = 0;
    build_heap(arr, n, count);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, count);
    }
    return count;
}
double most_frequent(double arr[], int n)
{

    heap_sort(arr, n);
    int most = 0;
    int element;
    int count = 0;
    double cur = arr[0];

    for (int i = 0; i <= n; i++)
    {
        if (cur == arr[i])
        {
            count++;
            if (most < count)
            {
                most = count;
                element = arr[i];
            }
        }
        else
        {
            if (most < count)
            {
                most = count;
                element = arr[i];
            }

            cur = arr[i];
            count = 1;
        }
    }
    return element;
}

int main()
{

    vector<double> array;
    ifstream file;
    file.open("numbers.txt");
    if (!file.is_open())
    {
        cout << "this is no working" << endl;
        exit(1);
    }

    while (!file.eof())
    {
        double number;
        file >> number;
        array.push_back(number);
    }

    double array_2[array.size()];
    for (int i = 0; i < array.size(); i++)
        array_2[i] = array[i];
    cout << "most freq =" << most_frequent(array_2, array.size()) << endl;

    return 0;
}