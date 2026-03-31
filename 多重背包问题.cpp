#include <stdio.h>
#include <string.h>

#define MAX_W 1000
#define MAX_N 100

int max(int a,int b){
    return (a > b) ? a : b;
}

int main(){
    int n, w;

    n = 2;
    w = 10;

    int weights[] = {1, 2};
    int values[] = {5, 10};
    int counts[] = {7, 2};

    int dp[MAX_W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n;i++){
        int num = counts[i];

        for (int k = 1; num > 0;k<<=1){
            int take = (k < num) ? k : num;
            int cur_w = take * weights[i];
            int cur_v = take * values[i];

            for (int j = w; j >= cur_w;j--){
                dp[j] = max(dp[j], dp[j - cur_w] + cur_v);
            }

            num -= take;
        }
    }
    printf("the maximun achievable value within the knapsack capacity: %d", dp[w]);
    return 0;
}

