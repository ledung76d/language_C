#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct {
	void * key;
	void * value;
} Entry;

typedef struct {
	Entry * entries;
	int size, total;
	Entry (*makeNode)(void*, void*);
	int (*compare)(void*, void*);
} SymbolTable;

#define INITIAL_SIZE 100
#define INCREMENTAL_SIZE 10
//Khởi tạo bảng dữ liệu
SymbolTable createSymbolTable(
		Entry (*makeNode)(void*, void*),
		int (*compare)(void*, void*)
);
//- Cấp phát bộ nhớ cho danh sách entries
//- Khởi tạo giá trị cho các biến size,total
//- Thiết lập con trỏ makeNode trỏ tới hàm makeNode
//- Thiết lập con trỏ compare trỏ tới hàm compare
//Thêm một entry mới vào bảng dữ liệu
void addEntry(void* key, void* value, SymbolTable* book);

//Tìm entry dựa trên key cho trước
Entry* getEntry(void* key, SymbolTable book);

//Xóa bảng dữ liệu
void dropSymbolTable(SymbolTable* tab);

//Hàm tạo 1 entry mới, mỗi entry tương ứng với cặp thông tin 
// tên người – số điện thoại
Entry makePhone(void* name, void* phone) {
	Entry res;
	res.key = strdup( (char*)name );
	res.value = malloc(sizeof(long));
	memcpy( res.value, phone, sizeof(long) );
	return res;
}

//Hàm so sánh 2 số điện thoại
int comparePhone(void * key1, void* key2) {
	return strcmp((char*)key1, (char*)key2);
}

int main(){

}