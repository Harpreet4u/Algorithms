// http://www.codechef.com/problems/TADELIVE
// Back to Coding 2015 :)
// Backward Dynamic Programming approach.
#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N, X, Y, res=0, memo[5010][5010];
int bobOrders[50000], andyOrders[50000];

int maxTip()
{
    for (int i=1; i<=N; i++)
    {
        for (int j=1; j<=X && j<=i ; j++)
        {
            int x = 0;
            if (j <= X)
                x = memo[i-1][j-1] + bobOrders[i];

            int y = 0;
            if ((i-j) <= Y)
                y = memo[i-1][j] + andyOrders[i];

            memo[i][j] = max(x, y);
        }
    }
    for (int i=0; i<=X; i++)
        res = max(res, memo[N][i]);
    return res;
}

int main()
{
    scanf("%d %d %d", &N, &X, &Y);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &bobOrders[i]);
    }
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &andyOrders[i]);
    }
    memset(memo, 0, sizeof(memo));
    res = maxTip();
    printf("%d\n", res);
    return 0;
}
