#include <stdio.h>
#include <stdlib.h>

void merge(int leftArray[], int rightArray[], int arr[], int length) {
	int leftSize=length/2;
	int rightSize=length-(length/2);
    int i = 0, l = 0, r = 0;

    while (l < leftSize && r < rightSize) {
        if (leftArray[l] < rightArray[r]) {
            arr[i] = leftArray[l];
            i++;
            l++;
        } else {
            arr[i] = rightArray[r];
            i++;
            r++;
        }
    }

    while (l < leftSize) {
        arr[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < rightSize) {
        arr[i] = rightArray[r];
        i++;
        r++;
    }
}

void mergeSort(int arr[], int length) {
    if (length <= 1){
		return;
	}

    int mid = length / 2;
    int leftArray[mid];
    int rightArray[length - mid];

    for (int i = 0; i < length; i++) {
        if (i < mid) {
            leftArray[i] = arr[i];
        } else {
            rightArray[i - mid] = arr[i];
        }
    }
    mergeSort(leftArray, mid);
    mergeSort(rightArray, length - mid);
    merge(leftArray, rightArray, arr, length);
}

void display(int arr[], int n) {
    printf("The array is: [");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]\n");
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    display(arr, n);
    printf("\n");
    mergeSort(arr, n);
    printf("After sorting the array: ");
    display(arr, n);

    return 0;
}

