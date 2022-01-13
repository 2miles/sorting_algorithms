#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 8;
const int WRAP = 10;
const int R_MAX = 100;


/// Prototypes
///////////////////////////////////////////////////

// with random int [0,100)
void populate_array(int arr[]);
// optional second arg determines the wrap width
void print_array(int arr[], int width=10);
// given an array and two indices, swap the data
void swap_data(int arr[], int i, int j);

void selection_sort (int arr[]);

void quick_sort(int arr[]);
void quick_sort_rec(int arr[], int low, int high);
int quick_sort_partition(int arr[], int low, int high);



/// Main
///////////////////////////////////////////////////
int main() {
    srand(std::time(nullptr));

    int data[SIZE];

    populate_array(data);
    cout << '\n' << "data before sort: ";
    print_array(data, WRAP);
    //selection_sort(data);
    quick_sort(data);
    cout << '\n' << "data AFTER sort: ";
    print_array(data, WRAP);
    return 0;
}


/// Definitions
///////////////////////////////////////////////////
void populate_array(int arr[]) {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = rand() % R_MAX;
    }
}
void print_array(int arr[], int wid) {
    for (int i = 0; i < SIZE; ++i) {
        if ((i % wid) == 0) {
            cout << "\n";
        }
        cout << setw(2) << arr[i] << ' ';
    }
    cout << '\n';
}
void swap_data(int arr[], int i, int j) {
    int temp;
    if ( i != j) {
        temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}
void selection_sort( int arr[]) {
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (arr[j] <= arr[i]) {
                swap_data(arr, i, j);
            }
        }
    }
}
void quick_sort(int arr[]) {
    quick_sort_rec(arr, 0, SIZE);
}
void quick_sort_rec( int arr[], int low, int high) {
    int mid;
    if (high - low > 1 ) {
        mid = quick_sort_partition(arr, low, high);
        quick_sort_rec(arr, low, mid);
        quick_sort_rec(arr, mid + 1, high);
    }
}
// Arbitrarily pick leftmost element as pivot, then
// move all the smaller elements to the left of pivot
// and move pivot into correct position
// RETURN index of pivot
int quick_sort_partition(int arr[], int low, int high) {
    int pivot = arr[high - 1];
    int mid = low;
    for (int i = low; i < high - 1; ++i) {
        if (arr[i] < pivot) {
            swap_data(arr, i, mid);
            ++mid;
        }
    }
    swap_data(arr, mid, high - 1);
    return mid;
}


