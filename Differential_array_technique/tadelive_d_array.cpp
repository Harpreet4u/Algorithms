// http://www.codechef.com/problems/TADELIVE
// Back to Coding 2015 :)
// Differential Array approach.
#include<iostream>
#include <cstdio>
#include<cstring>
#include<cassert>
#include <algorithm>
#include <functional>

using namespace std;

int N, X, Y, res=0;
int bobOrders[100000], andyOrders[100000];

void Init() {
  assert(scanf("%d%d%d", &N, &X, &Y) == 3);
  for (int i = 0; i < N; ++i)
    assert(scanf("%d", bobOrders + i) == 1);
  for (int i = 0; i < N; ++i)
    assert(scanf("%d", andyOrders + i) == 1);
}

void maxTip() {
  for (int i = 0; i < N; ++i) {
    res += bobOrders[i];
    andyOrders[i] -= bobOrders[i];
  }
  std::sort(andyOrders, andyOrders + N, greater<int>());
  for (int i = 0; N - i > X || (i < Y && andyOrders[i] >= 0); ++i)
    res += andyOrders[i];
  printf("%d\n", res);
}

int main() {
    Init();
    maxTip();
  return 0;
}
