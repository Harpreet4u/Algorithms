// http://www.codechef.com/problems/TADELIVE
// Back to Coding 2015 :)
// Brute force with bitmasks.
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, X, Y, res=0;
int bobOrders[10000], andyOrders[10000];

void maxTip()
{
    for (int i=0; i < 1<<N; i++)
    {
        int curTip = 0, bob = 0, andy = 0;
        for (int j=0; j<N; j++)
        {
            if (i&1<<j)
            {
                curTip += bobOrders[j];
                bob += 1;
            }
            else
            {
                curTip += andyOrders[j];
                andy += 1;
            }
        }
        if (bob <= X && andy <= Y)
            res = max(res, curTip);
    }
}

int main()
{
    scanf("%d %d %d", &N, &X, &Y);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &bobOrders[i]);
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d", &andyOrders[i]);
    }
    maxTip();
    printf("%d\n", res);
    return 0;
}
