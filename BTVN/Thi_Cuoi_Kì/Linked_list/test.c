#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct key_strs
{
    int data;
    char Tendoibong[20];
    int Diem;
    int Sobanthang,Sobanthua;
};
struct key_strs dulieu[100];
struct Vongdau
{
    char vong[20];
    int tran1[2];
    int tran2[2];
};
struct Vongdau vongdau[100];

void readFile(int *n){
    FILE *fp;
    fp=fopen("file.txt","r");
    if(fp==NULL){
        printf("Error file\n.");
        exit(1);
    }
    int count;
    fscanf(fp,"%d\n",&count);
    *n=count;
    printf("%d\n",count);
    char temp[20];
    for (int i = 0; i < count; i++)
    {
        fscanf(fp,"%d\t%s %s",&dulieu[i].data,dulieu[i].Tendoibong,temp);
        strcat(dulieu[i].Tendoibong," ");
        strcat(dulieu[i].Tendoibong,temp);
        printf("%d  %-10s\n",dulieu[i].data,dulieu[i].Tendoibong);
    }
    for(int i=0;i<count;i++){
        dulieu[i].Sobanthang=0;
        dulieu[i].Sobanthua=0;
        dulieu[i].Diem=0;
    }
    for(int i=0;i<count-1;++i){
       fscanf(fp,"%s %s\n",vongdau[i].vong,temp);
       strcat(vongdau[i].vong," ");
       strcat(vongdau[i].vong,temp);
       fscanf(fp,"%d %d\n",&vongdau[i].tran1[0],&vongdau[i].tran1[1]);
       fscanf(fp,"%d %d\n",&vongdau[i].tran2[0],&vongdau[i].tran2[1]);
    }
    fclose(fp);
    
    
}
void case1(int n){
    printf("ID\t%-10s\t%-10s\t%-10s\t%-10s\n","Tendoibong","Diem","Sobanthang"," Sobanthua");
    for(int i=0;i<n;i++){
        printf("%d\t%-10s\t%-10d\t%-10d\t%-10d\n",dulieu[i].data,dulieu[i].Tendoibong,dulieu[i].Diem,dulieu[i].Sobanthang,dulieu[i].Sobanthua);
    }
    
}
//
void check(int n,int k){
    for (int i = 0; i < n; i++)
    {
        if(k==dulieu[i].data) printf("%s    ",dulieu[i].Tendoibong);
    }
    return ;
}

void case2(int n){
    printf("Lich thi dau:\n");
    for (int i = 0; i < n-1; i++)
    {
        printf("%s\n",vongdau[i].vong);
        check(n,vongdau[i].tran1[0]);
        check(n,vongdau[i].tran1[1]);
        printf("\n");
        check(n,vongdau[i].tran2[0]);
        check(n,vongdau[i].tran2[1]);
        printf("\n");
    }
}


