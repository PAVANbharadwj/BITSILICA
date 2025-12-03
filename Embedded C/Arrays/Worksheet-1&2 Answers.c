// 1)Question: Print elements of an array
// Question description: Write a C program to read n elements into an array and display them.
// Sample data:
// Enter the number of elements: 5
// Enter the elements: 10 20 30 40 50
// Expected output:
// Elements in array are: 10 20 30 40 50
 
#include<stdio.h>
#include<stdlib.h>

int main() {
int n,i;
    printf("enter number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements of array:");
    for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
    }
    printf("dispaly the elements:");
    for(i=0;i<n;i++){
    printf("%d",arr[i]);
    }
    return 0;
}



// 2)Question: Sum of all elements in array
// Question description: Write a C program to find the sum of all array elements entered by the user.
// Sample data:
// Input: 1 2 3 4 5
// Expected output:
// Sum = 15

#include<stdlib.h>
#include<stdio.h>
int main(){
int n,i,sum=0;
printf("enter no if ele:");
scanf("%d",&n);
int a[n];
printf("enter values:");
for(i=0;i<n;i++){
scanf("%d",&a[i]);}
for(i=0;i<n;i++){
sum+=a[i];
}
printf("%d",sum);
return 0;
}


// 3)Question: Find maximum and minimum element
// Question description: Write a C program to find the largest and smallest element in the array.
// Sample data:
// Input: 8 3 15 6 2
// Expected output:
// Maximum = 15
// Minimum = 2

#include<stdlib.h>
#include<stdio.h>
int main() {
	int n,i;
	int min,max;
	printf("enetr no of ele:");
	scanf("%d",&n);
	int arr[n];
	for(i=0; i<n; i++) {
		scanf("%d",&arr[i]);
	}
	max=min=arr[0];
	for(i=1; i<n; i++) {
		if(arr[i]>max) {
			max=arr[i];
		}
		if(arr[i]<min) {
			min=arr[i];
		}
	}
	printf("%d",max);
	printf("%d",min);
	return 0;
}


// 4)Question: Count even and odd elements
// Question description: Write a C program to count how many even and odd numbers are in the array.
// Sample data:
// Input: 4 7 9 10 22
// Expected output:
// Even: 3
// Odd: 2

#include<stdlib.h>
#include<stdio.h>
int main() {
    int n,i;
    printf("enter no of ele:");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int even=0,odd=0;
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
           even+=1; 
        }
        else{
            odd+=1;
        }
    }
    printf("%d",even);
    printf("%d",odd);
	return 0;
}


// 5)Question: Copy array elements
// Question description: Write a C program to copy all elements from one array to another.
// Sample data:
// Input: 1 2 3 4 5
// Expected output:
// Copied array: 1 2 3 4 5

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int copy_arr[n];
    for (i = 0; i < n; i++) {
        copy_arr[i] = arr[i]; 
    }
    printf("Copied array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", copy_arr[i]);
    }
    printf("\n");
    return 0;
}

// 6)Question: Count negative elements
// Question description: Write a C program to count total number of negative elements in an array.
// Sample data:
// Input: -1 3 -4 5 0 -7
// Expected output:
// Total negative elements: 3

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count=0;
    for(i=0;i<n;i++){
        if(arr[i]<=0){
            count+=1;
        }
    }
    printf("%d",count);
    return 0;
}


// 7)Question: Find for an element
// Question description: Write a C program to search for a number in an array and print its index.
// Sample data:
// Array: 10 20 30 40 50
// Find: 30
// Expected output:
// Element found at index: 2


#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i,n;
    printf("enter no of array elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements to array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int k,found=0;
    printf("enter value to search:");
    scanf("%d",&k);
    for(i=0;i<n;i++){
        if(k==arr[i]){
            printf("the ele found at value%d",i);
            found+=1;
        }
    }
    if(!found){
        printf("Not found");
    }

    return 0;
}


// 8)Question: Reverse an array
// Question description: Write a C program to reverse an array in-place.
// Sample data:
// Input: 10 20 30 40 50
// Expected output:
// Reversed array: 50 40 30 20 10

