//
// Created by 方糖 on 2022/8/3.
//
#include "bits/stdc++.h"
using namespace std;

/**
 * 1. 找分界点 mid = (l + r) >> 1
 * 2. 递归左右
 * 3. 合二为一
 */

const int N = 1e6 + 10;
int n, a[N], b[N];

void MergeSort(int q[], int l, int r) {
    if (l >= r) return ;
    int mid = l + r >> 1;
    MergeSort(q, l, mid);
    MergeSort(q, mid + 1 , r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i] <= q[j]) b[k++] = q[i++];
        else b[k++] = q[j++];
    }
    while (i <= mid) b[k++] = q[i++];
    while (j <= r) b[k++] = q[j++];
    for (int i = l, j = 0 ; i <= r ; i++, j++) q[i] = b[j];
}

int main() {

    cin >> n ;
    for (int i = 0 ; i < n ; i++) cin >> a[i];

    MergeSort(a, 0 , n - 1);

    for (int i = 0 ; i < n ; i++) cout << a[i] << " ";

    return 0;
}