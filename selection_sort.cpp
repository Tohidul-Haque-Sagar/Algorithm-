#include <stdio.h>
int main(){
  int S[20], n,i,j;
  printf("How many element you want to sorted \n");
  scanf("%d", &n);
  printf("Enter number here\n");
  for (i= 0; i < n; i++){
    scanf("%d", &S[i]);
  }
  for(int i=0;i<n-1;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(S[j]<S[min]){
                    min=j;
            }
        }
        if(min!=i){
                int temp=S[i];
                S[i]=S[min];
                S[min]=temp;
            }
        }
  printf("\nSorted list ascending O(n):\n");
  for (int i = 0; i < n; i++){
     printf("%d ", S[i]);
  }
  for(int i=0;i<n-1;i++){
        int max=i;
        for(j=i+1;j<n;j++){
            if(S[j]>S[max]){
                    max=j;
            }
        }
        if(max!=i){
                int temp=S[i];
                S[i]=S[max];
                S[max]=temp;
            }
        }
  printf("\nSorted list descending O(n):\n");
  for (int i = 0; i < n; i++){
     printf("%d ", S[i]);
  }
}

