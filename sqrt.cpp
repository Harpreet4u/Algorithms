#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
    int n;
    cin>>n;

    int method;
    cin>>method;

    if (method == 1) {
      double x0 = 1;
      double x1;

      // https://en.wikipedia.org/wiki/Methods_of_computing_square_roots
      // newton's method..
      while (1) {
          x1 = (x0 + n/x0)/2;
          if (abs(x1-x0)<1) { 
            cout<<(int)x1<<endl;
            return 0;
          }
          x0 = x1;
      }
    } else {

      // Binary search method
      long long high = (n/2) + 1;
      long long low = 0;

      if (n == 0) return 0;
      if (n == 1) return 1;
      long long mid;

      while (high-low>1) {
          mid = low + (high - low)/2;
          if (mid*mid<=n) low = mid;
          else high = mid;
      }

      cout<<low<<endl;
    }

    return 0;
}
