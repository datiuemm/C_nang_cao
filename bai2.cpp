#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int nm(int *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao a[%d] = ",i);
		scanf ("%d", &*(p+i));
	}
}
int inm(int *p,int n)
{
	printf ("Mang da nhap: ");
	for (int i=0;i<n;i++)
	{
		printf ("   %d",*(p+i));
	}
}

int  amnn (int *p,int n)
{
	int i,tg;
	for (i=0;i<n;i++)
	{
		if (*(p+i)<0)
		{
		tg=*(p+i);
		break;
		}
	}
	for (i=i+1;i<n;i++)
	{
	if (*(p+i)<0 && (tg>=*(p+i)))
		{
//		printf ("   %d",*(p+i));
		printf ("\nvi tri so am nho nhat trong mang la: a[%d]",i);
		}
	}
}
int main()
{
	int *p,n;
	p=(int*)malloc(n*sizeof(int));
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	nm(p,n);
	inm(p,n);
	amnn(p,n);
}
