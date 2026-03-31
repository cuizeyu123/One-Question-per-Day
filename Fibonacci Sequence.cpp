//
// Created by q2015 on 25-6-14.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

int fib(int n) {
    if (n<=0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;
    return fib(n-1)+fib(n-2);
}
int fib_iter(int n) {
    if (n<=0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;
    int a = 1,b = 2,c = 0;
    for (int i=3;i<=n;i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
void print_fibonacci(int n) {
    if (n <= 0) {
        cout << "请输入正整数。" << endl;
        return;
    }
    long long a = 1, b = 2;  // 题目中前两项设为 1, 2
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << a << " ";
        } else if (i == 2) {
            cout << b << " ";
        } else {
            long long c = a + b;
            cout << c << " ";
            a = b;
            b = c;
        }
    }
    cout << endl;
}

vector<long long> generate_fibonacci(int n) {
    vector<long long> fib;

    if (n >= 1) fib.push_back(1);
    if (n >= 2) fib.push_back(2);
    for (int i = 2;i < n;++i) {
        fib.push_back(fib[i-1]+fib[i-2]);
    }

    return fib;
}

void write_fibonacci(const vector<long long>& fib,const string& filename) {
    ofstream file(filename);
    file << "Index,Fibonacci,Even,Ratio_to_Previous\n";
    for (size_t i=0;i<fib.size();++i) {
        file << i+1<<","<<fib[i]<<",";
        file << (fib[i]%2==0 ? "yes" : "no") << ",";

        if (i >= 1) {
            double ratio = static_cast<double>(fib[i]) / fib[i - 1];
            file << fixed << setprecision(8) << ratio;
        } else {
            file << "-";
        }

        file << "\n";
    }

    file.close();
    cout << "已将结果写入文件: " << filename << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "fib(" << n << ") = " << fib(n) << endl;
    print_fibonacci(n);
    return 0;
}