struct LinkedList{
    int data;
    char Tendoibong[20];
    int Diem;
    int Sobanthang,Sobanthua;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //Từ giờ dùng kiểu dữ liệu LinkedList có thể thay bằng node cho ngắn gọn
 
node CreateNode(struct key_strs value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ dùng malloc()
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->data = value.data; // Gán giá trị cho Node
    temp->Diem=value.Diem;
    temp->Sobanthang=value.Sobanthang;
    temp->Sobanthua=value.Sobanthua;
    strcpy(temp->Tendoibong,value.Tendoibong);
    return temp;//Trả về node mới đã có giá trị
}
 
node AddTail(node head, struct key_strs value){
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
 
 
node AddHead(node head, struct key_strs value){
    node temp = CreateNode(value); // Khởi tạo node temp với data = value
    if(head == NULL){
        head = temp; // //Nếu linked list đang trống thì Node temp là head luôn
    }else{
        temp->next = head; // Trỏ next của temp = head hiện tại
        head = temp; // Đổi head hiện tại = temp(Vì temp bây giờ là head mới mà)
    }
    return head;
}
 
node AddAt(node head, struct key_strs value, int position){
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
        printf("%d\t%-10s\t%-10d\t%-10d\t%-10d\n", p->data,p->Tendoibong,p->Diem,p->Sobanthang,p->Sobanthua);
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
    struct key_strs value;
    int n;
    do{
        printf("\nNhap so luong phan tu n = ");
        scanf("%d", &n);
    }while(n <= 0);
 
    for(int i = 0; i < n; ++i){
        printf("\nNhap gia tri can them: ");
        scanf("%d", &value.data);
        head = AddTail(head, value);
    }
    return head;
}
void Search_IDwin(node head,int ID, int value1,int value){
    int position = 0;
    for(node p = head; p != NULL; p = p->next){
        if(p->data == ID){
            p->Sobanthang+=value1;
            p->Sobanthua+=value;
            if(value1>value)    p->Diem+=3;
            if(value1<value)    p->Diem+=0;
            if(value1==value)    p->Diem+=1;
        }
    }
}


int update(int n,int i,node head){
    int a1,a2;
    printf("%s\n",vongdau[i].vong);
    check(n,vongdau[i].tran1[0]);
    check(n,vongdau[i].tran1[1]);
    printf(": ");
    scanf("%d - %d",&a1,&a2);
    Search_IDwin(head,vongdau[i].tran1[0],a1,a2);
    Search_IDwin(head,vongdau[i].tran1[1],a2,a1);
    
    check(n,vongdau[i].tran2[0]);
    check(n,vongdau[i].tran2[1]);
    int a3,a4;
    printf(": ");
    scanf("%d - %d",&a3,&a4);
    Search_IDwin(head,vongdau[i].tran2[0],a3,a4);
    Search_IDwin(head,vongdau[i].tran2[1],a4,a3);
}

void Search_min(node head){
    int position = 0;
    int value=9999;
    node pk = head;
    value=pk->data;
    for(node p = head; p != NULL; p = p->next){
        if(p->Diem < value){
            value=p->Diem;
        }
    }

    printf("Cac doi co diem thap nhat:\n");
     printf("ID\t%-10s\t%-10s\t%-10s\t%-10s\n","Tendoibong","Diem","Sobanthang"," Sobanthua");
    int j=0;
    int i=0;
    for(node p = head; p != NULL; p = p->next){
        
        if(p->Diem == value){
            printf("%d\t%-10s\t%-10d\t%-10d\t%-10d\n", p->data,p->Tendoibong,p->Diem,p->Sobanthang,p->Sobanthua);
            head=DelAt(head,j);
        }
        j++;
    }
    
    printf("Cac doi co diem thap nhat:\n");
     printf("ID\t%-10s\t%-10s\t%-10s\t%-10s\n","Tendoibong","Diem","Sobanthang"," Sobanthua");
    for(node p = head; p != NULL; p = p->next){
        //if(p->Diem != value){
            printf("%d\t%-10s\t%-10d\t%-10d\t%-10d\n", p->data,p->Tendoibong,p->Diem,p->Sobanthang,p->Sobanthua);
        //}
    }
}


int main(){
    int n;
    readFile(&n);
    //case1(n);
    node head=NULL;
    
    
    //case3
    
   
    int option=0;
    int k=0;
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
            printf("Chuc nang 1:\n");
            for(int i=n-1;i>=0;i--){
                head = AddTail(head, dulieu[i]);
            }
            printf("ID\t%-10s\t%-10s\t%-10s\t%-10s\n","Tendoibong","Diem","Sobanthang"," Sobanthua");
            Traverser(head);
            break;
        case 2:
            printf("Chuc nang 2:\n");
            case2(n);
            break;
        case 3:
            printf("Chuc nang 3:\n");
            update(n,k,head);
            Traverser(head);
            k++;
            break;
        case 4:
            printf("Chuc nang 3:\n");
            Search_min(head);
            break;
        case 5:
            break;
        case 6:
            break;
        }

    } while (option != 0);
}