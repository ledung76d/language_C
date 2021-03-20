#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char elementtype;
struct binarysearchtree
{
    elementtype ta[100];
    elementtype tv[100];
    struct binarysearchtree *left;
    struct binarysearchtree *right;
};
typedef struct binarysearchtree *node;
node root = NULL;
void xoadaucach(char *s)
{
	int i;
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == '_')
        {
            s[i] = ' ';
        }
    }
}
node insert(node root, char *s, char *s1)
{
    if(root == NULL)
    {
        root = (node)malloc(sizeof(struct binarysearchtree));
        strcpy(root->ta, s);
        xoadaucach(s1);
        strcpy(root->tv, s1);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(root->ta[0] > s[0])
    {
        root->left = insert(root->left, s, s1);
    }
    else
    {
        root->right = insert(root->right, s, s1);
    }
    return root;
}
node search(node root, char *s)
{
    if(root == NULL)return;
    else if(strcmp(root->ta, s) == 0)
    {
        return root;
    }
    else
    {
        if(root->ta[0] > s[0])return search(root->left, s);
        else return search(root->right, s);
    }
}
void xoacay(node root)
{
    if(root == NULL)return;
    xoacay(root->left);
    return xoacay(root->right);
    free(root);
}
void clearBuffer()
{
    char c;
    c = getchar();
}
void swapString(char *s1, char *s2)
{
    char tmp[100];
    strcpy(tmp, s1);
    strcpy(s1, s2);
    strcpy(s2, tmp);
}
void swapNumber(double *a, double *b)
{
    double c = *a;
    *a = *b;
    *b = c;
}
void duyetcaythutugiua(node root)
{
    if(root != NULL)
    {
        duyetcaythutugiua(root->left);
        printf("%s: %s\n", root->ta, root->tv);
        duyetcaythutugiua(root->right);
    }
}
void case1()
{
    FILE *fp = fopen("dich.txt", "r");
    char ta[100], tv[100];
    if(fp == NULL)
    {
        printf("Co loi khi mo file!\n");
        exit(0);
    }
    else
    {
        while(fscanf(fp, "%s %s", ta, tv) != EOF)
        {
            printf("%s %s\n", ta, tv);
            root = insert(root, ta, tv);
        }
    }
    fclose(fp);
}
void case2()
{
    duyetcaythutugiua(root);
}
void case3()
{
    char sta[100];
    char stv[100];
    printf("Nhap vao mot tu tieng Anh: ");
    gets(sta);
    node tmp = search(root, sta);
    if(tmp != NULL)
    {
        printf("Co muon nhap noi dung moi cho muc tu hay khong (y/n)? ");
        char check;
        scanf("%c", &check);
        if(check == 'y')
        {
            printf("Nhap noi dung moi moi: ");
            gets(stv);
            strcpy(tmp->tv, stv);
        }

    }
    else
    {
        printf("Nhap nghia cua tu: ");
        gets(stv);
        root = insert(root, sta, stv);
    }
}
void case4()
{
    printf("Nhap vao mot cau chi gom tieng Anh: ");
    char cta[100];
    char ata[100][100];
    int i;
    gets(cta);
    strcat(cta, " ");
    for(i = 0; i < strlen(cta); i++)
    {
        if(cta[i] >= 'A' && cta[i] <= 'Z')cta[i] += 32;
    }
    int j = 0,k = 0;
    for(i = 0; i < strlen(cta); i++)
    {
        if(cta[i] == ' ')
        {
            strncpy(ata[k], &cta[j], i - j);
            ata[k][i-j] = '\0';
            j = i + 1;
            k++;
        }
    }
    for(i = 0; i < k; i++)
    {
        printf("%s\n", ata[i]);
    }
    for(i = 0; i < k; i++)
    {
        if(search(root, ata[i]) != NULL)
        {
            printf("%s ", search(root, ata[i])->tv);
        }
        else
        {
            printf("<thieu tu> ");
        }
    }
}
int n = 0;
char fta[100][100];
char ftv[100][100];
void deocoten(char *s)
{
	int i;
    for(i = 0; i< strlen(s); i++)
    {
        if(s[i] == ' ')
        {
            s[i] = '_';
        }
    }
}
void duyetcaythututruoc(node root)
{
    if(root != NULL)
    {
        strcpy(fta[n], root->ta);
        strcpy(ftv[n], root->tv);
        deocoten(ftv[n]);
        n++;
        duyetcaythututruoc(root->left);
        duyetcaythututruoc(root->right);
    }
}
void case5()
{
	int i;
    FILE *fp1 = fopen("dict.txt", "w");
    duyetcaythututruoc(root);
    for(i = 0; i < n; i++)
    {
        fprintf(fp1,"%s %s\n", fta[i], ftv[i]);
    }
    fclose(fp1);
}
void menu()
{
    while(1)
    {
        printf("\n---MENU---\n");
        printf("1. Nap tu dien\n");
        printf("2. Noi dung tu dien\n");
        printf("3. Them sua tu\n");
        printf("4. Dich cau Anh-Viet\n");
        printf("5. Luu file tu dien\n");
        printf("6. Thoat\n");
        printf("Ban chon: ");
        int x;
        scanf("%d", &x);
        clearBuffer();
        switch(x)
        {
        case 1:
            case1();
            break;
        case 2:
            case2();
            break;
        case 3:
            case3();
            break;
        case 4:
            case4();
            break;
        case 5:
            case5();
            break;
        case 6:
            xoacay(root);
            exit(0);
        }
    }
}

int main()
{
    menu();
    return 0;
}
