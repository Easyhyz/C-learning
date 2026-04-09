#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int front, rear;
}SeqQueue;
InitQueue(SeqQueue *Q);//初始化空队列
EnQueue(SeqQueue *Q, ElemType e);//进队
DeQueue(SeqQueue *Q, ElemType *e);//出队
GetHead(SeqQueue Q, ElemType *e);//取队头元素

void YangHui(int n)

{
    
    SeqQueue Q;
    
    InitQueue(&Q);
    
    EnQueue(&Q, 1);//第1行数字进队
    
    int i, j, k, temp, x;
    
    for(i=2; i<=n; i++)//打印前n-1行
        
    {
        
        for(k=1; k<=n-i+1; k++)//打印第i行的前导空格
            
            printf("  ");//两个空格
        
        EnQueue(&Q, 1);//第i行第一个数字进队
        
        for(j=1; j<=i-2; j++)//第i-1行数字出队并打印，同时生成第i行中间的i-2个数并进队
            
        {
            
            DeQueue(&Q, &temp);//第i-1行数字出队
            
            printf("%4d", temp);//每个数字占4格
            
            GetHead(Q, &x);
            
            EnQueue(&Q, temp+x);//生成第i行数字并进队
            
        }
        
        DeQueue(&Q, &temp);//第i-1行最后一个数字出队
        
        printf("%4d\n", temp);
        
        EnQueue(&Q, 1);//第i行最后一个数字进队
        
    }
    
//打印队列中的第n行数字
    
    for(i=1; i<=n; i++)
        
    {
        
        DeQueue(&Q, &temp);
        
        printf("%4d", temp);
        
    }
    
    printf("\n");
    
}

int main()
{
    
    int n;
    
    scanf("%d", &n);//输入打印的行数
    
    YangHui(n);//打印杨辉三角
    
    return 0;
}

void initQueue(SeqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
}

int EnQueue(SeqQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        return 0;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;

    return 1;
}