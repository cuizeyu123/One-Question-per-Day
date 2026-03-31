#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double beans;
    double food;
    double ratio;

} Warehouse;

int compare(const void* a,const void *b){
    Warehouse *w1 = (Warehouse *)a;
    Warehouse *w2 = (Warehouse *)b;
    if (w1->ratio<w2->ratio)
        return 1;
    if (w2->ratio<w1->ratio)
        return -1;
    return 0;
}

int main(){
    double m;
    int n;

    while(scanf("%lf %d",&m,&n) && (m!=-1 || n != -1)){
        Warehouse houses[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &houses[i].beans, &houses[i].food);
            // 计算性价比
            if (houses[i].food > 0)
            {
                houses[i].ratio = houses[i].beans / houses[i].food;
            }
            else
            {
                // 如果猫粮成本为 0，性价比无穷大，直接白给！
                houses[i].ratio = 1e9;
            }
        }

        qsort(houses, n, sizeof(Warehouse), compare);

        double totalBeans = 0.0;

        for (int i = 0; i < n;i++){
            if(m >= houses[i].food){
                totalBeans += houses[i].beans;
                m -= houses[i].food;
            }else{
                totalBeans += houses[i].ratio * m;
                m = 0;
                break;
            }
        
        }

        printf("%.3f\n", totalBeans);
    }

    return 0;
}