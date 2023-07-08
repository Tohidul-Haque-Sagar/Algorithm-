#include <stdio.h>
//for this problem time complexity will be O(n^2)
//inner loop will take n-1*n/2 times
//outer loop will take n times
// so time complexity will be O({n^2-n+2n}/2)

int countDistinct(int arr[], int size) {
    int distinctCount = 0;
    int distinctFlag;

    for (int i = 0; i < size; i++) {
        distinctFlag = 1;

        // Check if arr[i] is distinct
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                distinctFlag = 0;
                break;
            }
        }

        // Increment distinctCount if arr[i] is distinct
        if (distinctFlag == 1) {
            distinctCount++;
        }
    }

    return distinctCount;
}

int main() {
    int arr[] = {0,1, 2, 3, 4, 4, 5, 6, 6, 7, 8, 8, 9, 9, 9,2 ,10,5};
    int size = sizeof(arr) / sizeof(arr[0]);

    int distinctCount = countDistinct(arr, size);

    printf("Total distinct numbers: %d\n", distinctCount);

    return 0;
}


