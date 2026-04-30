#include "global.h"
// 二进制转十进制，利用栈的方法
// 2的n-1次方

// 结构定义
typedef char Elemtype; // 用char类型防止将栈内的二进制数位作为一整个数值
typedef struct
{
    Elemtype *base;/* data */ // 栈底指针
    Elemtype *top; // 栈顶指针
    int stackSize;
}sqStack;

// 初始化
void InitStack(sqStack *s)
{
    s-> base = (Elemtype *)malloc(INITSIZE * sizeof(Elemtype)); // 动态分配内存
    if (!s->base) // 容易忽略细节
    {
        printf("内存分配失败！");
        exit(0);
    }

    s->top = s->base; // 初始化栈顶指针
    s->stackSize = INITSIZE;
}

// 压栈
void Push(sqStack *s, Elemtype e) // 明确压入栈的地址和要压入的元素
{
    // 要考虑溢出
    if (s->top - s->base >= s->stackSize)
    {
        s->base = (Elemtype *)realloc();
    }
    *(s->top) = e; // 取栈顶的值并赋值
    s->top++; // 更新栈顶指针

}