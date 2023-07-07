#include <stdio.h>

typedef struct count {
    int data;
    int moved;
} count;

void swap(int *a, int *b, count len[], int size) {
    int t = *a;
    *a = *b;
    *b = t;
    
    for (int h = 0; h < size; h++) {
        if (len[h].data == *a || len[h].data == *b) {
            len[h].moved++;
        }
    }
}

int partition(int array[], int low, int high, count len[], int size) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            swap(&array[i], &array[j], len, size);
        }
    }

    swap(&array[i + 1], &array[high], len, size);
    return (i + 1);
}

void quickSort(int array[], int low, int high, count len[], int size) {
    if (low < high) {
        int pi = partition(array, low, high, len, size);
        quickSort(array, low, pi - 1, len, size);
        quickSort(array, pi + 1, high, len, size);
    }
}

void printArray(int array[], int size, count len[]) {
    for (int i = 0; i < size; ++i) {
        printf("%d  ", array[i]);
    }
    printf("\nAmount of times moved: (number : Times moved)\n");
    for (int i = 0; i < size; ++i) {
        printf("%d : %d\n", len[i].data, len[i].moved);
    }
}

void input(count len[], int array[], int size) {
    for (int i = 0; i < size; i++) {
        len[i].data = array[i];
        len[i].moved = 0;
    }
}

int main() {
    int data[] = {97, 16, 45, 63, 13, 22, 7, 58, 78};
    int n = sizeof(data) / sizeof(data[0]);
    count len[n];

    input(len, data, n);

    printf("Unsorted Array:\n");
    printArray(data, n, len);

    quickSort(data, 0, n - 1, len, n);

    printf("Sorted array in ascending order:\n");
    printArray(data, n, len);

    return 0;
}
