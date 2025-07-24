/* Array utility functions for basic array operations */
#include <stdio.h>

int array_sum(int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

double array_avg(int *arr, int n) {
    if (n == 0) {
        return 0;
    }
    return (double)array_sum(arr, n) / n;
}

int array_min(int *arr, int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int array_max(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int array_search(int *arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

void array_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void array_reverse(int *arr, int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}

void array_copy(int *dest, int *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int count_even(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int count_odd(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

void print_results() {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("Sum: %d\n", array_sum(arr, 5));
    printf("Min: %d\n", array_min(arr, 5));
    printf("Even count: %d\n", count_even(arr, 5));
}

int main() {
    print_results();
    return 0;
} 