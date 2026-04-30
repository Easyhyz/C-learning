#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 全局索引，用于在递归建树时记录读取位置
int index = 0;

// 1. 根据扩展先序序列构建二叉树
TreeNode* buildTree(char *str) {
    // 如果遇到 '#'，表示空节点
    if (str[index] == '#') {
        index++;
        return NULL;
    }
    
    // 创建新节点
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = str[index];
    index++;
    
    // 递归构建左右子树
    node->left = buildTree(str);
    node->right = buildTree(str);
    
    return node;
}

// 2. 层序遍历 (使用数组模拟队列)
void levelOrder(TreeNode *root) {
    if (root == NULL) return;
    
    // 使用数组模拟队列，MAX_SIZE 足够大以防止溢出
    TreeNode *queue[1000];
    int front = 0, rear = 0;
    
    // 根节点入队
    queue[rear++] = root;
    
    while (front < rear) {
        // 出队
        TreeNode *current = queue[front++];
        // 访问节点：打印数据
        printf("%c", current->data);
        
        // 左子树入队
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        // 右子树入队
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

// 释放内存
void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char input[1000];
    // 读取一行输入
    scanf("%s", input);
    
    // 特判空树情况
    if (input[0] == '#') {
        // 空树不输出任何内容
        return 0;
    }
    
    // 重置索引并建树
    index = 0;
    TreeNode *root = buildTree(input);
    
    // 执行层序遍历
    levelOrder(root);
    
    // 释放内存
    freeTree(root);
    
    return 0;
}