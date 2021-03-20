#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *next;
};
typedef struct node* node_ptr;

//Khoi tao hang doi 
node_ptr front= NULL;   //phan tu dau hang doi
node_ptr rear=NULL;     //phan tu cuoi hang doi

//Kiem tra queue rong
bool is_emty(){
    return (front == NULL);
}

//Tham phan tu vao hang doi
bool enqueue(int value){
    node_ptr tmp=(node_ptr)malloc(sizeof(struct node));
    if(tmp==NULL)
        return false;
    
    tmp->data=value;
    tmp->next=NULL;
    if(rear==NULL)
        front=rear=tmp;
    else
    {
        rear->next=tmp;
        rear=tmp;
    }
    return true;
    
}
//xoa bo phan tu dau tien 
bool dequeue(int *value){
    if(is_emty()){
        printf("\nThe queue is empty\n");
        return false;
    }
    node_ptr tmp=front;
    *value=front->data;
    front=front->next;
    free(tmp);
    return true;
}
//in hang doi
void display(){
    if(is_emty()){
        printf("\nThe queue is empty!\n");
        return;
    }
    node_ptr tmp=front;
    printf("\n[front -> ");

	while(tmp != NULL){
		printf("[%d]", tmp->data);
		tmp = tmp->next;
	}

	printf(" <- rear]\n");
}
//Dem so phan tu trong queue
int dem(){
    node_ptr tmp=front;
    int value=0;
	while(tmp != NULL){
		value++;
		tmp = tmp->next;
	}
    return value;
}

//Xoa queue
bool clear(){
    if(is_emty()){
        printf("\nThe queue is empty!\n");
        return false;
    }
    node_ptr current=front;
    node_ptr previous=NULL;
    while (current!=NULL)
    {
        previous=current->next;
        free(current);
        current=previous;
    }
    front=NULL;
    return is_emty();
    
}
int main(){
    int i;
    for ( i = 0; i < 6; i++)
    {
        enqueue(i);
    }
    int value;
    printf("\n\n %d\n",dem());
    for(i=0;i<6;i++)
    {
        dequeue(&value);
        printf("%d ",value);
    }
    printf("\n\n %d",dem());


    clear();
}