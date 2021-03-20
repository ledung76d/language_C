#include <stdio.h>

int main()
{
    int soKwh;
    double thanhToan1,thanhToan2,chenhlech;
    int traloi;
    
    do
    {   //tinh so tien thanh toan cu
        printf("Nhap vao so dien tieu thu: ");
        scanf("%d",&soKwh);
        
        if(soKwh>400) 
            thanhToan1 = (soKwh-400)*2701 + (50*1549 + 50*1600 + 100*1858 + 100*2340 + 100*2615);
        else if(soKwh>300) 
            thanhToan1 = (soKwh-300)*2615 + (50*1549 + 50*1600 + 100*1858 + 100*2340 );
        else if(soKwh>200) 
            thanhToan1 = (soKwh-200)*2340 + (50*1549 + 50*1600 + 100*1858  );
        else if(soKwh>100)
            thanhToan1 = (soKwh-100)*1858 + (50*1549 + 50*1600);  
        else if(soKwh>50) 
            thanhToan1 = (soKwh-50)*1600 + (50*1549);  
        else
            thanhToan1 = soKwh*1549;
            
        printf("Tong tien cu: %.2lf\n",thanhToan1);
        printf("VAT: %.2lf\n",thanhToan1 * 0.1);
        printf("===============================================\n");
        printf("Thanh toan cua khach theo thang do cu: %.2lf\n",thanhToan1 + thanhToan1* 0.1);
        
		printf("------------------------------------------------\n");
        printf("------------------------------------------------\n");
        // So tien thanh toan moi
		if(soKwh>700) 
            thanhToan2 = (soKwh-700)*3105 + (100*1549+100*1858+200*2340+300*2701);
        else if(soKwh>400) 
            thanhToan2 = (soKwh-400)*2701 + (100*1549+100*1858+200*2340);
        else if(soKwh>200) 
            thanhToan2 = (soKwh-200)*2340 + (100*1549+100*1858);
        else if(soKwh>100)
            thanhToan2 = (soKwh-100)*1858 + (100*1549);    
        else
            thanhToan2 = soKwh*1549;
            
        printf("Tong tien moi: %.2lf\n",thanhToan2);
        printf("VAT: %.2lf\n",thanhToan2 * 0.1);
        printf("===============================================\n");
        printf("Thanh toan cua khach theo thang do moi: %.2lf\n",thanhToan2 + thanhToan2* 0.1);
        
        printf("------------------------------------------------\n");
        printf("------------------------------------------------\n");
        
        chenhlech=thanhToan1-thanhToan2;
        if(chenhlech>0)
        	printf("Thang do cu chenh lech nhieu hon thang do moi: %.2lf dong\n",chenhlech);
    	else
    		printf("Thang do moi chenh lech nhieu hon thang do cu: %.2lf dong\n",-chenhlech);
        printf("Thuc hien tiep nhan phim 1: ");
        scanf("%d",&traloi);
        printf("\f");
    }
    while(traloi==1);
    
    return 0;
}

