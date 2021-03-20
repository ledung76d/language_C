#include <stdio.h>
const int MAX_ROW = 15;
const int MAX_COL = 9;

int main()
{
    char sodo[MAX_ROW][MAX_COL];
    int i,j,traloi,row,col;
    // reset mang truoc khi dung
    for(i=0;i<MAX_ROW;i++)
        for(j=0;j<MAX_COL;j++)
            sodo[i][j] = 0;
            
    printf("Nhap cac vi tri co nguoi ngoi: \n"); 
    do
    {
        printf("Vi tri co nguoi ngoi : Hang (dem tu 1), cot (dem tu 1) ");
        scanf("%d%d", &row, &col);
        // check gia tri nhap vao co hop le
        if(row>=1 && row<=MAX_ROW && col>=1 && col<=MAX_COL)
            sodo[row-1][col-1]=1;
        else
            printf("Vi tri ban nhap khong hop le!\n");
        
        printf("Co muon nhap them vi tri? (0/1)");
        scanf("%d",&traloi);
    }
    while(traloi!=0);
    
    //in ra cac vi tri ngoi hien co
    printf("So do ngoi hien tai:\n");
    for(i=0;i<MAX_ROW;i++)
    { 
        for(j=0;j<MAX_COL;j++)
        {
            if(sodo[i][j] == 0) printf("-");
            else printf("#");
        }
        printf("\n");
    }    
            
    // check vi pham (chi can check cac o ke tiep tu trai qua phai)
    printf("Check vi pham\n");
    int demViPham=0;
    for(i=0;i<MAX_ROW;i++)
        for(j=0;j<MAX_COL;j++)
            if(sodo[i][j] != 0)
            {
                // neu la o duoi cung --> bo qua
                if( i==MAX_ROW-1 && j==MAX_COL-1) continue;
                
				// neu nam o phia duoi
                else if((i==MAX_ROW-1) && (sodo[i][j+1]!=0)) 
                {
                    printf("Vi pham tai vi tri %d %d.\n",i+1,j+1);
                    demViPham++;
                }
                
                // neu la bien phai
                else if ((j==MAX_COL-1 ) && (sodo[i+1][j]!=0 || sodo[i+1][j-1]!=0))
                {
                    printf("Vi pham tai vi tri %d %d.\n",i+1,j+1);
                    demViPham++;
                }

                // neu nam o bien trai
                else if ((j==0 ) && (sodo[i][j+1]!=0 || sodo[i-1][j+1]!=0))
                {
                    printf("Vi pham tai vi tri %d %d.\n",i+1,j+1);
					demViPham++;	
				}
                // nam o vi tri giua bang     [i-1,j+1]
                else if(sodo[i][j+1]!=0 || sodo[i+1][j]!=0 || sodo[i+1][j+1]!=0 || sodo[i-1][j+1]!=0)
                {
                    printf("Vi pham tai vi tri %d %d \n",i+1,j+1);
                    demViPham++;
                }
                
            }
    
    printf("Tim duoc %d vi tri vi pham\n",demViPham);
    return 0;
}

