#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>

#define SIZE 50000
int data[SIZE];

void RandomDataWrite(char *FileName){
    FILE *fp;
    time_t t;
    int i;
    fp = fopen(FileName, "w");
    srand((unsigned) time(&t));

    for(i = 0; i < SIZE; i++){
        fprintf(fp, "%d\n", rand()%INT_MAX);
    }
    fclose(fp);
}

void ReadFromFile(char *FileName){
    FILE *fp;
    int i;
    fp = fopen(FileName, "r");
    for(i = 0; i < SIZE; i++){
        fscanf(fp, "%d", &data[i]);
    }
    fclose(fp);
}

void WriteToConsole(){
    for(int i = 0; i < SIZE; i++){
        printf("%10d", data[i]);
    }
}

int selectionSort(){
  int c = 0;
  for(int i = 0; i < SIZE-1; i++){
    int max = i;
    for (int j = i+1; j < SIZE; j++){
      if (data[j] < data[max])
        max = j;
        c++;
    }
    if(max != i){
      int temp = data[i];
      data[i] = data[max];
      data[max] = temp;
      c++;
    }
  }
  return c;
}
int selectionSort_descending(){
  int c = 0;
  for(int i = 0; i < SIZE-1; i++){
    int min = i;
    for (int j = i+1; j < SIZE; j++){
      if (data[j] > data[min])
        min = j;
        c++;
    }
    if(min != i){
      int temp = data[i];
      data[i] = data[min];
      data[min] = temp;
      c++;
    }
  }
  return c;
}

int bubbleSort(){
  int c = 0;
  for(int i = 0 ; i < SIZE-1; i++){
    for (int j = 0 ; j < SIZE-i-1; j++){
      if (data[j] > data[j+1]){
        int temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
        c++;
      }
    }
  }
  return c;
}
int bubbleSortDescending(){
  int c = 0;
  for(int i = 0 ; i < SIZE-1; i++){
    for (int j = 0 ; j < SIZE-i-1; j++){
      if (data[j] < data[j+1]){
        int temp = data[j];
        data[j] = data[j+1];
        data[j+1] = temp;
        c++;
      }
    }
  }
  return c;
}

int insertionSort() {
  int c = 0;
  for (int i = 1; i < SIZE; i++) {
    c++;
    int key = data[i];
    int j = i-1;
    while (key < data[j] && j >= 0) {
      data[j+1] = data[j];
      --j;
    }
    data[j+1] = key;
  }
  return c;
}
int insertionSortDesending() {
  int c = 0;
  for (int i = 1; i < SIZE; i++) {
    c++;
    int key = data[i];
    int j = i-1;
    while (key > data[j] && j >= 0) {
      data[j+1] = data[j];
      --j;
    }
    data[j+1] = key;
  }
  return c;
}

int main(){
    clock_t start, end;
    int i, ans;
    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    WriteToConsole();
//selection sort
    start = clock();
    ans = selectionSort();
    end = clock();

    double time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\n\nselectionSort took %.10lf seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);
    //Here all are SelectionSort descending

    RandomDataWrite("RandomIntegers.txt");
    ReadFromFile("RandomIntegers.txt");
    start = clock();
    ans = selectionSort_descending();
    end = clock();
    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\n\n SelectionSort for descending took %.10lf seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);

    //bubble sort
    ReadFromFile("RandomIntegers.txt");
    start = clock();
    ans = bubbleSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\nbubbleSort took %.10lf seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);
    // here is all for BubbleSort Descending

   ReadFromFile("RandomIntegers.txt");
    start = clock();
    ans = bubbleSortDescending();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds

    printf("\n\n bubbleSort Descending took %.10lf seconds to execute \n", time_taken);
    printf("\nNumber of times if statement true in the function is %d\n", ans);

    //insert sort
    ReadFromFile("RandomIntegers.txt");
    start = clock();
    ans = insertionSort();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\n\n InsertionSort took %.10lf seconds to execute \n", time_taken);
    printf("\nNumber of times for statement true in the function is %d\n", ans);
    //here all for insert sort descending
    ReadFromFile("RandomIntegers.txt");
    start = clock();
    ans = insertionSortDesending();
    end = clock();

    time_taken = ((double)(end-start))/CLOCKS_PER_SEC;

    printf("\n\n InsertionSort Descending took %.10lf seconds to execute \n", time_taken);
    printf("\nNumber of times for statement true in the function is %d\n", ans);

}
