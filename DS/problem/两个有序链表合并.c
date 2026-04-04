#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define INITSIZE 100
#define FALSE 0
#define TRUE 1

typedef int Elemtype;
typedef struct LNode *PtrToNode;

struct LNode
{
    Elemtype data;
    struct LNode * next;

};
typedef PtrToNode Linklist;

Linklist Read();
void Print(Linklist L);
Linklist Merge(Linklist L1, Linklist L2);


Linklist Read()
{
    Linklist head, tail, temp;
    int x;

    head = (Linklist)malloc(sizeof(struct LNode));
    head->next = NULL;
    tail = head;

    scanf("%d", &x);
    while (x != -1)
    {
        temp = (Linklist)malloc(sizeof(struct LNode));
        temp -> data = x;
        temp -> next = NULL;

        tail -> next = temp;
        tail = temp;

        scanf("%d", &x);
    }
    return head;
}

void Print(Linklist head)
{
    Linklist p = head->next;
    if (p == NULL)
    {
        printf("NULL");
    }
    else
    {
        while (p)
        {
            printf("%d", p->data);
            if (p->next) printf(" ");
            p = p->next;
        }
    }
    printf("\n");
}

Linklist Merge(Linklist L1, Linklist L2)
{
    Linklist head, tail;
    Linklist p1 = L1->next;
    Linklist p2 = L2->next;

    head = (Linklist)malloc(sizeof(struct LNode));
    head -> next = NULL;
    tail = head;

    while (p1 && p2)
    {
        if (p1->data <= p2->data)
        {
            tail->next = p1;
            p1 = p1->next;
        }
        else
        {
            tail->next = p2;
            p2 = p2->next;
        }
        tail = tail->next;
    }
    if (p1)
    {
        tail->next = p1;
    }
    else
    {
        tail->next = p2;
    }
    L1->next = NULL;
    L2->next = NULL;
    return head;
}

int main()
{
    Linklist L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);

    return 0;
}