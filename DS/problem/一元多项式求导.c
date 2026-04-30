#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INITSIZE 100

typedef int Elemtype;
struct Term;

struct Term // 多项式的项
{
    int coef;
    int exp;
}terms[1000], results[1000];



int main()
{
    int n = 0;
    while (scanf("%d %d", &terms[n].coef, &terms[n].exp) == 2)
    {
        if (terms[n].coef == 0 || terms[n].exp == 0) // 系数与指数为零时结束
        {
            break;
        }
        n++;
    }

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        results[m].coef = terms[m].coef * terms[m].exp;
        results[m].exp = terms[m].exp - 1;
        m++;
    }
    if (m == 0)
    {
        printf("0 0");
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d %d", results[i].coef, results[i].exp);
            if (i < m-1) printf(" ");
        }
        
    }

    return 0;
}