#include <stdio.h>
#include<stdlib.h>
int main()
{
    int i,n;
    printf("enter no of array elements:");
    scanf("%d",&n);
    int arr[n];
    printf("enter elements to array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n/2;i++){
        int temp=arr[i];
        arr[i]=arr[n-1-i];
        arr[n-1-i]=temp;
    }
    printf("reversed string:");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}

// 9)Question: Insert element at position
// Question description: Write a C program to insert a number at a given position in an array.
// Sample data:
// Array: 10 20 30 40
// Insert: 25 at position 2
// Expected output:
// Array after insertion: 10 20 25 30 40

#include <stdio.h>
int main() {
    int arr[100], n, i, pos, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter value to insert: ");
    scanf("%d", &val);
    printf("Enter position: ");
    scanf("%d", &pos);
    if(pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }
    for(i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++; 
    printf("Array after insertion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// 10)Question: Delete element at position
// Question description: Write a C program to delete a number at a given position in an array.
// Sample data:
// Array: 10 20 30 40
// Delete at position: 2
// Expected output:
// Array after deletion: 10 20 40


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter elements into the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int pos;
    printf("Enter index to delete (0-based index): ");
    scanf("%d", &pos);
    if(pos < 0 || pos >= n) {
        printf("Invalid deletion index!\n");
        return 1;
    }
    for(i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Array after deletion: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}


// 11)Question: Sort array in ascending order
// Question description: Write a C program to sort elements in ascending order.
// Sample data:
// Input: 20 5 10 8
// Expected output:
// Sorted array: 5 8 10 20


//BUBBLE SORT
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n,temp;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    printf("Array after sorting: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}


// 12)Question: Sort array in descending order
// Question description: Write a C program to sort array elements in descending order.
// Sample data:
// Input: 7 2 9 4
// Expected output:
// Sorted array: 9 7 4 2

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n,temp;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    
    printf("Array after sorting: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}


// 13)Question: Merge two arrays
// Question description: Write a C program to merge two arrays into a third array.
// Sample data:
// Array 1: 1 2 3
// Array 2: 4 5 6
// Expected output:
// Merged array: 1 2 3 4 5 6


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n2,n1;
    printf("Enter number of array elements: ");
    scanf("%d", &n1);

    int arr1[n1];
    printf("Enter elements into the array1:");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of array elements: ");
    scanf("%d", &n2);

    int arr2[n2];
    printf("Enter elements into the array2:");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int merged[n1+n2];
    for(i=0;i<n1;i++){
        merged[i]=arr1[i];
    }
    for(i=0;i<n2;i++){
        merged[n1+i]=arr2[i];
    }
    printf("Array after sorting: ");
    for(i = 0; i < n1+n2; i++) {
        printf("%d ", merged[i]);
    }

    printf("\n");
    return 0;
}


// 14)Question: Frequency of each element
// Question description: Write a C program to count the frequency of each element in an array.
// Sample data:
// Input: 1 2 2 3 3 3
// Expected output:
// 1 occurs 1 time
// 2 occurs 2 times
// 3 occurs 3 times


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        int count=1;
        if(arr[i]!=-1){
            for(j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    count++;
                    arr[j]=-1;
                }
            }
            printf("%d occurs %d times\n",arr[i],count);
        }
    }
    return 0;
}

// 15)Question: Remove duplicate elements
// Question description: Write a C program to remove duplicate elements from an array.
// Sample data:
// Input: 2 3 2 4 3 5
// Expected output:
// Array after removing duplicates: 2 3 4 5

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, k = 0;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n], result[n];
    printf("Enter elements into the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Remove duplicates logic
    for(i = 0; i < n; i++) {
        int isdup = 0;
        // Check if arr[i] is already in result
        for(j = 0; j < k; j++) {
            if(arr[i] == result[j]) {
                isdup = 1;
                break;
            }
        }

            if(isdup == 0) {
            result[k] = arr[i];  // Corrected the equality operator to assignment
            k++;
        }
    }

    // Output the array after removing duplicates
    printf("Array after removing duplicates: ");
    for(i = 0; i < k; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
    return 0;
}


// 16)Question: Find duplicate elements
// Question description: Write a C program to find all duplicate elements in an array.
// Sample data:
// Input: 1 2 3 2 4 1
// Expected output:
// Duplicate elements: 1 2

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, k = 0;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n], result[n];
    printf("Enter elements into the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n; i++) {
        int isdup = 0;
        for(j = 0; j < k; j++) {
            if(arr[i] == result[j]) {
                isdup = 1;
                break;
            }
        }
        if(isdup == 0) {
            int alreadyPrinted = 0;
            for(j = 0; j < i; j++) {
                if(arr[i] == arr[j]) {
                    alreadyPrinted = 1;
                    break;
                }
            }
            
            if(!alreadyPrinted) {
                printf("%d ", arr[i]);
                isdup = 1;
            }
        }
    }
     printf("\n");
    return 0;
}


