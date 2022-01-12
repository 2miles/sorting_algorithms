#include <iostream>
#include <ctime
#include <iomanip>

using namespace std;

const int SIZE = 20;
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

/// Main
///////////////////////////////////////////////////
int main() {
    srand(std::time(nullptr));

    int data[SIZE];

    populate_array(data);
    cout << "data before sort: ";
    print_array(data, WRAP);
    cout << '\n';
    selection_sort(data);
    cout << '\n';
    cout << "data AFTER sort: ";
    print_array(data, WRAP);
    cout << '\n';
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
}
void swap_data(int arr[], int i, int j) {
    int temp;
    temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}


// T(n) == n^2, best and worst cases
void selection_sort ( int arr[]) {
    for (int i = 0; i < SIZE - 1; ++i) {
        for (int j = i + 1; j < SIZE; ++j) {
            if (arr[j] <= arr[i]) {
                swap_data(arr, i, j);
            }
        }
    }
}

