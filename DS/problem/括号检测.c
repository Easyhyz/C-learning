#include "global.h"

// 写一个读取输入中的括号的函数----不对，无法判断是否匹配
// 计算左右括号是否匹配，统计数量
// 应该单独判断是否匹配

int isMatch(char str[]);
int blocketLen(char str[]);

int main()
{
    char str[MAXLEN];
    fgets(str, MAXLEN, stdin);
    int len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
        len--;
    }

    int leftCount = 0, rightCount = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c == '(' || c == '[' || c == '{') leftCount++;
        if (c == ')' || c == ']' || c == '}') rightCount++;
    }
    printf("%d %d\n", leftCount, rightCount);
    
    // 判断并输出
    if (isMatch(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;

    return 0;
}

int isMatch(char str[])
{
    char stack[MAXLEN];
    int top = -1;
    char c;

    for (int i = 0; str[i] != '\0'; i++)
    {
        c = str[i];
        if (c == '(' || c == '[' || c == '{')
        {
            stack[++top] = c;
        }
        else if (c == ')' || c == ']' || c == '}')
        {
            if (top == -1) 
            {
                return FALSE;
            }
            char left = stack[top--];
            
            if (left == '(' && c != ')') return FALSE;
            if (left == '[' && c != ']') return FALSE;
            if (left == '{' && c != '}') return FALSE;
        }

    }
    return top == -1;
}