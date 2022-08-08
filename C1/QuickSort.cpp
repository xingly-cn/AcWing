//
// Created by 方糖 on 2022/8/3.
//
#include "bits/stdc++.h"
using namespace std;

/**
 * 1.确定分界点x
 * 2.根据 x 将区间分成两部分
 * 3.递归处理两部分
 * */

const int N = 1e6 + 10;
int n, a[N];

void Quick_Sort(int q[], int l, int r) {
    if (l >= r) return ;
    int x = q[l], i = l - 1, j = r + 1;
    while(i < j) {
        do i++; while (q[i] < x);   // 找到第一个大于x的
        do j--; while (q[j] > x);   // 找到第一个小于x的
        if (i < j) swap(q[i], q[j]);    // 未越界交换
    }
    Quick_Sort(q, l, j);
    Quick_Sort(q, j + 1, r);
}

int main() {

    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];

    Quick_Sort(a, 0, n-1);

    for (int i = 0 ; i < n ; i++) cout << a[i] << " ";

    return 0;
}
