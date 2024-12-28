#include <iostream>
using namespace std;


int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int arr_match[] = {1, 2, 2, 3, 4, 5};

    int arr_len = sizeof(arr) / sizeof(arr[0]);
    cout << arr_len;
}