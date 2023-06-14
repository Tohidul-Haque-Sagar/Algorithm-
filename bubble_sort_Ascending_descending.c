#include <stdio.h>
int main(){
  int S[20], n;
  printf("How many element you want\n");
  scanf("%d", &n);
  printf("Enter number here\n");
  for (int i= 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  for(int i = 0 ; i < n-1; i++){
    for (int j = 0 ; j < n-i-1; j++){
      if (S[j] > S[j+1]){
        int swap = S[j];
        S[j] = S[j+1];
        S[j+1] = swap;
      }
    }
  }
  printf("\nSorted list ascending:\n");
  for (int i = 0; i < n; i++){
     printf("%d ", S[i]);
  }
  for(int i = 0 ; i < n-1; i++){
    for (int j = 0 ; j < n-i-1; j++){
      if (S[j] < S[j+1]){
        int swap = S[j];
        S[j] = S[j+1];
        S[j+1] = swap;
      }
    }
  }
  printf("\nSorted list descending:\n");
  for (int i = 0; i < n; i++){
     printf("%d ", S[i]);
  }
}
