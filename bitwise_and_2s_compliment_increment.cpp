// http://www.geeksforgeeks.org/add-1-to-a-given-number/
#include<iostream>
#include<cstdio>

using namespace std;

int main() {

    int x, m = 1;
    scanf("%d", &x);
    int z = x;
    // increment bit by bit method

    while (x & m) {
        x ^= m;
        m <<= 1;
    }

    x ^= m;
    printf("%d\n", x);

    // 2s compliment method
    z = -(~z);
    printf("2s compliemnt ans: %d\n", z);




    return 0;
}
