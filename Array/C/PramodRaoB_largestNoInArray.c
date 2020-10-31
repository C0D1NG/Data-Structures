#include <stdio.h>
int main() {
    int i, n;
    float array[100];

    printf("Enter the number of elements (<= 100): ");
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &array[i]);
    }

    // storing the largest number to arr[0]
    for (i = 1; i < n; ++i) {
        if (array[0] < array[i])
            array[0] = array[i];
    }

    printf("Largest element = %.2f\n", array[0]);

    return 0;
}
