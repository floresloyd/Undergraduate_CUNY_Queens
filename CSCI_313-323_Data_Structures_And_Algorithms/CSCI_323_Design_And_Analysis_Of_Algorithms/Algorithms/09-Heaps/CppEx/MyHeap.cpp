#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class NoSuchElementException : public std::exception {
public:
    const char* what() const noexcept override {
        return "No such element exists in the heap!";
    }
};

void inline Swap(int& a, int& b) {
	if (&a == &b) return;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
} //end-Swap

//------------ Binary Heap operations ---------------------
// Helper functions
void pushUp(vector<int> &H){
    int index = H.size()-1;
    while (index > 0){
        int parent = (index-1)/2;
        if (H[parent] <= H[index]) break;

        Swap(H[index], H[parent]);
        index = parent;
    } // end-while
} // end-pushUp

void pushDown(vector<int> &H, int index, int N){
    while (true){
        int left = 2*index+1;
        int right = 2*index+2;
        int smallest = index;
        if (left < N && H[left] < H[smallest]) smallest = left;
        if (right < N && H[right] < H[smallest]) smallest = right;
        if (smallest == index) break;

        Swap(H[index], H[smallest]);
        index = smallest;
    } // end-while
} // end-pushDown

void print(vector<int> &H){
    if (H.size() == 0) cout << "The heap is empty" << endl;
    cout << "The heap elements level by level:" << endl;

    int index = 0;
    int numElementsAtThisLevel = 1;
    int level = 0;
    while (index < H.size()){
        printf("Level [%2d]: [", ++level);
        int lastIndex = std::min(index + numElementsAtThisLevel, (int)H.size());
        for (; index < lastIndex; index++){
            printf("%d, ", H[index]);
        } // end-for
        printf("\b\b]\n");
        numElementsAtThisLevel *= 2;
    } // end-while
    printf("----------------------------------------\n");
} // end-print

// top: O(1)
int top(vector<int> &H){
    if (H.size() < 0) throw NoSuchElementException();
    return H[0];
} // end-top

int pop(vector<int> &H){    
    if (H.size() < 0) throw NoSuchElementException();
    int ret = H[0];
    H[0] = H.back();
    H.pop_back();

    pushDown(H, 0, H.size());

    return ret;
} // end-pop

void push(vector<int> &H, int num){
    H.push_back(num);
    pushUp(H);
} // end-push

void makeHeap(vector<int> &H){
    for (int i=H.size()/2; i>=0; --i){
        pushDown(H, i, H.size());
    } // end-for
} // end-makeHeap

/// Create a min-heap & sort the numbers in descending order
void heapSort(vector<int> &H){
    if (H.size() <= 1) return;

    makeHeap(H);    
    for (int index=H.size()-1; index > 0; --index){
        Swap(H[0], H[index]);
        pushDown(H, 0, index);
    } // end-for    
} // end-heapSort

///------------------ Tests -------------------
void Test1(){
    vector<int> H;

    push(H, 2);
    push(H, 4);
    push(H, 3);
    push(H, 7);
    push(H, 5);
    push(H, 8);
    push(H, 9);
    push(H, 11);
    push(H, 9);
    push(H, 6);
    push(H, 10);

    print(H);

	printf("The minimum element is: %d\n", top(H));
	printf("Deleting the minimum element %d\n", pop(H));
	printf("Now, the minimum element is: %d\n", top(H));

    print(H);
} // end-Test1

void Test2(){
    vector<int> H;

	push(H, 2);
	push(H, 4);
	push(H, 3);
	push(H, 7);
	push(H, 5);
	push(H, 8);
	push(H, 9);
	push(H, 11);
	push(H, 9);
	push(H, 6);

	print(H);

	printf("The minimum element is: %d\n", top(H));

	printf("Inserting 1 into the heap...\n");
	push(H, 1);

	printf("Now, the minimum element is: %d\n", top(H));

	print(H);
} // end-Test2

/// Test makeHeap
void Test3(){
	vector<int> H = { 20, 6, 3, 10, 16, 2, 10, 14, 8, 7 };

    cout << "Before makeHeap: " << endl;
    print(H);

    makeHeap(H);

    cout << "After makeHeap" << endl;
    print(H);
} // end-Test3

/// Test HeapSort
void Test4(){
	vector<int> nums = { 20, 6, 3, 10, 16, 2, 10, 14, 8, 7 };

    cout << "Initial array elements: ";
    for (auto num: nums) cout << num << ", ";
    cout << endl;

    heapSort(nums);

    cout << "Array elements sorted in decreasing order: ";
    for (auto num: nums) cout << num << ", ";
    cout << endl;
} // end-Test4

int main(){
//    Test1();
//    Test2();
//    Test3();
    Test4();

    return 0;
}