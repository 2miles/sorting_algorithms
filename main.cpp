#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

const int SIZE = 20;
const int WRAP = 10;
const int R_MAX = 100;


/// Prototypes
///////////////////////////////////////////////////
//with random int [0,100)
void populate_array(int arr[]);
//optional second arg determines the wrap width
void print_array(int arr[], int width=10);


/// Main
///////////////////////////////////////////////////
int main() {
    srand(std::time(nullptr));

    int data[SIZE];

    populate_array(data);
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
}
