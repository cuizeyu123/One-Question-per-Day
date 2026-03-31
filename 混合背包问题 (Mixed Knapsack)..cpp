// 混合背包问题(Mixed Knapsack)
// 其实是背包问题的大圆满结局。
// 它并没有新的核心状态转移方程，而是考察你对前三种背包（0 - 1、完全、多重）的遍历顺序和拆分逻辑的掌握程度。
#include <stdio.h>
#include <string.h>

#define MAX_W 1000

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void zeroOnePack(int dp[],int w,int v,int W){
    for (int j = w; j >= W;j--){
        dp[j] = max(dp[j], dp[j - w] + v);
    }
}

void completePack(int dp[],int w, int v, int W){
    for (int j = w; j <= W;j++){
        dp[j] = max(dp[j], dp[j - w] + v);
    }
}

int main(){
    int n = 3;
    int W = 15;
    int dp[MAX_W + 1] = {0};

    int weights[] = {2, 3, 2};
    int values[] = {5, 8, 4};
    int types[] = {0, -1, 5};

    for (int i = 0; i < n; i++)
    {
        if (types[i] == 0)
        {

            zeroOnePack(dp, weights[i], values[i], W);
            printf("物品 %d (0-1) 已处理\n", i);
        }
        else if (types[i] == -1)
        {

            completePack(dp, weights[i], values[i], W);
            printf("物品 %d (完全) 已处理\n", i);
        }
        else
        {
            int num = types[i];
            for (int k = 1; num > 0; k <<= 1)
            {
                int take = (k < num) ? k : num;
                zeroOnePack(dp, take * weights[i], take * values[i], W);
                num -= take;
            }
            printf("物品 %d (多重) 已处理\n", i);
        }
    }
    printf("混合背包最大价值: %d\n", dp[W]);
    return 0;
}