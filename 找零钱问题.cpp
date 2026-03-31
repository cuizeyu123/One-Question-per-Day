#include<stdio.h>
#define INF 10000


int main(){
    int coins[] = {1, 2, 5};
    int coins_count = 3;
    int amount = 6;
    int dp[amount + 1];

    dp[0] = 0;
    for (int i = 1; i <= amount;i++){
        dp[i] = INF;
    }

    for (int i = 0; i < coins_count;i++){
        for (int j = coins[i]; j <= amount;j++){
            if()
        }
    }
}