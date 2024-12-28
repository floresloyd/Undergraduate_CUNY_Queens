#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &A, int i) {
    int n = A.size();
    if (i < 0 || i >= n - 1) {
        cout << "Invalid index i" << endl;
        return;
    }

    int left = 0;
    int right = n - 1;
    int temp;

    while (left < right) {
        int leftSize = i - left + 1;
        int rightSize = right - i;

        if (leftSize == rightSize) {
            // Swap the elements pairwise
            for (int k = 0; k < leftSize; k++) {
                temp = A[left + k];
                A[left + k] = A[i + 1 + k];
                A[i + 1 + k] = temp;
            }
            break;
        } else if (leftSize < rightSize) {
            // Swap the first 2*leftSize elements
            for (int k = 0; k < leftSize; k++) {
                temp = A[left + k];
                A[left + k] = A[i + rightSize + 1 + k];
                A[i + rightSize + 1 + k] = temp;
            }
            right = i + rightSize;
        } else {
            // Swap the last rightSize elements
            for (int k = 0; k < rightSize; k++) {
                temp = A[i - rightSize + k + 1];
                A[i - rightSize + k + 1] = A[i + 1 + k];
                A[i + 1 + k] = temp;
            }
            left = i - rightSize + 1;
        }
    }
}

int main() {
    vector<int> A = {10, 2, 4, 8, 9, 3, 15, 6};
    int i = 2;

    cout << "Original Array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    swap(A, i);

    cout << "Swapped Array: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