// 17)Question: Find second largest element
// Question description: Write a C program to find the second largest number in the array.
// Sample data:
// Input: 10 20 50 40
// Expected output:
// Second largest: 40


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     int first, second;
    if(n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    } 
    if(arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }
    for(i = 2; i < n; i++) {
        if(arr[i] > first) {
            second = first;  
            first = arr[i];  
        } else if(arr[i] > second && arr[i] != first) {
            second = arr[i]; 
        }
    }
    printf("%d",second);
    return 0;
}


// 18)Question: Difference between max and min
// Question description: Write a C program to find the difference between largest and smallest elements in an array.
// Sample data:
// Input: 5 1 9 3 6
// Expected output:
// Difference: 8


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
     int first, second;
    if(n < 2) {
        printf("Array must have at least two elements.\n");
        return 0;
    } 
    if(arr[0] > arr[1]) {
        first = arr[0];
        second = arr[1];
    } else {
        first = arr[1];
        second = arr[0];
    }
    int k;
    k= first-second;
    printf("%d",k);
    return 0;
}

// 19)Question: Left rotate array by n
// Question description: Write a C program to rotate an array to the left by n positions.
// Sample data:
// Array: 1 2 3 4 5
// Rotate by: 2
// Expected output:
// Rotated array: 3 4 5 1 2

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,temp,r,n;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("how many left rotations:");
    scanf("%d",&r);
    r=r%n;
    for(i=0;i<r;i++){
        temp=arr[0];
        for(j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
    printf("final array:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}


// 20)Question: Right rotate array by n
// Question description: Write a C program to rotate an array to the right by n positions.
// Sample data:
// Array: 1 2 3 4 5
// Rotate by: 2
// Expected output:
// Rotated array: 4 5 1 2 3

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,temp,r,n;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("how many right rotations:");
    scanf("%d",&r);
    r=r%n;
    for(i=0;i<r;i++){
        temp=arr[n-1];
        for(j=n-1;j>0;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
    printf("final array:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}


// 21)Question: Sum of even numbers
// Question description: Write a C program to find the sum of all even numbers in an array.
// Sample data:
// Input: 2 3 4 5 6
// Expected output:
// Sum of even numbers: 12

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,j,n,count;
    printf("enter no of elements in array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter array elements:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]%2==0){
            count+=arr[i];
        }
    }
    printf("%d",count);
    return 0;
}


// 22)Question: Count prime numbers
// Question description: Write a C program to count and display all prime numbers in an array.
// Sample data:
// Input: 2 4 5 6 7 8
// Expected output:
// Primes: 2 5 7
// Count: 3


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(int num) {
    if (num <= 1) {
        return 0;  
    }
    if (num == 2) {
        return 1; 
    }
    if (num % 2 == 0) {
        return 0; 
    }
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int i, n, count = 0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            count++; 
        }
    }
    printf("Primes: %d\n", count);
    return 0;
}

// 23)Question: Count duplicate elements
// Question description: Write a C program to count how many duplicate values are in the array.
// Sample data:
// Input: 1 2 3 1 4 2
// Expected output:
// Total duplicate elements: 2


#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, j, n, count = 0;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        int isdup=0;
        for(j=0;j<i;j++){
            if(arr[i]==arr[j]){
                isdup=1;
                break;
            }
        }
        if(isdup==0){
            int countoccur=0;
            for(j=0;j<n;j++){
                if(arr[i]==arr[j]){
                countoccur++;
            }
        }
        if(countoccur>1){
            count++;
        }
    }
    }
    printf("%d", count);
    return 0;
}



