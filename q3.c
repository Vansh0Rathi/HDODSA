#include <stdio.h>

int main() {
    int n, k;
    int arr[100];
    int found = -1, count = 0;

    // Input size
    scanf("%d", &n);

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input key
    scanf("%d", &k);

    // Linear Search
    for(int i = 0; i < n; i++) {
        count++; // each comparison
        if(arr[i] == k) {
            found = i;
            break;
        }
    }

    // Output
    if(found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }

    printf("Comparisons = %d", count);

    return 0;
}