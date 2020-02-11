/*
    Selection Sort
*/

#include <stdio.h>

void Show(int A[], int n, char *c) {
    int i;
    printf("%s",c);
    for(i = 0; i < n; i++) {
        printf("[%d]",A[i]);
    }
    printf("\n");
}

void Swap(int *A, int *B) {
 int t;
 t = *A;
 *A = *B;
 *B = t;
}

void SelectionSort(int *A, int n) {
    int i,j,min;
    for(i = 0; i < n; i++) {
       min = i;
       for(j = min+1; j < n; j++) {
           if (A[j] < A[min]) {
               min = j;
           }
       }
       Swap(&A[i],&A[min]);
    }
}

void RecursiveSelectionSort(int *A, int i, int n) {
    int min, j;
    if(i >= n-1) {
        return;
    }
    
    min = i;
    for(j = min+1; j < n; j++) {
        if (A[j] < A[min]) {
           min = j;
        }
    }
    Swap(&A[i],&A[min]);
    RecursiveSelectionSort(A,i+1,n);
}

int main()
{
    int n = 6;
    int A[6] = {74,32,89,55,21,64};
    int B[6] = {74,32,89,55,21,64};
    
    Show(A, n, "Unsorted Array => ");
    SelectionSort(&A[0],n);
    Show(A, n, "Sorted Array => ");
    
    Show(B, n, "\nUnsorted Array => ");
    RecursiveSelectionSort(&B[0],0,n);
    Show(B, n, "Sorted Array => ");

    return 0;
}
