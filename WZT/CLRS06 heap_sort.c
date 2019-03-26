//堆排序的c语言实现

#include <stdio.h>

void swap(int tree[], int a1, int a2) {
    int temp = tree[a1];
    tree[a1] = tree[a2];
    tree[a2] = temp;
}

//heapify 需在i节点的 所有子树 均为堆的前提下才可进行
void heapify(int tree[], int n, int i) {
    if (i >= n) return;
    int c1 = 2 * i + 1;
    int c2 = 2 * i + 2;
    int max = i;
    if (c1 < n && tree[c1] > tree[max])
        max = c1;
    if (c2 < n && tree[c2] > tree[max])
        max = c2;
    if (max != i) {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
}

void build_heap(int tree[], int n) {
    int par = 0.5 * (n - 1 - 1);
    for (int i = par; i >= 0; i--) {
        heapify(tree, n, i);
    }
}

void heap_sort(int tree[], int n) {
    build_heap(tree, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(tree, i, 0);
        //将最大数放在最后, 随后进行heapify
        heapify(tree, i, 0);
    }
}
int main() {
    int tree[] = {4, 10, 3, 5, 1, 2};
    int n = 6;
    //再次强调! 对于0节点的所有子树, 均满足堆的定义, 才可对0进行heapify
    heapify(tree, n, 0);
    for (int i = 0; i < n; i++) {
        printf("%d\n", tree[i]);
    }
    int tree2[] = {2, 4, 9, 3, 1, 7};
    int tree3[] = {2, 4, 9, 3, 1, 7};
    int n2 = 6, n3 = n2;
    build_heap(tree2, n2);
    for (int i = 0; i < n2; i++) {
        printf("%d\n", tree2[i]);
    }
    heap_sort(tree3, n3);
    for (int i = 0; i < n3; i++) {
        printf("%d\n", tree3[i]);
    }
    return 0;
}