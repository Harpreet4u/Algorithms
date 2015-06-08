#include<iostream>
#include<cstdio>

using namespace std;

int main() {
    /* Psuedo Code:
    **start
    **    N; //an integer
    **    X = N
    **    while true
    **        print X
    **        if( X == 0 )
    **            break;
    **        X = (X-1) & N;
    **    end while
    **end
    */
    int N = 22; // 10110
    int X = N;
    while (1) {
        cout << X << "\n";
        if (X == 0)
            break;
        X = (X - 1) & N;
    }
    /* Output:
    ** 22 10110
    ** 20 10100
    ** 18 10010
    ** 16 10000
    ** 6  00110
    ** 4  00100
    ** 2  00010
    ** 0  0000
    */
    return 0;
}