// 24)Question: Split array into halves
// Question description: Write a C program to split the array into two halves and print them separately.
// Sample data:
// Input: 1 2 3 4 5 6
// Expected output:
// First half: 1 2 3
// Second half: 4 5 6


#include <stdio.h>
#include <stdlib.h>
int main() {
    int i, n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
        int mid=n/2;
    printf("first half:");
    for(i=0;i<mid;i++){
        printf("%d",arr[i]);
        }
    printf("\nsecond half:");
    for(i=mid;i<n;i++){
        printf("%d",arr[i]);
        }
    }
    return 0;
}


// 25)Question: Segregate even and odd
// Question description: Write a C program to arrange all even numbers first and then all odd numbers.
// Sample data:
// Input: 1 2 3 4 5 6
// Expected output:
// Even numbers: 2 4 6
// Odd numbers: 1 3 5


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Even numbers: ");
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    
    printf("\nOdd numbers: ");
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }
    
    return 0;
}



// 26)Find the union of two arrays
 
// Question description:
// Write a C program to find the union of two arrays (all unique elements from both arrays).
// Sample data:
// Array 1: 1 2 3 4 Array 2: 3 4 5 6
// Expected output:
// Union: 1 2 3 4 5 6


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n1, n2,flag;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n1);
    
    int arr1[n1];
    
    printf("Enter array elements: ");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of elements in the array: ");
    scanf("%d", &n2);
    
    int arr2[n2];
    
    printf("Enter array elements: ");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int union_arr[n1 + n2];
    int k = 0;
    for(i = 0; i < n1; i++) {
        union_arr[k++] = arr1[i];
    }
    for(i = 0; i < n2; i++) {
        flag = 0;
        for(j = 0; j < k; j++) {
            if(arr2[i] == union_arr[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            union_arr[k++] = arr2[i];
        }
    }
    printf("Union of the two arrays: ");
    for(i = 0; i < k; i++) {
        printf("%d ", union_arr[i]);
    }
    
    return 0;
}



// 27)Question description:
// Write a C program to find the intersection of two arrays (common elements).
// Sample data:
// Array 1: 1 2 3 4 Array 2: 3 4 5 6
// Expected output:
// Intersection: 3 4


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n1, n2,flag;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n1);
    
    int arr1[n1];
    
    printf("Enter array elements: ");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of elements in the array: ");
    scanf("%d", &n2);
    
    int arr2[n2];
    
    printf("Enter array elements: ");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("Intersection: ");
    int found=0;
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                printf("%d",arr1[i]);
                found=1;
                break;
            }
        }
    }
    if(!found){
        printf("no common ele found");
    }
    return 0;
}


// 28)Find the difference of two arrays

// Question description:
// Write a C program to find the difference of two arrays (elements present in first array but not in second).
// Sample data:
// Array 1: 1 2 3 4 Array 2: 3 4 5 6
// Expected output:
// Difference (Array1 - Array2): 1 2

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n1, n2,found;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n1);
    
    int arr1[n1];
    
    printf("Enter array elements: ");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of elements in the array: ");
    scanf("%d", &n2);
    
    int arr2[n2];
    
    printf("Enter array elements: ");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    printf("Diffrence: ");
    int anyfound=0;
    for(i=0;i<n1;i++){
        found=0;
        for(j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                found=1;
                break;
            }
        }
    	if(found==0){
        printf("%d",arr1[i]);
        }
    }
    return 0;
}


// 29)Check if array is palindrome
// Question description:
// Write a C program to check whether an array is palindrome (reads the same forward and backward).
// Sample data:
// Input: 1 2 3 2 1
// Expected output:
// The array is a palindrome.


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j,n,flag;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i]==arr[j]){
                flag=1;
                break;
            }
        }
    }
    if(flag>0){
        printf("Palindrom");
    }
    else{
        printf("Not palindrom");
    }
    return 0;
}

