#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 定义栈的最大大小
#define MAXSIZE 100

// 全局变量：栈和栈顶指针
char stack[MAXSIZE];
int top = -1;

// 函数声明
void push(char c);
char pop();
char getTop();
int isEmpty();
int getPriority(char op); // 获取运算符优先级

int main() {
    char infix[21]; // 输入的中缀表达式，题目说不超过20个字符
    char postfix[21]; // 输出的后缀表达式
    int pIndex = 0;  // 后缀表达式索引

    // 读取输入
    scanf("%s", infix);

    // 遍历中缀表达式
    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // 1. 如果是数字，直接加入结果
        if (c >= '0' && c <= '9') {
            postfix[pIndex++] = c;
        }
        // 2. 如果是左括号，直接入栈
        else if (c == '(') {
            push(c);
        }
        // 3. 如果是右括号
        else if (c == ')') {
            // 持续弹出直到遇到左括号
            while (getTop() != '(') {
                postfix[pIndex++] = pop();
            }
            pop(); // 弹出 '(' 并丢弃
        }
        // 4. 如果是运算符 (+, -, *, /)
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            // 栈不为空，且栈顶不是左括号，且栈顶运算符优先级 >= 当前运算符
            while (!isEmpty() && getTop() != '(' && 
                   getPriority(getTop()) >= getPriority(c)) {
                postfix[pIndex++] = pop(); // 弹出栈顶运算符
            }
            push(c); // 当前运算符入栈
        }
    }

    // 5. 将栈中剩余的运算符全部弹出
    while (!isEmpty()) {
        postfix[pIndex++] = pop();
    }

    // 输出结果
    postfix[pIndex] = '\0'; // 字符串结束符
    printf("%s", postfix);

    return 0;
}

// --- 栈操作函数实现 ---

void push(char c) {
    if (top < MAXSIZE - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // 栈空返回空字符
}

char getTop() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isEmpty() {
    return top == -1;
}

// --- 优先级函数 ---
// 返回运算符的优先级，数字越大优先级越高
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/') {
        return 2;
    }
    return 0; // 其他情况（如括号处理时）
}