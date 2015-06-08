// http://www.codechef.com/problems/TADELIVE
// Back to Coding 2015 :)
// Brute force approach.
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, X, Y, res=0;
int bobOrders[10000], andyOrders[10000];

void maxTip(int curOrder, int andy, int bob, int tipMoney)
{
    if(curOrder == N)
    {
        if (andy <= Y && bob <= X)
            res = max(res, tipMoney);
    }
    else
    {
        maxTip(curOrder + 1, andy, bob + 1, tipMoney + bobOrders[curOrder]);
        maxTip(curOrder + 1, andy + 1, bob, tipMoney + andyOrders[curOrder]);
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
    maxTip(0, 0, 0, 0);
    printf("%d\n", res);
    return 0;
}