// 30)Count pairs with given sum
  
// Question description:
// Write a C program to find number of pairs in the array whose sum is equal to a given value.
// Sample data:
// Input array: 1 5 7 -1 5 Sum = 6
// Expected output:
// Number of pairs: 3


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, j, sum, count;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("enter sum:");
    scanf("%d",&sum);
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == sum) {
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}





// 31)Find missing number in array
 
// Question description:
// Write a C program to find the missing number in an array of size n containing numbers from 1 to n+1.
// Sample data:
// Input: 1 2 4 5 6
// Expected output:
// Missing number is: 3

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int expected_sum=(n+1)*(n+2)/2;
    int actual_sum=0;
    for(i=0;i<n;i++){
        actual_sum+=arr[i];
        }
    int missing_number=expected_sum-actual_sum;
    printf("Missing number:%d",missing_number);
    return 0;
}


// 32) Find the majority element
 
// Question description:
// Write a C program to find the majority element in an array (element appearing more than n/2 times).
// Sample data:
// Input: 2 2 1 2 3 2 2
// Expected output:
// Majority element: 2



#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, k;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int count=0;
    for(i=0;i<n;i++){
        if(count==0){
            k=arr[i];
        }
        if(arr[i]==k){
           count++; 
        }
        else{
            count--;
        }
    }
    count=0;
    for(i=0;i<n;i++){
        if(arr[i]==k){
            count++;
        }
    }
    if(count>n/2){
        printf("%d",k);
    }
    else{
        printf("No Majaority");
    }
    return 0;
}


// 33)Find subarray with maximum sum (Kadane’s Algorithm)
 
// Question description:
// Write a C program to find the maximum sum of a contiguous subarray.
// Sample data:
// Input: -2 -3 4 -1 -2 1 5 -3
// Expected output:
// Maximum contiguous sum is 7


// 34)Find leader elements in array
 
// Question description:
// Write a C program to find all leader elements in the array (elements greater than all elements to their right).
// Sample data:
// Input: 16 17 4 3 5 2
// Expected output:
// Leader elements: 17 5 2



#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int right = arr[n-1];
    printf("Leader elements: %d ", right);
    for(i = n-2; i >= 0; i--) {
        if(arr[i] > right) {
            right = arr[i];
            printf("%d ", arr[i]); 
        }
    }
    
    return 0;
}




//  35)Find equilibrium index
 
// Question description:
// Write a C program to find the index where the sum of elements to the left is equal to the sum to the right.
// Sample data:
// Input: -7 1 5 2 -4 3 0
// Expected output:
// Equilibrium index is 3


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, j, found=0;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        int left_sum=0;
        for(j=0;j<i;j++){
            left_sum+=arr[j];
        }
        int right_sum=0;
        for(j=i+1;j<n;j++){
            right_sum+=arr[j];
        }
        if(left_sum==right_sum){
            printf("%d",i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("NO EQUILIBRIUM INDEX");
    }
return 0;
}


// 36)Find second smallest element
 
// Question description:
// Write a C program to find the second smallest element in the array.
// Sample data:
// Input: 12 13 1 10 34 1
// Expected output:
// Second smallest element is 10


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, j;
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int first, second;
    if(arr[0]<arr[1]){
        first=arr[0];
        second=arr[1];
    }
    else{
        first=arr[1];
        second=arr[0];
    }
    for(i=2;i<n;i++){
        if(arr[i]<first){
            second=first;
            first=arr[i];
        }
        else if(arr[i]<second && arr[i]!=first){
            second=arr[i];
        }
    }
    printf("%d",second);
 return 0;
}




// 37)Check if array is subset of another
 
// Question description:
// Write a C program to check if one array is a subset of another array.
// Sample data:
// Array 1: 1 2 3 4 5 Array 2: 2 4 5
// Expected output:
// Array2 is a subset of Array1



