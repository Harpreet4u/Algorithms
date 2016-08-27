#include<iostream>
#include<cstdio>

using namespace std;

// 2 traversals from forward and backward technique.
int max_product(int arr[], int n) {
    int max_fwd = -1000000;
    int max_bwd = -1000000;

    int max_so_far = 1;

    for (int i=0;i<n;i++) {
        max_so_far *= arr[i];
        if (max_so_far == 0) {
            max_so_far = 1;
            continue;
        }

        if (max_fwd < max_so_far) {
            max_fwd = max_so_far;
        }
    }

    max_so_far = 1;
    for (int i=n-1; i>=0; i--) {
        max_so_far *= arr[i];
        if (max_so_far == 0) {
            max_so_far = 1;
            continue;
        }

        if (max_bwd < max_so_far) {
            max_bwd = max_so_far;
        }
    }

    return max(max(max_fwd, max_bwd), 0);
}


// Kadane technique
int max_product_kadane(int arr[], int n) {
  int max_ending_here = 1;
  int min_ending_here = 1;

  int max_so_far = 1;

  for (int i=0;i<n;i++) {
    
    if (arr[i]>0) {
        max_ending_here *= arr[i];
        min_ending_here = min(min_ending_here*arr[i], 1);
    } else if (arr[i] == 0) {
        max_ending_here = 1;
        min_ending_here = 1;
    } else {

        int tmp = max_ending_here;
        max_ending_here = max(min_ending_here*arr[i], 1);
        min_ending_here = tmp * arr[i];
    }

    if(max_so_far < max_ending_here) {
        max_so_far = max_ending_here;
    }

  }

  return max(max_so_far, 0);

}


int main() {
    //int arr[] = {-2, -3, -10, 1, 1};
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout<<max_product(arr, arr_size)<<endl;
    cout<<max_product_kadane(arr, arr_size)<<endl;
    
    return 0;
}
