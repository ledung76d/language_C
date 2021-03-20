#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
    int data;
    struct _Node *left, *right;
} Node;

Node* BST_root = NULL;

Node* makeNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    return newNode;
}

Node* find(Node* root, int i) {
    if(root == NULL) {
        return NULL;
    }
    else if(root->data == i) {return root;}
    if(find(root->left, i) == NULL) find(root->right, i);
}
/*
int max(int i, int j) {
    return ((i <= j)? j : i);
}
*/
int numOfChild(Node* root) {
    if(root == NULL) return -1;
    return numOfChild(root->left) + numOfChild(root->right) + 2;
}

void insert(Node* root, int i, int j) {
    Node* current = find(root, i);
    if(current == NULL) {
        printf("Khong ton tai i \n");
    }
    else if(current->left == NULL) {
        while(find(BST_root, j) != NULL) {
            printf("Nhap lai gia tri j! \n");
            scanf("%d", &j);
        }
        current->left = makeNode(j);
    }
    else if(current->right == NULL) {
        while(find(BST_root, j) != NULL) {
            printf("Nhap lai gia tri j! \n");
            scanf("%d", &j);
        }
        current->right = makeNode(j);
    }
    else {
        printf("i da co ca 2 con trai phai \n");
    }
}

void enter_root() {
    int d = 0;
    do {
    printf("Gia tri cua Root: \n");
    scanf("%d", &d);
    } while (d < 1 || d > 10);
    BST_root = makeNode(d);
}
void clear (void)
{    
  while ( getchar() != '\n' );
}
void enter_pchild() {
    char option = 'C';
    while (option == 'C') {
        int i, j = 0;
        printf("Gia tri cua (i, j): \n");
        scanf("%d %d", &i, &j);
        insert(BST_root, i, j);
        printf("Tiep tuc? (Yes = C) \n");
        clear();
        scanf("%c", &option);
    }
}

#define MAX 100

typedef struct Q_Node {
    Node* n;
    char pos[20];
    int gen;
} Q_Node;

typedef struct queue
{
	Q_Node* value[MAX];
	int front,rear;
}Queue;


Q_Node* makeqNode(Node* n, char* pos, int gen) {
    Q_Node* qn = (Q_Node*)malloc(sizeof(Q_Node));
    qn->n = n;
    strcpy(qn->pos, pos);
    qn->gen = gen;
}

void enqueue(Queue *q,Q_Node* in)
{
	q->value[++q->rear] = in;
}

Q_Node* dequeue(Queue *q)
{
	return q->value[++q->front];
}

int empty(Queue* q) {
    return q->front == q->rear;
}

void breadth_first(Node* node) {
    char* prev_str = " ";
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = 0;
    if(node != NULL) {
        char* org = "goc";
        enqueue(q,makeqNode(node, org, 0));
        while(!empty(q)) {
            Q_Node* dq = dequeue(q); node = dq->n;
            if(strcmp(prev_str, dq->pos) != 0) {
                printf("\nNut %s ", dq->pos);
                if(dq->gen != 0) printf("%d", dq->gen);
                printf(": ");
            }
            else printf(", ");
            printf("%d",node->data);

            if(node->left != NULL) {
                char* npos = dq->pos;
                int ngen = 0;
                if(strcmp(dq->pos, "goc") == 0) {
                    npos = "con";
                }
                if(strcmp(dq->pos, "con") == 0) {
                    npos = "chau";
                    ngen = dq->gen + 1;
                }
                if(strcmp(dq->pos, "chau") == 0) {
                    npos = "chau";
                    ngen = dq->gen + 1;
                }

                enqueue(q, makeqNode(node->left, npos, ngen));
            }
            if(node->right != NULL) {
                char* npos = dq->pos;
                int ngen = 0;
                if(strcmp(dq->pos, "goc") == 0) {
                    npos = "con";
                }
                if(strcmp(dq->pos, "con") == 0) {
                    npos = "chau";
                    ngen = dq->gen + 1;
                }
                if(strcmp(dq->pos, "chau") == 0) {
                    npos = "chau";
                    ngen = dq->gen + 1;
                }
                enqueue(q, makeqNode(node->right, npos, ngen));
            }
        }
    }
}

void show_child() {
    int i = 0;
    printf("Nhap nut i ma ban muon xem con: \n");
    scanf("%d", &i);
    Node* current = find(BST_root, i);

    if(current != NULL) breadth_first(current);
    else printf("Khong ton tai i \n");
}

void delete(Node* root) {
    if(root == NULL) return;
    delete(root->left);
    delete(root->right);
    free(root);
}

void delete_child() {
    int i = 0;
    printf("Nhap nut i ma ban muon xoa con: \n");
    scanf("%d", &i);
    Node* current = find(BST_root, i);
    if(current == NULL) {
        printf("Khong ton tai i \n");
        return;
    }
    delete(current->left); current->left = NULL;
    delete(current->right); current->right = NULL;
}

void showMenu() {
    int option = 0, value = 0;
	do{
		
		printf("\n====Nhap vao so bat ky de thuc hien chuc nang====\n"
			   "\n1) Nhap vao root (gia tri cua nut goc trong cay)"
			   "\n2) Nhap (i, j) de thiet lap j la nut con cua nut i"
			   "\n3) Hien thi cac nut con/chau cua nut i"
			   "\n4) Nhap i va xoa phan tu con/chau cua i (neu co)"
			   "\n\n5) Thoat.\n\n");

		printf("option: ");
		scanf("%d", &option);
        fflush(stdin);

		switch(option){

			case 5:
                return;

            case 1:
                enter_root();
                break;

			case 2:
				enter_pchild();
				break;

			case 3:
				//show_child();
				break;

			case 4:
				delete_child();
				break;

			default:
				printf("\nINVALID OPTION!!!\n");
				break;

		}

	}while(option != 0);
}
int main() {
    showMenu();
}