#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n1, n2;
    
    printf("Enter number of elements in the array1: ");
    scanf("%d", &n1);
    
    int arr1[n1];
    
    printf("Enter array elements: ");
    for(i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter number of elements in the array2: ");
    scanf("%d", &n2);
    
    int arr2[n2];
    
    printf("Enter array elements: ");
    for(i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int found=0;
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(arr1[i]==arr2[j]){
                found=1;
                break;
            }
        }
    }
    if(!found){
        printf("No subset");
    }
    else{
        printf("Array1 is a subset of array2");
    }
 return 0;
}




// 38)Sort array of 0s, 1s and 2s
 
// Question description:
// Write a C program to sort an array consisting of only 0s, 1s, and 2s.
// Sample data:
// Input: 0 1 2 0 1 2 1 0
// Expected output:
// Sorted array: 0 0 0 1 1 1 2 2

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n,j,temp;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
       for(j=0;j<n-1-i;j++){
           if(arr[j]>arr[j+1]){
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       } 
    }
        
    printf("Fianl array:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}




// 39)Find product of all elements
 
// Question description:
// Write a C program to find the product of all elements in the array.
// Sample data:
// Input: 1 2 3 4
// Expected output:
// Product: 24


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n, product=1;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        product*=arr[i];
        }
    printf("%d",product);
 return 0;
}



// 40) Find the maximum difference between two elements such that larger element appears after the smaller
// Question description:
// Write a C program to find the maximum difference between two elements in an array such that the larger element appears after the smaller element.
// Sample data:
// Input: 2 3 10 6 4 8 1
// Expected output:
// Maximum difference: 8 (10 - 2)

#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    
    int arr[n];
    
    printf("Enter array elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int k=arr[0];
    int diff=arr[1]-arr[0];
    for(i=0;i<n;i++){
        if(arr[i]-k>diff){
            diff=arr[i]-k;
        }
        if(arr[i]<k){
            k=arr[i];
        }
    }
    printf("%d",diff);
 return 0;
}



// 41)Find the minimum and maximum element using minimum comparisons
 
// Question description:
// Write a C program to find minimum and maximum elements using minimum number of comparisons.
// Sample data:
// Input: 1000 11 445 1 330 3000
// Expected output:
// Minimum element is 1 Maximum element is 3000


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n,j,temp;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) { 
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n-1;i++){
       for(j=0;j<n-1-i;j++){
           if(arr[j]>arr[j+1]){
               temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       } 
    }
        
    printf("Min ele in array:%d\n",arr[0]);
    printf("Max ele in array:%d",arr[n-1]);
    return 0;
}


// 42)Count occurrences of a number
 
// Question description:
// Write a C program to count how many times a specific number appears in an array.
// Sample data:
// Input array: 1 2 3 2 2 5 Number to count: 2
// Expected output:
// Number 2 occurs 3 times


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n, count=0,num;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("enter number to count: ");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        if(arr[i]==num){
            count+=1;
        }
    }
    printf("%d occurs %d times",num,count);
    return 0;
}



// 43) Find two elements whose sum is closest to zero
 
// Question description:
// Write a C program to find two elements whose sum is closest to zero.
// Sample data:
// Input: 1 60 -10 70 -80 85
// Expected output:
// Pair whose sum is closest to zero: -80 85



// 44)Rearrange positive and negative numbers
 
// Question description:
// Write a C program to rearrange an array so that positive and negative numbers are placed alternatively.
// Sample data:
// Input: 1 2 3 -4 -1 4
// Expected output:
// Rearranged array: -4 1 -1 2 3 4


