// http://www.codechef.com/problems/TADELIVE
// Back to Coding 2015 :)
// Forward Dynamic Programming approach.
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, X, Y, res=0, memo[5010][5010];
int bobOrders[50000], andyOrders[50000];

int maxTip(int curOrder, int bobOrdersTillNow)
{
    // Memoization.
    if (memo[curOrder][bobOrdersTillNow] != -1)
        return memo[curOrder][bobOrdersTillNow];

    int curTip = 0;
    // Base case.
    if (curOrder == N)
        return 0;
    else
    {
        if ((bobOrdersTillNow + 1) <= X)
            curTip = max(curTip, bobOrders[curOrder] + maxTip(curOrder+1, bobOrdersTillNow+1));

        if (((curOrder - bobOrdersTillNow)+1) <= Y)
            curTip = max(curTip, andyOrders[curOrder] + maxTip(curOrder+1, bobOrdersTillNow));
    }
    memo[curOrder][bobOrdersTillNow] = curTip;
    return curTip;
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
    for (int i=0; i<(N+1); i++)
        for (int j=0; j<(max(X, Y)+1); j++)
            memo[i][j] = -1;
    res = maxTip(0, 0);
    printf("%d\n", res);
    return 0;
}
