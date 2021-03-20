#include <stdio.h>
#include <stdlib.h>
typedef int elementtype; //Chọn kiểu dữ liệu
struct linkedlist
{
    elementtype data;
    struct linkedlist *next;
};
typedef struct linkedlist *node;
node creatNode(elementtype value) //Tạo node
{
    node tmp;
    tmp = (node)malloc(sizeof(struct linkedlist));
    tmp->data = value;
    tmp->next = NULL;
    return tmp;
}
node addHead(node head, elementtype value)//Thêm vào đầu
{
    if(head == NULL)
    {
        head = creatNode(value);
    }
    else
    {
        node tmp = creatNode(value);
        tmp->next = head;
        head = tmp;
    }
    return head;
}
node addTail(node head, elementtype value)//Thêm vào cuối
{
    if(head == NULL)
    {
        head = creatNode(value);
    }
    else
    {
        node tmp = head;
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = creatNode(value);
    }
    return head;
}
node insert(node head, elementtype value, int index)//Chèn vào vị trí index
{
    if(index == 0 || head == NULL)
    {
        head = creatNode(value);
    }
    else
    {
        node tmp = head;
        while(head->next != NULL && index != 1)
        {
            index--;
            tmp = tmp->next;
        }
        node tmp1 = creatNode(value);
        tmp1->next = tmp->next;
        tmp->next = tmp1;
    }
    return head;
}
node delHead(node head)//Xóa node đầu
{
    if(head == NULL)
    {
        printf("Khong co gi de xoa het!\n");
    }
    else
    {
        node tmp = head;
        head = head->next;
        free(tmp);
    }
    return head;
}
node delTail(node head)//Xóa node cuối
{
    node tmp = head;
    while(tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    node tmp1 = tmp->next;
    tmp->next = NULL;
    free(tmp1);
    return head;
}
node delnode(node head, int index)//Xóa node ở vị trí index
{
    if(index == 0 || head == NULL)
    {
        head = delHead(head);
    }
    else
    {
        node tmp = head;
        while(tmp->next->next != NULL && index != 1)
        {
            index--;
            tmp = tmp->next;
        }
        if(index != 1)
        {
            head = delTail(head);
        }
        else
        {
            node tmp1 = tmp->next;
            tmp->next = tmp->next->next;
            free(tmp1);
        }
    }
    return head;
}
elementtype getNode(node head, int index)//Trả về giá trị của node ở vị trí index
{
    while(head->next != NULL && index != 0)
    {
        index--;
        head = head->next;
    }
    return head->data;
}
node Search(node head, elementtype value)//Trả về node có giá trị value
{
    node tmp = head;
    while(tmp->next != NULL && tmp->data != value)
    {
        tmp = tmp->next;
    }
    if(tmp->data == value)return tmp;
    else return NULL;
}
void printList(node head)//In danh sách
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}
void sortLinkedList(node head)// Sắp xếp danh sách
{
    node tmp, tmp1;
    elementtype a;
    while(head->next != NULL)
    {
        tmp = head;
        tmp1 = head->next;
        while(tmp1 != NULL)
        {
            if(tmp->data > tmp1->data)
            {
                a = tmp->data;
                tmp->data = tmp1->data;
                tmp1->data = a;
            }
            tmp1 = tmp1->next;
        }
        head = head->next;
    }
}
int main()
{
    node head = NULL;
    head = addTail(head, 1);
    head = addTail(head, 3);
    head = addHead(head, 5);
    head = addTail(head, 2);
    printList(head);
    sortLinkedList(head);
    printf("\n");
    printList(head);
    head = insert(head, 0, 1);
    printf("\n");
    printList(head);
    head = delHead(head);
    printf("\n");
    printList(head);
    head = delTail(head);
    printf("\n");
    printList(head);
    head = delnode(head, 1);
    printf("\n");
    printList(head);
    node head1 = Search(head, 3);
    head1->next = creatNode(9);
    printf("\n");
    printList(head);
    printf("\n---%d---\n", getNode(head, 0));
    return 0;
}
