#include <stdio.h>
#include <stdlib.h>
typedef int KeyType; // Loại dữ liệu của Key
typedef struct Node
{
    KeyType key;
    struct Node *left;
    struct Node *right;
} NodeType;
typedef struct Node *TreeType;
//Tìm kiếm trên BST
TreeType Search(KeyType x, TreeType Root)
{
    if (Root == NULL)
        return NULL;         // not found
    else if (Root->key == x) /* found x */
        return Root;
    else if (Root->key < x)
        //continue searching in the right sub tree
        return Search(x, Root->right);
    else
    {
        // continue searching in the left sub tree
        return Search(x, Root->left);
    }
}
/*Insert a node from a BST

• Lưu ý: Trong BST, không có 2 nút nào có cùng key
*/

void InsertNode(KeyType x, TreeType *Root)
{
    if (*Root == NULL)
    {
        /* Create a new node for key x */
        *Root = (NodeType *)malloc(sizeof(NodeType));
        (*Root)->key = x;
        (*Root)->left = NULL;
        (*Root)->right = NULL;
    }
    else if (x < (*Root)->key)
        InsertNode(x, &(*Root)->left);
    else if (x > (*Root)->key)
        InsertNode(x, &(*Root)->right);
}
//Xoa toan bo nut trong cay
void freetree(TreeType tree)
{
    if (tree != NULL)
    {
        freetree(tree->left);
        freetree(tree->right);
        free((void *)tree);
    }
}