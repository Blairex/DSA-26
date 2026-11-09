#include <stdio.h>
#define MAX 100

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
  int arr[MAX];
  int n, low = 0, high, i;
  printf("Quick Sort Program\n");
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
  quickSort(arr, low, high);
  printf("\nArray After Sorting:\n");
  for (i = 0; i < n; i++) {
    printf("Value at index[%d]:%d\n", i, arr[i]);
  }
  return 0;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  int j, temp;

  for (j = low; j < high; j++) {
    if (arr[j] < pivot) {
      i++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }

  i++;
  temp = arr[i];
  arr[i] = arr[high];
  arr[high] = temp;

  return i;
}
