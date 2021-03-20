#include <stdio.h>
#include <math.h>
int
main ()
{
  int week[7];
  int i;


  printf ("Nhap thoi gian hoc cua tung ngay trong tuan:\n");
  for (i = 0; i < 7; i++)
    {
      printf ("Ngay %d: ", i + 1);
      scanf ("%d", &week[i]);
    }
  int max, timemax;

  max = week[0];
  timemax = 0;
  for (i = 0; i < 7; i++)
    if (max < week[i])
      {
	max = week[i];
	timemax = i;
      }

//  printf ("Ngay %d hoc nhieu nhat trong tuan la:  %d (phut)\n", i + 1, max);

  // tinh trung binh thoi gian va in ra 
  int tongtime = 0;
  for (i = 0; i < 7; i++)
    tongtime = tongtime + week[i];
  double trungbinh = (double) tongtime / 7;
  printf ("Thoi gian trung binh la:%.2f(phut) \n", trungbinh);
  // nhung ngay co thoi gian hoc nhieu hon gia tri trung binh
  for (i = 0; i < 7; i++)
    if (week[i] > trungbinh)
      printf (" Ngay %d hoc cham chi la:%d (phut)\n", i + 1, week[i]);
  int maxcot = 80;
  printf ("Bieu do minh hoa thoi gian hoc cac ngay trong tuan\n\n");
  for (i = 0; i < 7; i++)
    {
      int sodausao = round ((float) week[i] * maxcot / max);
      printf ("%d", i + 1);
      for (int k = 0; k < sodausao; k++)
	printf ("*");
      printf ("\n");
    }
  return 0;
}
