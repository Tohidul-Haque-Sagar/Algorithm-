#include <stdio.h>
int main(){
  int S[20], n;
  printf("How many element you want\n");
  scanf("%d", &n);
  printf("Enter number here\n");
  for (int i= 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  for(int i=1;i<n;i++){
        int temp=S[i];
        int j=i-1;
        while(j>=0 && S[j]>temp){
            S[j+1]=S[j];
            j--;
        }
        S[j+1]=temp;
    }
  printf("\nSorted list ascending:\n");
  for (int i = 0; i < n; i++){
     printf("%d ", S[i]);
  }
    for(int i=1;i<n;i++){
        int temp=S[i];
        int j=i-1;
        while(j>=0 && S[j]<temp){
            S[j+1]=S[j];
            j--;
        }
        S[j+1]=temp;
    }
  printf("\nSorted list descending:\n");
  for (int i = 0; i < n; i++){
     printf("%d ", S[i]);
  }
}

