#include<stdio.h>
#include<stdlib.h>
 
struct LinkedList{
    int data;
    struct LinkedList *next;
 };
 
typedef struct LinkedList *node; //Từ giờ dùng kiểu dữ liệu LinkedList có thể thay bằng node cho ngắn gọn
//Tao moi 1 node
node CreateNode(int value){
    node temp; // declare a node
    temp = (node)malloc(sizeof(struct LinkedList)); // Cấp phát vùng nhớ dùng malloc()
    temp->next = NULL;// Cho next trỏ tới NULL
    temp->data = value; // Gán giá trị cho Node
    return temp;//Trả về node mới đã có giá trị
}
//Them vao cuoi danh sach
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
 
//Them vao dau danh sach
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

//Them vao vi tri bat ki position
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

//Xoa phan tu dau ds 
node DelHead(node head){
    if(head == NULL){
        printf("\nCha co gi de xoa het!");
    }else{
        head = head->next;
    }
    return head;
}
//Xoa phan tu cuoi danh sach 
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
//Xoa phan tu bat ki 
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
 //Lay gia tri o vi tri bat ki
int Get(node head, int index){
    int k = 0;
    node p = head;
    while(p != NULL && k != index){
        p = p->next;
    }
    return p->data;
}
//Tim kiem trong danh sach lien ket 
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
//Xoa tat ca cac node co gia tri = value 
node DelByVal(node head, int value){
    int position = Search(head, value);
    while(position != -1){
        DelAt(head, position);
        position = Search(head, value);
    }
    return head;
}
//In danh sach lien ket
void Traverser(node head){
    printf("\n");
    for(node p = head; p != NULL; p = p->next){
        printf("%5d", p->data);
    }
}

//Khoi tao node head 
node InitHead(){
    node head;
    head = NULL;
    return head;
}
//Dem so phan tu trong danh sach 
int Length(node head){
    int length = 0;
    for(node p = head; p != NULL; p = p->next){
        ++length;
    }
    return length;
}
//Ham nhap danh sach lien ket
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
 
 
 
int main(){
    printf("\n==Tao 1 danh sach lien ket==");
    node head = Input(); //Nhap vao danh sach
    Traverser(head); //In danh sach
 
    printf("\n==Thu them 1 phan tu vao linked list==");
    head = AddAt(head, 100, 2); // them 100 vao vi tri thu 3 trong ds
    Traverser(head);
 
    printf("\n==Thu xoa 1 phan tu khoi linked list==");
    head = DelAt(head, 1); //xoa phan tu thu 2 trong danh sach
    Traverser(head);
 
    printf("\n==Thu tim kiem 1 phan tu trong linked list==");
    int index = Search(head, 5); //Tim kiem phan tu 5 trong ds
    printf("\nTim thay tai chi so %d", index);  // 0 co -1 ko co
 
    printf("\nBan co the thu them nhe!");
 
}
 