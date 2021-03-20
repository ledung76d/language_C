#include <stdio.h>
#include <stdlib.h>
typedef int elementtype;
struct bst
{
    elementtype data;
    struct bst *left;
    struct bst *right;
};
typedef struct bst *node;
node insert(node root, elementtype value)
{
    if(root == NULL)
    {
        node tmp = (node)malloc(sizeof(struct bst));
        tmp->data = value;
        tmp->left = NULL;
        tmp->right = NULL;
        return tmp;
    }
    else
    {
        if(root->data > value)
        {
            root->left = insert(root->left, value);
        }
        if(root->data < value)
        {
            root->right = insert(root->right, value);
        }
    }
    return root;
}
node search(node root, elementtype value)
{
    if(root == NULL)return NULL;
    else if(root->data == value)
    {
        return root;
    }
    else
    {
        if(root->data > value)return search(root->left, value);
        else return search(root->right, value);
    }
}
void xoaHet(node root)
{
    if(root == NULL)
    {
        return;
    }
    xoaHet(root->left);
    xoaHet(root->right);
    free(root);
}
elementtype minNode(node root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
node deleteNode(node root, elementtype value)
{
    if(root == NULL)
    {
        return root;
    }
    if(root->data > value)
    {
        root->left = deleteNode(root->left, value);
    }
    else if(root->data < value)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if(root->left == NULL)
        {
            node tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
        if(root->right == NULL)
        {
            node tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
        root->data = minNode(root->right);
        root->right = deleteNode(root->right, root->data);
    }
    return root;
}
void preOder(node root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOder(root->left);
        preOder(root->right);
    }
}
void inOder(node root)
{
    if(root != NULL)
    {
        inOder(root->left);
        printf("%d ", root->data);
        inOder(root->right);
    }
}
void postOder(node root)
{
    if(root != NULL)
    {
        postOder(root->left);
        postOder(root->right);
        printf("%d ", root->data);
    }
}
//duyệt cây theo chiều rộng
#define Max 100
typedef struct
{
    node root[Max];
    int muc[Max];
    int front;
    int rear;
} Queue;
void makenullqueue(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
int isEmpty(Queue q)
{
    return q.front == -1;
}
int fullqueue(Queue q)
{
    return (q.rear - q.front + 1) == Max;
}
void enqueue(Queue *q, node root,int muc)
{
    if(!fullqueue(*q))
    {
        if(isEmpty(*q))
        {
            q->front = 0;
            q->rear = 0;
        }
        q->root[q->rear] = root;
        q->muc[q->rear] = muc;
        q->rear++;
    }
    else
    {
        printf("Queue is full!\n");
        exit(0);
    }
}
void dequeue(Queue *q)
{
    if(!isEmpty(*q))
    {
        q->front++;
        if(q->front >= q->rear)
        {
            makenullqueue(q);
        }
    }
    else printf("Queue is empty!\n");
}
void duyetcaytheochieurong(node root)
{
    if(root == NULL)return;
    Queue q;
    makenullqueue(&q);
    int muc = 0;
    enqueue(&q, root, muc);
    node root1;
    while(!isEmpty(q))
    {
        root1 = q.root[q.front];
        printf("%d ",root1->data);
        dequeue(&q);
        if(root1->left != NULL)
        {
            enqueue(&q, root1->left,muc);
        }
        if(root1->right != NULL)
        {
            enqueue(&q, root1->right,muc);
        }
    }
}
int main()
{
    node root = NULL;
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 3);
    root = insert(root, 9);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 6);
    root = insert(root, 2);
    root = insert(root, 10);
    root = insert(root, 13);
    printf("duyet thu tu truoc: ");
    preOder(root);
    printf("\n");
    printf("duyet thu tu giua: ");
    inOder(root);
    printf("\n");
    printf("duyet thu tu sau: ");
    postOder(root);
    printf("\n");
    printf("duyet cay theo chieu rong: ");
    duyetcaytheochieurong(root);
    printf("\n");
    printf("%d\n", search(root, 13)->data);
    printf("%d\n", search(root, 2)->data);
    if(search(root, 14) == NULL)printf("null\n");
    xoaHet(search(root, 10)->left);
    search(root, 10)->left = NULL;
    xoaHet(search(root, 10)->right);
    search(root, 10)->right = NULL;
    inOder(root);
    printf("\n");
    root = deleteNode(root, 6);
    inOder(root);
    printf("\n");
    duyetcaytheochieurong(root);
    return 0;
}