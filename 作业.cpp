#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int maxVal;
    int minVal;
    int compareCount;
} Result;

Result findMaxMin(int *arr, int n)
{
    Result res;

    if (n == 0)
    {
        res.maxVal = res.minVal = 0;
        res.compareCount = 0;
        return res;
    }

    res.maxVal = arr[0];
    res.minVal = arr[0];
    res.compareCount = 0;

    for (int i = 1; i < n; i++)
    {
        res.compareCount++; 
        if (arr[i] > res.maxVal)
        {
            res.maxVal = arr[i];
        }

        res.compareCount++;
        if (arr[i] < res.minVal)
        {
            res.minVal = arr[i];
        }
    }

    return res;
}

int* generateRandomArray(int n, int minVal, int maxVal)
{
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        int num = minVal + rand() % (maxVal - minVal + 1);
        arr[i] = num;
    }

    return arr;
}

void printArray(int *arr, int n)
{
    printf("[");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]");
}

int getSimpleMax(int *arr, int n) {
    if (n <= 0) return 0;
    int maxV = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxV) maxV = arr[i];
    }
    return maxV;
}

int getSimpleMin(int *arr, int n) {
    if (n <= 0) return 0;
    int minV = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < minV) minV = arr[i];
    }
    return minV;
}

int main()
{
    srand((unsigned int)time(NULL));

    const int ARRAY_SIZE = 10;   
    const int RANDOM_MIN = 1;    
    const int RANDOM_MAX = 20;   
    const int EXECUTE_TIMES = 10; 

    int totalCompareCount = 0;
    printf("   最大最小元素查找算法 - 比较次数统计\n");
    printf("数组大小: %d\n", ARRAY_SIZE);
    printf("随机数范围: [%d, %d]\n", RANDOM_MIN, RANDOM_MAX);
    printf("执行次数: %d\n", EXECUTE_TIMES);


    for (int test = 1; test <= EXECUTE_TIMES; test++)
    {
        int* arr = generateRandomArray(ARRAY_SIZE, RANDOM_MIN, RANDOM_MAX);

        Result result = findMaxMin(arr, ARRAY_SIZE);

        totalCompareCount += result.compareCount;

        printf("第%d次: ", test);
        printArray(arr, ARRAY_SIZE);
        printf("\n");
        printf("  -> 最大值: %d, 最小值: %d, 比较次数: %d\n", 
               result.maxVal, result.minVal, result.compareCount);
        
        free(arr);
    }

    double avgCompareCount = (double)totalCompareCount / EXECUTE_TIMES;

    printf("统计结果：\n");
    printf("  总比较次数: %d\n", totalCompareCount);
    printf("  平均比较次数: %.2f\n", avgCompareCount);
    printf("  理论比较次数: %d\n", 2 * (ARRAY_SIZE - 1));
    printf("使用简单遍历验证:\n");
    
    int* testArr = generateRandomArray(ARRAY_SIZE, RANDOM_MIN, RANDOM_MAX);
    printArray(testArr, ARRAY_SIZE);
    printf("\n");
    printf("  -> 验证最大值: %d\n", getSimpleMax(testArr, ARRAY_SIZE));
    printf("  -> 验证最小值: %d\n", getSimpleMin(testArr, ARRAY_SIZE));
    free(testArr);

    return 0;
}