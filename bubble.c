#include <stdio.h>
void bubbleSort(int arr[], int n) {
int i, j;
int flag;
for (i = 0; i < n-1; i++) {
flag = 0;
for (j = 0; j < n-i-1; j++) {
if (arr[j] > arr[j+1]) {
int temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
flag = 1;   }        }
if (flag == 0) {
break;        }    }        }
int main() {
int n, i;
printf("Enter the number of elements: ");
scanf("%d", &n);
int arr[n];
printf("Enter the elements:\n");
for (i = 0; i < n; i++) {
scanf("%d", &arr[i]);  }
bubbleSort(arr, n);
printf("Sorted array: \n");
for (i = 0; i < n; i++) {
printf("%d ", arr[i]);   }
return 0; }
