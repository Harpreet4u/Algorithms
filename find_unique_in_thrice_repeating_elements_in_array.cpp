#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int get_single(vector<int> &v) {
    
    int ones = 0;
    int twos = 0;
    int common_bit_mask;

    for (int i=0;i<v.size();i++) {
        twos = twos | (ones & v[i]);
        ones = ones ^ v[i];
        common_bit_mask = ~(ones & twos);
        ones &= common_bit_mask;
        twos &= common_bit_mask;
    }

    return ones;
}

int main() {
    int arr[] = {1, 3, 2, 3, 1, 3, 1};
    
    vector<int> v(arr, arr+7);

    cout<<get_single(v)<<endl;
    return 0;
}
