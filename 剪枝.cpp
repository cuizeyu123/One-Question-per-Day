#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* path[100];
int pathSize = 0;
int res[100][100];
int resSize = 0;

void preOrder(TreeNode *root){
    if (root ==NULL || root -> val == 3){
        return;
    }

    path[pathSize++] = root;

    if(root ->val == 7){
        for (int i = 0; i < pathSize;i++){
            res[resSize][i] = path[i] -> val;
        }
        resSize++;
    }
    preOrder(root -> left);
    preOrder(root -> right);
    pathSize--;
}

TreeNode *createNode(int val)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printResult()
{
    printf("找到的路径:\n");

    for (int i = 0; i < resSize; i++)
    {
        printf("path %d: ", i + 1);

        int j = 0;

        /* 因为不知道每条路径长度，只能打印到7 */
        while (1)
        {
            printf("%d ", res[i][j]);

            if (res[i][j] == 7)
            {
                break;
            }

            j++;
        }

        printf("\n");
    }
}

int main()
{

    /*
            1
          /   \
         2     3
        / \
       4   5
          / \
         6   7

    注意：
    val == 3 会直接 return
    val == 7 时保存路径
    */

    TreeNode *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->left->right->left = createNode(6);
    root->left->right->right = createNode(7);

    preOrder(root);

    printResult();

    return 0;
}