#include <stdio.h>
#include <stdlib.h>

int linearSearch(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int* arr, int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int interpolationSearch(int* arr, int size, int target) {
    int low = 0;
    int high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low;
            }
            return -1;
        }

        int pos = low + ((double)(high - low) / (arr[high] - arr[low]) * (target - arr[low]));
        if (arr[pos] == target) {
            return pos;
        } else if (arr[pos] < target) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }
    return -1;
}
int main() {
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter the elements (sorted for binary and interpolation search):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    int index = linearSearch(arr, n, target);
    if (index != -1) {
        printf("Linear Search: Element found at index %d\n", index);
    } else {
        printf("Linear Search: Element not found\n");
    }
    index = binarySearch(arr, n, target);
    if (index != -1) {
        printf("Binary Search: Element found at index %d\n", index);
    } else {
        printf("Binary Search: Element not found\n");
    }
    index = interpolationSearch(arr, n, target);
    if (index != -1) {
        printf("Interpolation Search: Element found at index %d\n", index);
    } else {
        printf("Interpolation Search: Element not found\n");
    }
    free(arr);
    return 0;
}
