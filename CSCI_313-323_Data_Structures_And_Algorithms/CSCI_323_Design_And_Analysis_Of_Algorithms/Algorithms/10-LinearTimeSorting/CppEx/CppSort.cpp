#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>

using namespace std;

///===================== SORT TEST ==================================
/// Sort Test
///
struct Foo {
    string name;
    int age;

    Foo(string _name, int _age) { name = _name; age = _age; }
};

void Print(vector<int> &v) {
    for (auto a : v) {
        printf("%d, ", a);
    } //end-for
    printf("\n");
    printf("------------------------------------------------\n");
} //end-Print

void Print(vector<Foo>& v) {
    for (auto a : v) {
        printf("<%8s, %d>\n", a.name.c_str(), a.age);
    } //end-for
    printf("------------------------------------------------\n");
} //end-Print

///================================================================
void Test1() {
    // vector is a variable size contiguous array of elements
    vector<int> nums = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    /// Sort in ascending order
    /// For details on how C++ sort function works, look into 
    /// https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
    /// According to this page, sort utility is a hybrid sorting algorithm
    /// For very small data, it uses InsertionSort
    /// For moderate-size data, it uses HeapSort
    /// For large-sized data, it uses QuickSort with MedianOfThree heuristic
    ///
    std::sort(nums.begin(), nums.end());
    std::sort(nums.begin(), nums.end(), std::less<int>());   // Same as above

    Print(nums);
}

void Test2(){
    vector<int> nums = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    std::sort(nums.begin(), nums.end(), std::greater<int>());

    Print(nums);
} // end-Test2

void Test3(){
    // We can also supply our own comparison function, which has the following prototype:
    // bool cmp(const Type1 &a, const Type2 &b);
    vector<int> nums = { 3, 2, 2, 5, 6, 8, 7, 5, 8, 7, 1, 2, 1, 4, 3 };

    // Sort in ascending order
    auto cmp1 = [](int first, int second) { return first < second; };
    std::sort(nums.begin(), nums.end(), cmp1);

    Print(nums);


    // We can also supply our own comparison function, which has the following prototype:
    // bool cmp(const Type1 &a, const Type2 &b);
    // Sort in descending order
    auto cmp2 = [](int first, int second) { return first > second; };
    std::sort(nums.begin(), nums.end(), cmp2);

    Print(nums);
} // end-Test3

void Test4(){
    /// Sort an array of objects
    vector<Foo> arr = { Foo("Ceren", 20), Foo("Veli", 20), Foo("Ali", 20), Foo("Ayse", 18),
                      Foo("Cem", 20), Foo("Fatma", 22), Foo("Zerrin", 18),
                      Foo("Oya", 22)};

    // Sort in ascending order wrt name
    auto cmp1 = [](Foo& first, Foo& second) { return first.name < second.name; };
    std::sort(arr.begin(), arr.end(), cmp1);
    Print(arr);

    // Now, sort wrt to age
    auto cmp2 = [](Foo& first, Foo& second) { return first.age < second.age; };
    std::sort(arr.begin(), arr.end(), cmp2);
    Print(arr);

    // Now, sort wrt to age. If two people have the same age, sort wrt. their name
    auto cmp3 = [](Foo& first, Foo& second) {
        if (first.age == second.age) return first.name < second.name;
        return first.age < second.age;
    };
    std::sort(arr.begin(), arr.end(), cmp3);
    Print(arr);
} // end-Test4

void Test5(){
    // Sort indices
    vector<int> nums = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };
    int n = nums.size();
    vector<int> I(n);
    for (int i = 0; i < n; i++) I[i] = i;

    std::sort(I.begin(), I.end(), 
        [&](int first, int second) {
            return nums[first] < nums[second];
        });

    Print(nums);
    Print(I);
} // end-Test5

int main(){
//    Test1();
//    Test2();
//    Test3();
//    Test4();
    Test5();
} // end-main
