#include <iostream>
#include <queue>
#include <vector>

void removeKth(std::queue<int>& qu, int k) {
    int n = qu.size();
    if (k < 1 || k > n) {
        std::cout << "Invalid k" << std::endl;
        return;
    }

    for (int i = 0; i < k - 1; ++i) {
        int val = qu.front();
        qu.pop();
        qu.push(val);
    }

    qu.pop();

    for (int i = 0; i < n - k; ++i) {
        int val = qu.front();
        qu.pop();
        qu.push(val);
    }
}
/*
 时间复杂度分析：
 该算法主要由两个循环组成。
 第一个循环执行 k-1 次出队和入队操作。
 中间执行一次出队操作。
 第二个循环执行 n-k 次出队和入队操作。
 总的操作次数为 (k-1) + 1 + (n-k) = n 次。
 因为队列的出队（pop）、入队（push）和取队头元素（front）操作的时间复杂度均为 O(1)，
 所以整个算法的时间复杂度为 O(n)，其中 n 为队列中的元素个数。
 */

void printQueue(std::queue<int> qu) {
    while (!qu.empty()) {
        std::cout << qu.front() << " ";
        qu.pop();
    }
    std::cout << std::endl;
}

int main() {
    int a[] = {5, 2, 8, 4, 3, 6, 9, 7, 1, 10};
    int n = 10;
    int k = 3;

    std::queue<int> qu;
    for (int i = 0; i < n; ++i) {
        qu.push(a[i]);
    }

    std::cout << "初始队列: ";
    printQueue(qu);

    std::cout << "删除第 " << k << " 个元素 (" << a[k-1] << ")..." << std::endl;
    removeKth(qu, k);

    std::cout << "结果队列: ";
    printQueue(qu);

    return 0;
}
