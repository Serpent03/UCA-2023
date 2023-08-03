/* There is a list of encrypted files of size n, each with a different value, and a list of n binary values. A value of 1 represents a file that has been 
decrypted, and 0 represents an encrypted file that is not yet decrypted. The value sum of the encrypted files is the sum of all values of the files
where the corresponding value in the binary list isl
1. In a single operation, a group of up to k encrypted files can be decrypted simultaneously.
The values of the encrypted files and the binary list are given, along with the maximum number of encrypted files that can be decrypted in a single 
operation. Find the maximum possible value sum of the decrypted files.
Note: A group, i.e., subarray is defined as any contiguous segment of the array.

Example 1
Given n = 4, k = 2, encrypted_file = [7, 4, 3, 5], and
binary = [1, 0, 0, 0].


Example 2
Given n = 6, k = 2, encrypted_file = [1 , 3, 5, 2 , 5 ,4], and
binary = [1,1, 0, 1, 0, 0].

Answer is 15 */
#include<stdio.h>
#include<assert.h>
#include<limits.h>
int slidingWindow(int a[], int n, int k, int binary[]){
    int temp_a[n];
    for (int i = 0; i < n; i++) {
        temp_a[i] = a[i];
    }
    for (int i = 0; i < n; i++) {
       if (binary[i] == 1) temp_a[i] = INT_MIN; 
    } 
    int p1 = 0;
    int p2 = 0;
    int temp_sum = 0;
    int final_sum = 0;
    while (p2 <  n) {
        temp_sum += temp_a[p2];
        if (p2 - p1 + 1 == k ) {
            if (temp_sum > final_sum) {
                final_sum = temp_sum;
            }
            temp_sum -= temp_a[p1]; 
            p1++;
        }
        p2++;
    }
    return final_sum;
}
int operation(int a[], int n, int k, int binary[]) {
 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (binary[i] == 1 && a[i] != -1) {
            ans += a[i];
        }
    } 
    return ans;
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int k;
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int a[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int binary[n];
    printf("Enter the binary array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &binary[i]);
    }
    int ans = operation(a, n, k,  binary);
    ans += slidingWindow(a, n, k, binary);
    printf("%d \n", ans);
}

