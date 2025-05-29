// #include "Vec.h"
// #include <cmath>

// int Vec3D ::getLenth()
// {
//     return std:: sqrt(x*x + y*y +z*z);
// }

#include <iostream>
#include <algorithm> // for sort
#include <string>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    sort(arr, arr + n); // sort from the start to the end of the array

    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";  // prints: 1 2 5 5 6 9


        cout<<"  "<<sizeof(arr)/sizeof(arr[0]);
}
