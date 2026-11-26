
#include <stdio.h>
#include <limits.h>

int main() {
    int arr[] = {2, 2, 3, 1, 5, 5, 4};
    int n = 7;

    long long first = LLONG_MIN;
    long long second = LLONG_MIN;
    long long third = LLONG_MIN;

    int i;

    for (i = 0; i < n; i++) {

        if (arr[i] == first || arr[i] == second || arr[i] == third)
            continue;

        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        }
        else if (arr[i] > second) {
            third = second;
            second = arr[i];
        }
        else if (arr[i] > third) {
            third = arr[i];
        }
    }

    if (third == LLONG_MIN)
        printf("Third maximum does not exist. Maximum: %lld", first);
    else
        printf("Third Maximum: %lld", third);

    return 0;
}
