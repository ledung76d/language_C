#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct key_strs
{
    int data;
    char Tendoibong[20];
    int Diem;
    int Sobanthang,Sobanthua;
};
struct key_strs dulieu[100];
 
struct LinkedList{
    int data;
    char Tendoibong[20];
    int Diem;
    int Sobanthang,Sobanthua;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //Từ giờ dùng kiểu dữ liệu LinkedList có thể thay bằng node cho ngắn gọn
 
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ dùng malloc()
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->data = value; // Gán giá trị cho Node
    return temp;//Trả về node mới đã có giá trị
}
 
node AddTail(node head, int value){
    node temp,p;// Khai báo 2 node tạm temp và p
    temp = CreateNode(value);//Gọi hàm createNode để khởi tạo node temp có next trỏ tới NULL và giá trị là value
    if(head == NULL){
        head = temp;     //Nếu linked list đang trống thì Node temp là head luôn
    }
    else{
        p  = head;// Khởi tạo p trỏ tới head
        while(p->next != NULL){
            p = p->next;//Duyệt danh sách liên kết đến cuối. Node cuối là node có next = NULL
        }
        p->next = temp;//Gán next của thằng cuối = temp. Khi đó temp sẽ là thằng cuối(temp->next = NULL mà)
    }
    return head;
}
 
 
node AddHead(node head, int value){
    node temp = CreateNode(value); // Khởi tạo node temp với data = value
    if(head == NULL){
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }else{
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}
 
node AddAt(node head, int value, int position){
    if(position == 0 || head == NULL){
        head = AddHead(head, value); // Nếu vị trí chèn là 0, tức là thêm vào đầu
    }else{
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        node p = head;
        while(p != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định chèn cuối
            // Nếu bạn không muốn chèn, hãy thông báo vị trí chèn không hợp lệ
            head = AddTail(head, value);
            // printf("Vi tri chen vuot qua vi tri cuoi cung!\n");
        }else{
            node temp = CreateNode(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
    return head;
}
 
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
 
node DelTail(node head){
    if (head == NULL || head->next == NULL){
         return DelHead(head);
    }
    node p = head;
    while(p->next->next != NULL){
        p = p->next;
    }
    p->next = p->next->next; // Cho next bằng NULL
    // Hoặc viết p->next = NULL cũng được
    return head;
}
 
node DelAt(node head, int position){
    if(position == 0 || head == NULL || head->next == NULL){
        head = DelHead(head); // Nếu vị trí chèn là 0, tức là thêm vào đầu
    }else{
        // Bắt đầu tìm vị trí cần chèn. Ta sẽ dùng k để đếm cho vị trí
        int k = 1;
        node p = head;
        while(p->next->next != NULL && k != position){
            p = p->next;
            ++k;
        }
 
        if(k != position){
            // Nếu duyệt hết danh sách lk rồi mà vẫn chưa đến vị trí cần chèn, ta sẽ mặc định xóa cuối
            // Nếu bạn không muốn xóa, hãy thông báo vị trí xóa không hợp lệ
            head = DelTail(head);
            // printf("Vi tri xoa vuot qua vi tri cuoi cung!\n");
        }else{
            p->next = p->next->next;
        }
    }
    return head;
}
 
int Get(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }
    return p->data;
}
 
int Search(node head, int value){
    int position = 0;
    for(node p = head; p != NULL; p = p->next){
        if(p->data == value){
            return position;
        }
        ++position;
    }
    return -1;
}
 
node DelByVal(node head, int value){
    int position = Search(head, value);
    while(position != -1){
        DelAt(head, position);
        position = Search(head, value);
    }
    return head;
}
 
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}
 
node InitHead(){
    node head;
    head = NULL;
    return head;
}
 
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
 
node Input(){
    node head = InitHead();
    int n, value;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value);
        head = AddTail(head, value);
    }
    return head;
}
//
struct Vongdau
{
    char vong[20];
    int tran1[2];
    int tran2[2];
};
struct Vongdau vongdau[100];
void readfile(int *n){
    FILE *fp;
    fp=fopen("file.txt","r");
    if(fp==NULL){
        printf("Error FILE?");
        exit(1);
    }
    int count=0;
    fscanf(fp,"%d\n",&count);
    *n=count;
    char temp[20],temp1[20];
    int c;
    for(int i=0;i<count;++i){
        fscanf(fp,"%d\t%s %s\n",&c,temp,temp1);
        printf("%d %10s\n",dulieu[i].data,dulieu[i].Tendoibong);
        //strcat(dulieu[i].Tendoibong,temp);
    }

    for(int i=0;i<count-1;++i){
       fscanf(fp,"%s %s\n",vongdau[i].vong,temp);
       strcat(vongdau[i].vong,temp);
       fscanf(fp,"%d %d\n",&vongdau[i].tran1[1],&vongdau[i].tran1[2]);
       fscanf(fp,"%d %d\n",&vongdau[i].tran2[1],&vongdau[i].tran2[2]);
    }
    fclose(fp);
}
void Infile(int n){
    printf("%d",n);
    for (int i = 0; i < n; i++)
    {
        printf("%d %10s\n",dulieu[i].data,dulieu[i].Tendoibong);
    }
    for (int i = 0; i < n-1; i++)
    {
        //printf("%s\n",vongdau[i].vong);
        //printf("%d  %d\n",vongdau[i].tran1[1],vongdau[i].tran1[2]);
        //printf("%d  %d\n",vongdau[i].tran2[1],vongdau[i].tran2[2]);
    }
    
} 
 
int main(){
    int option=0;
    int n;
    readfile(&n);
    //Infile(n);
    do
    {
        printf("\n Menu \n"
               "\n1 -   Chuc nang 1    "
               "\n2 -   Chuc nang 2    "
               "\n3 -   Chuc nang 3    "
               "\n4 -   Chuc nang 4    "
               "\n5 -   Chuc nang 5    "
               "\n6 -   Chuc nang 6    "
               "\n0 -   EXIT\n\n");

        printf("Option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 0:
            break;
        case 1:
        
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }

    } while (option != 0);
 
}