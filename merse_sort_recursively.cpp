#include <bits/stdc++.h>
using namespace std;

void merger(int left[],int leftsize,int right[],int rightsize,int arr[]);
void merge_sort(int arr[],int n);
void displayArray(int arr[], int n);
void merge_sort(int arr[],int n){
    if(n==1){
        return;
    }
    int leftsize=n/2;
    int rightsize=n-leftsize;
    int left[leftsize],right[rightsize];

    for(int i=0;i<leftsize;i++){
            left[i]=arr[i];
    }
    for(int i=leftsize;i<n;i++){
        right[i-leftsize]=arr[i];
    }
    merge_sort(left,leftsize);
    merge_sort(right,rightsize);

    merger(left,leftsize,right,rightsize,arr);
}
void merger(int left[],int leftsize,int right[],int rightsize,int arr[]){
    int itL=0,itR=0,itA=0;
    while(itL < leftsize && itR < rightsize){
            if(left[itL]<=right[itR]){
                arr[itA]=left[itL];
                itL++;
                itA++;
            }
            else{
                arr[itA]=right[itR];
                itR++;
                itA++;
            }
    }
    while(itR<rightsize){
            arr[itA]=right[itR];
            itR++;
            itA++;
    }
    while(itL<rightsize){
            arr[itA]=left[itL];
            itL++;
            itA++;
    }
}
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {12000,1400,11,50,90, 8, 1, 5,500,70, 2, 10,100, 7, 3,2000};
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, size);

    cout << "Sorted array: " << endl;
    displayArray(arr, size);

    return 0;
}
