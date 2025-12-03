#include <stdio.h>

int main() {
    int n, i, pos = -1, ele;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n+1]; 

    printf("Enter %d elements in ascending order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to insert: ");
    scanf("%d", &ele);

    for(i = 0; i < n; i++) {
        if(ele < arr[i]) {
            pos = i;
            break;
        }
    }
    if(pos == -1) 
        pos = n;

    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = ele;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
