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

void printf_root(Node *root){
    printf_root(root->left);
    printf("%d",root->data);
    printf_root(root->right);
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
                //printf_root(root);
				//show_child();
				break;

			case 4:
				//delete_child();
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