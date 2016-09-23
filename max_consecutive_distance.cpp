#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

int maxGap(const vector<int> &A) {

    int n = A.size();
    vector<int> v1(n, -1); // min vector
    vector<int> v2(n, -1); // max vector

    if (n<2)
      return 0;

    int max_=A[0], min_=A[0];
    // Step 1: fetch min and max in array
    for (int i=0;i<n;i++) {
        max_ = max(max_, A[i]);
        min_ = min(min_, A[i]);
    }

    int gap = max_ - min_;
    // each bucket size
    gap = gap/(n-1);
    // base case
    if (gap==0)
      return max_-min_;

    int bucket;

    // Step 2: insert element to buckets
    for (int i=0;i<n;i++) {
        bucket = (int)(A[i]-min_)/gap;
        if (v1[bucket]<0) {
            v1[bucket]=A[i];
            v2[bucket]=A[i];
        } else {
            v1[bucket] = min(v1[bucket], A[i]);
            v2[bucket] = max(v2[bucket], A[i]);
        }
    }

    int max_dif = 0, prev = 0;
    // Step 3: Calcuate max diff from consecutive buckets
    for (int i=0;i<n;i++) {

        if (v1[i]>=0) {
            // current bucket min - previous bucket max.
            max_dif = max(max_dif, v1[i] - v2[prev]);
            prev = i;
        }
    }

    return max_dif;
}

int main() {
    int n, tmp;
    vector<int> v;
    cin>>n;
    while(n--) {
        cin>>tmp;
        v.push_back(tmp);
    }

    cout<<maxGap(v)<<endl;
    return 0;
}
