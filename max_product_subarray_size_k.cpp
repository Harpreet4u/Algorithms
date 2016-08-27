#include<iostream>
#include<cstdio>

using namespace std;


int findMaxProduct(int arr[], int n, int k) {
    
    int max_product = 1, cur_product = 1;
    for (int i=0;i<k;i++) {
        cur_product *= arr[i];
    }
    int prev_product = cur_product;
    for (int i=1;i<=n-k;i++) {
        cur_product = (prev_product/arr[i-1])*arr[i+k-1];
        max_product = max(max_product, cur_product);
        prev_product = cur_product;
    }

    return max_product;
}


int main() {
    int arr1[] = {1, 5, 9, 8, 2, 4, 1, 8, 1, 2};
    int k = 6;
    int n = sizeof(arr1)/sizeof(arr1[0]);
    cout << findMaxProduct(arr1, n, k) << endl;
    
  return 0;

}
