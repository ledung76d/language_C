#include<stdio.h>

int main() {
    float rate,n,tien,tienlai;
    printf("Nhap lai suat rate %/nam:\n");
    scanf("%f",&rate);
    printf("Nhap so tien gui:\n ");
    scanf("%f",&tien);
    printf("Nhap so thang gui:\n");
    scanf("%f",&n);
    rate=rate/12;
    tienlai=tien;
	for(int i=1;i<n;i++){
		tienlai=tienlai*(1+rate);
	}
	printf("So tien goc %f\n",tien);
	printf("So tien lai %f\n",tienlai-tien);
    return 0;
}
