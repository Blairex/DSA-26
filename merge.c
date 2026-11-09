#include <stdio.h>
#define MAX 100

void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);

int main() {
  int arr[MAX];
  int n, low = 0, high, i;
  printf("Merge Sort Program\n");
  printf("Enter the number of elements:");
  scanf("%d", &n);
  high = n - 1;
  for (i = 0; i < n; i++) {
    printf("Enter value for index[%d]:", i);
    scanf("%d", &arr[i]);
  }
  printf("\nArray Before Sorting:\n");
  for (i = 0; i < n; i++) {
    printf("Value at index[%d]:%d\n", i, arr[i]);
  }
  mergeSort(arr, low, high);
  printf("\nArray After Sorting:\n");
  for (i = 0; i < n; i++) {
    printf("Value at index[%d]:%d\n", i, arr[i]);
  }
  return 0;
}

void mergeSort(int arr[], int low, int high) {
  int mid;
  if (low < high) {
    mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}

void merge(int arr[], int low, int mid, int high) {
  int i = low, j = mid + 1, k = low;
  int b[MAX];

  while (i <= mid && j <= high) {
    if (arr[i] < arr[j]) {
      b[k] = arr[i];
      i++;
    } else {
      b[k] = arr[j];
      j++;
    }
    k++;
  }

  while (i <= mid) {
    b[k] = arr[i];
    k++;
    i++;
  }
  while (j <= high) {
    b[k] = arr[j];
    k++;
    j++;
  }
  for (i = low; i <= high; i++) {
    arr[i] = b[i];
  }
}
