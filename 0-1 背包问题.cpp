// Gemini 说
// “0 - 1 背包问题”是算法入门里的经典，也是动态规划（Dynamic Programming）的必经之路。

// 简单来说，你是一个小偷，背着一个容量有限的背包（容量为 W）。面前有一堆宝物，每个宝物都有自己的重量（weight）和价值（value）。你的目标是：在不撑破背包的前提下，带走总价值最高的宝物。
//核心规则： 每种物品只有一件，要么装入（1），要么不装（0）。这就是“0 -1”名字的由来。

#include <stdio.h>

// 返回两个整数中的较大值
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main(){
    int n, W;
    printf("please input the total number of goods and backpack");
    scanf("%d %d",&n, &W);

    int weights[n], values[n];
    int dp[W + 1];

    for (int i = 0; i <= W;i++){
        dp[i] = 0;
    }

    printf("Please input the weight and value of each goods");
    for (int i = 0; i < n;i++){
        scanf("%d %d", &weights[i], &values[i]);
    }

    for (int i = 0; i < n;i++){
        for (int j = W; j >= weights[i];j--){
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);

        }
    }
    printf("背包能装下的最大价值为: %d\n", dp[W]);

    return 0;
}