#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Invalid Input\n");
    return 1;
    }
    int arr[n];  
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
     int i = -1, temp = 0;

    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int pos = i + 1, neg = 0;
    while (pos < n && neg < pos && arr[neg] < 0) {
        temp = arr[neg];
        arr[neg] = arr[pos];
        arr[pos] = temp;

        pos++;
        neg += 2;
    }
    printf("ARRAY AFTER UPDATE: \n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}


// 45) Move all zeros to end of array
 
// Question description:
// Write a C program to move all zeros in the array to the end while maintaining the order of non-zero elements.
// Sample data:
// Input: 1 0 2 0 0 3 4
// Expected output:
// Output: 1 2 3 4 0 0 0


#include <stdio.h>
#include <stdlib.h>

int main() {
    int i,n, j=0;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n],result[n];
    printf("Enter elements into the array:");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]!=0){
            result[j++]=arr[i];
        }
    }
    while(j<n){
        result[j++]=0;
    }
    printf("Fianl array:");
    for(i=0;i<n;i++){
        printf("%d",result[i]);
    }
    return 0;
}


// 46)Find the frequency of each element
 
// Question description:
// Write a C program to find the frequency of each element in the array.
// Sample data:
// Input: 10 20 10 30 20 20 10 10
// Expected output:
// 10: 4 20: 3 30: 1

#include <stdio.h>
#include<stdlib.h>

int main() {
    int i, j, n, count;
    printf("Enter number of array elements: ");
    scanf("%d", &n);

    int arr[n], freq[n];

    printf("Enter elements into the array: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1;  
    }

    for(i = 0; i < n; i++) {
        count = 1;
        if(freq[i] != 0) {
            for(j = i + 1; j < n; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                    freq[j] = 0; 
                }
            }
            freq[i] = count;
        }
    }

    printf("Frequencies:\n");
    for(i = 0; i < n; i++) {
        if(freq[i] != 0) {
            printf("%d: %d\n", arr[i], freq[i]);
        }
    }

    return 0;
}



// 47)Find maximum sum of k consecutive elements

// Question description:
// Write a C program to find maximum sum of k consecutive elements in an array.
// Sample data:
// Input: 2 3 4 1 5 6 7 k = 3
// Expected output:
// Maximum sum of 3 consecutive elements: 18


#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,n,j,temp,count;
    printf("enter no of array elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter ele to array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    int diff=arr[n-1]-arr[n-2];
    for(i=0;i<n;i++){
        if(arr[i-1]-arr[i-2]==diff){
            count+=arr[i];
        }
    }
    printf("%d",count);
    return 0;
}


// 48)Rotate array by k positions
// Question description:
// Write a C program to rotate the elements of an array by k positions to the right.
// Sample data:
// Input: 1 2 3 4 5 k = 2
// Expected output:
// Output: 4 5 1 2 3


#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,n,j,temp,k;
    printf("enter no of array elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter ele to array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter k rotations to right:");
    scanf("%d",&k);
    for(i=0;i<k;i++){
        temp=arr[n-1];
        for(j=n-1;j>0;j--){
            arr[j]=arr[j-1];
        }
        arr[0]=temp;
    }
    printf("Rotated array:");
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}


// 49)Find longest consecutive sequence
// Question description:
// Write a C program to find the length of the longest consecutive elements sequence.
// Sample data:
// Input: 100 4 200 1 3 2
// Expected output:
// Longest consecutive sequence length: 4 (1, 2, 3, 4)



// 50)Find the missing two numbers in an array
 
// Question description:
// Write a C program to find two missing numbers from an array containing numbers from 1 to n+2.
// Sample data:
// Input: 1 2 4 6
// Expected output:
// Missing numbers: 3 5


// Challenges
// ------------

// 2)Rearrange array elements so that positive and negative numbers are placed alternatively
// Without changing the relative order of positive and negative numbers, rearrange them alternately. Extra space should be avoided if possible.

 
// Example: Input: [1, 2, -3, -1, -2, 3]
// Output: [1, -3, 2, -1, 3, -2]
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    if (n < 2) {
        printf("Invalid Input\n");
    return 1;
    }
    int arr[n];  
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
     int i = -1, temp = 0;

    for (int j = 0; j < n; j++) {
        if (arr[j] < 0) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int pos = i + 1, neg = 0;
    while (pos < n && neg < pos && arr[neg] < 0) {
        temp = arr[neg];
        arr[neg] = arr[pos];
        arr[pos] = temp;

        pos++;
        neg += 2;
    }
    printf("ARRAY AFTER UPDATE: \n");
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}