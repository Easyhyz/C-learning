#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
typedef struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// 全局索引，用于在递归建树时记录当前读取到字符串的哪个位置
int globalIndex = 0;

// 1. 根据扩展先序序列构建二叉树
TreeNode* buildTree(char *str) {
    // 如果遇到 '#'，表示空节点
    if (str[globalIndex] == '#') {
        globalIndex++; // 消费掉这个字符
        return NULL;
    }
    
    // 创建新节点
    TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = str[globalIndex]; // 当前字符作为节点值
    globalIndex++; // 移动到下一个字符
    
    // 递归构建左子树和右子树
    node->left = buildTree(str);
    node->right = buildTree(str);
    
    return node;
}

// 2. 先序遍历 (根-左-右)
void preorder(TreeNode *root, char *result, int *len) {
    if (root != NULL) {
        result[(*len)++] = root->data;
        preorder(root->left, result, len);
        preorder(root->right, result, len);
    }
}

// 3. 中序遍历 (左-根-右)
void inorder(TreeNode *root, char *result, int *len) {
    if (root != NULL) {
        inorder(root->left, result, len);
        result[(*len)++] = root->data;
        inorder(root->right, result, len);
    }
}

// 4. 后序遍历 (左-右-根)
void postorder(TreeNode *root, char *result, int *len) {
    if (root != NULL) {
        postorder(root->left, result, len);
        postorder(root->right, result, len);
        result[(*len)++] = root->data;
    }
}

// 5. 统计叶子节点数量
int countLeaves(TreeNode *root) {
    if (root == NULL) return 0;
    // 如果左右子树都为空，则是叶子节点
    if (root->left == NULL && root->right == NULL) return 1;
    // 递归统计左右子树的叶子数
    return countLeaves(root->left) + countLeaves(root->right);
}

// 释放内存的函数
void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char input[1000]; // 假设输入字符串长度不超过1000
    scanf("%s", input);
    
    // 特殊情况：如果是空树
    if (input[0] == '#') {
        printf("0\n");
        return 0;
    }
    
    // 重置全局索引并构建二叉树
    globalIndex = 0;
    TreeNode *root = buildTree(input);
    
    // 准备存储遍历结果的数组
    char pre[1000], in[1000], post[1000];
    int preLen = 0, inLen = 0, postLen = 0;
    
    // 执行三种遍历
    preorder(root, pre, &preLen);
    inorder(root, in, &inLen);
    postorder(root, post, &postLen);
    
    // 输出结果
    // 输出先序序列
    for (int i = 0; i < preLen; i++) printf("%c", pre[i]);
    printf("\n");
    
    // 输出中序序列
    for (int i = 0; i < inLen; i++) printf("%c", in[i]);
    printf("\n");
    
    // 输出后序序列
    for (int i = 0; i < postLen; i++) printf("%c", post[i]);
    printf("\n");
    
    // 输出叶子节点数
    printf("%d\n", countLeaves(root));
    
    // 释放动态分配的内存
    freeTree(root);
    
    return 0;
}