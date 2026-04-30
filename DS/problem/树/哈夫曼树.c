#include <stdio.h>

#define MAXN 25

int heap[MAXN];
int heapSize = 0;

// 向下调整堆（小顶堆）
void siftDown(int i) {
    int minPos = i;
    while (1) {
        if (i * 2 <= heapSize && heap[i * 2] < heap[minPos]) minPos = i * 2;
        if (i * 2 + 1 <= heapSize && heap[i * 2 + 1] < heap[minPos]) minPos = i * 2 + 1;
        if (minPos == i) break;
        int temp = heap[i];
        heap[i] = heap[minPos];
        heap[minPos] = temp;
        i = minPos;
    }
}

// 向上调整堆
void siftUp(int i) {
    while (i > 1 && heap[i] < heap[i / 2]) {
        int temp = heap[i];
        heap[i] = heap[i / 2];
        heap[i / 2] = temp;
        i /= 2;
    }
}

// 插入元素
void push(int x) {
    heap[++heapSize] = x;
    siftUp(heapSize);
}

// 弹出堆顶
int pop() {
    int result = heap[1];
    heap[1] = heap[heapSize--];
    siftDown(1);
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 初始化堆（堆从下标1开始）
    heapSize = 0;
    
    for (int i = 0; i < n; i++) {
        int w;
        scanf("%d", &w);
        push(w);
    }
    
    int wpl = 0;
    // 合并 n-1 次
    for (int i = 0; i < n - 1; i++) {
        int a = pop();
        int b = pop();
        int sum = a + b;
        wpl += sum;
        push(sum);
    }
    
    printf("%d\n", wpl);
    return 0;
}