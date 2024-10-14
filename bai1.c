#include<stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int n = 9;
    int arr[] = {2, 0, 2, 0, 0, 1, 0, 2, 1};
    for(int i = 0; i < 9; i++) {
        for(int j = i + 1; j < 9; j++) {
            if(arr[i] > arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
    printf("new array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}