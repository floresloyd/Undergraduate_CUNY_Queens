#include <iostream>
#include <unordered_map>        // HASH MAP
#include <algorithm>            // SORT
using namespace std;

bool On (int arr[], int len);
bool On2 (int arr[], int len);
bool nlogn (int arr[], int len);

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int arr_match[] = {1, 2, -2, 3, 4, 5};

    int arr_len = sizeof(arr) / sizeof(arr[0]);
    int arr_match_len = sizeof(arr_match) / sizeof(arr_match[0]);

    cout << nlogn(arr_match, arr_match_len);
}

bool On2(int arr[], int len){
    for(int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++){
            if (abs(arr[i]) == abs(arr[j])){
                return true;
            } // end if
        } // end inner loop
    } // end outer loop
    return false;
}

bool On(int arr[], int len){
    unordered_map<int, int> seen_values;

    for(int i = 0; i < len; i++){;
        int current_num = arr[i];
        // CHECK IF NUMBER ALREADY EXISTS IN HASHMAP, IF IT DOES WE HAVE A MATCH
        if (seen_values.count(abs(current_num)) > 0){
            return true;
        }
        // If it does not exist add it to seen_values
        else{
            seen_values[current_num] = 1;
        }
    } // end for
    return false;
}

bool nlogn(int arr[], int len){
    sort(arr, arr + len); // SORT nLogn

    int left = 0;           // left pointer (Start of arr)
    int right = len - 1;    // right pointer (end of arr)

    // MAKE SURE THEY DONT CROSS EACH OTHER , if they do loop ends
    while (left < right){

        // GET SUM TO KNOW HOW TO MOVE THROUGH THE LIST
        int sum = arr[left] + arr[right]; 

        if (sum == 0){
            return true;            // match found
        }else if (sum > 0){             
           right --;
        }else {
           left ++;
        }
    } // while

    return false;

}




