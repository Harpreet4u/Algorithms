#include<iostream>
#include<cstdio>

using namespace std;

int max_sub_array_sum(int arr[], int n) {

    int max_ending_here = 0;
    int max_so_far = 0;

    for (int i=0;i<n;i++) {
        max_ending_here = max(arr[i], max_ending_here+arr[i]);
        max_so_far = max(max_ending_here, max_so_far);
    }

    return max_so_far;
}


int main() {
    int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = max_sub_array_sum(a, n);
    cout << "Maximum contiguous sum is " << max_sum << endl;
    return 0;
}
