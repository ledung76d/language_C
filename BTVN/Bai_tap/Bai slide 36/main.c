#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


typedef struct noder{

	int data;
	struct noder* previous;

}*node_ptr;


node_ptr front = NULL;
node_ptr rear = NULL;

bool is_empty(){

	return (front == NULL);
}

void display_front(){

	if(is_empty()){

		printf("\nThe queue is empty!\n");
		return;
	}

	printf("\n[%d]\n", front->data);
}

void display_rear(){

	if(is_empty()){

		printf("\nThe queue is empty!\n");
		return;
	}
	
	printf("\n[%d]\n", rear->data);
}

bool enqueue(int value){

	node_ptr item = (node_ptr) malloc(sizeof(struct noder));

	if (item == NULL)
		return false;

	item->data = value;
	item->previous = NULL;

	if(rear == NULL)
		front = rear = item;
	else{
		rear->previous = item;
		rear = item;
	}

	return true;
}

bool dequeue(){

	if(is_empty()){

		printf("\nThe queue is empty!\n");
		return false;
	}
    
	node_ptr temp = front;
    printf("Dequeue data: %d",temp->data);
	front = front->previous;
	free(temp);

	return true;
}

void display(){


	if(is_empty()){

		printf("\nThe queue is empty!\n");
		return;
	}

	node_ptr temp = front;

	printf("\n[front -> ");

	while(temp != NULL){
		printf("[%d]", temp->data);
		temp = temp->previous;
	}

	printf(" <- rear]\n");

}

bool clear(){

	if(is_empty()){

		printf("\nThe queue is empty!\n");
		return false;
	}

	node_ptr current = front;
	node_ptr previous = NULL;

	while(current != NULL){

		previous = current->previous;
		free(current);
		current = previous;
	}

	front = NULL;

	return is_empty();
}



typedef struct node *link;
struct node{
    int item;
    link l,r;   
};
link NEW(int item,link l, link r ){
    link x=malloc(sizeof*x);
    x->item = item;
    x->l = l ;
    x->r =r ;
    return x;
}

link max(int a[],int l, int r){
    int m=(l+r)/2;
    int u,v;
    link x=NEW(a[m],NULL,NULL);
    if(l == r) return x;
    x->l=max(a,l,m);
    x->r=max(a,m+1,r);
    u=x->l->item;
    v=x->r->item;
    if(u>v)
        x->item =u;
    else 
        x->item=v;
    return x;
}

void breadth_first(link node){
    //struct Queue *queue;
    if(node!=NULL){
        enqeue(node);
        while(is_empty()){
            node=dequeue(queue); 
            printf("--%d",node->item);
            if(node->l!=NULL)
                enqueue(node->l);
            if(node->r!=NULL)
                enQueue(node->r);
        }
    }
}

int main(){
  int option = 0;
    int i, j;
    int n=0 ;
    int *Array;
    do
    {
        printf("\n Menu \n"
               "\n1 - Nhap kich thuoc mang N:  "
               "\n2 - Nhap vao N phan tu cua mang"
               "\n3 - Tao cay"
               "\n4 - In cay ra man hinh"
               "\n\n5 - EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Nhap kich thuoc mang N:");
                scanf("%d",&n);
                Array=(int *)malloc(n* sizeof( int));
                break;
            case 2:
               
                if(n==0){
                    printf("Nhap kich thuoc mang N:");
                    scanf("%d",&n);
                    Array=(int *)malloc(n* sizeof( int));
                }
                
                printf("Nhap gia tri mang:\n");
                for(i=0;i<n;i++){
                    printf("A[%d] = ",i+1);
                    scanf("%d",&Array[i]);
                }
               
                break;

            case 3:

                printf("==Da tao cay.==");
                link node;
                node = max(Array,0,n-1);
                
                break;

            case 4:

                //breadth_first(node);
                break;
            
            case 5:

                break;
        }

    } while (option != 5);
}



