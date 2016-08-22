// References:
// 1. http://www.geeksforgeeks.org/maximum-of-all-subarrays-of-size-k/#disqus_thread
// 2. https://www.hackerrank.com/challenges/deque-stl

#include<iostream>
#include<cstdio>
#include<vector>
#include<deque>

using namespace std;

// O(n) Linear time algorithm better than naive O(nk) algorithm
void print_k_max(vector<int> v, int k) {
    deque<int> q;
    for(int i=0; i<v.size(); i++) {
        for(; !q.empty() && v[i] > q.back();) q.pop_back();  
        q.push_back(v[i]);  
        if(i >= k && q.front() == v[i-k]) q.pop_front();  
        if(i >= k-1) printf( i < v.size()-1 ? "%d ":"%d\n", q.front());
    }
}

int main() {
    int t, n, k;
    for(scanf("%d",&t);t--;) {
        scanf("%d%d",&n,&k);
        vector<int> v(n);
        for(int i=0; i<n; i++) scanf("%d",&v[i]);
            print_k_max(v, k);
    }
    return 0;
}
