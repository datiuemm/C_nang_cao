#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct tt{
	char sbd[20];
	char hoten[20];
	float diemanh;
	float diemtoan;
	float tongdiem;
	
	
};

void nhaptt (tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao thong tin thi sinh thu %d",i+1);
		printf ("\nHay nhap vao ma thi sinh: ");
		fflush (stdin);
		gets ((p+i)->sbd);
		
		printf ("Hay nhap vao ten thi sinh: ");
		fflush (stdin);
		gets ((p+i)->hoten);
		
		printf ("Hay nhap vao diem toan thi sinh: ");
		scanf ("%f",&(p+i)->diemtoan);
		
		
		printf ("Hay nhap vao diem anh thi sinh: ");
		scanf ("%f",&(p+i)->diemanh);
		
		(p+i)->tongdiem=(p+i)->diemtoan+(p+i)->diemanh;
	}
}

void intt (tt *p,int n)
{
	printf ("\nThong tin cac thi sinh da nhap la: ");
		for (int i=0;i<n;i++)
	{
		printf ("\n|%s\t||%s\t||%.2f\t||%.2f\t||%.2f\t|",(p+i)->sbd,(p+i)->hoten,(p+i)->diemtoan,(p+i)->diemanh,(p+i)->tongdiem);
	}
}

void in17(tt *p,int n)
{
	bool a=false;
	printf ("\nDay la danh sach cac hoc sinh co tong diem tren 17: ");
	for (int i=0;i<n;i++)
	{
	if (((p+i)->diemtoan) >= 8 && ((p+i)->tongdiem) >= 17)
	{
				printf ("\n|%s\t||%s\t||%.2f\t||%.2f\t||%.2f\t|",(p+i)->sbd,(p+i)->hoten,(p+i)->diemtoan,(p+i)->diemanh,(p+i)->tongdiem);
				a =true;
	}
	}
	if (a==false) printf ("Khong co hoc sinh nao thoa man dieu kien.");
}

void inx(tt *p,int n,int x)
{
	bool a=false;
	printf ("\nDay la danh sach cac hoc sinh co tong diem tren bang %d la: ",x);
	for (int i=0;i<n;i++)
	{
	if (((p+i)->tongdiem) == x)
	{
				printf ("\n|%s\t||%s\t||%.2f\t||%.2f\t||%.2f\t|",(p+i)->sbd,(p+i)->hoten,(p+i)->diemtoan,(p+i)->diemanh,(p+i)->tongdiem);
				a =true;
	}
	}
	if (a==false) printf ("Khong co hoc sinh nao thoa man dieu kien.");
}

void inFile(tt *p,int n)
{
	FILE *f = fopen ("thisinh.txt", "w");
	
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
	}
		for (int i=0;i<n;i++)
		fprintf (f,"\n|%s\t||%s\t||%.2f\t||%.2f\t||%.2f\t|",(p+i)->sbd,(p+i)->hoten,(p+i)->diemtoan,(p+i)->diemanh,(p+i)->tongdiem);
}

int main()
{
	int n,x;
	tt *p;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	p=(tt*)malloc(n*sizeof(tt));
	nhaptt (p,n);
	intt (p,n);
	in17(p,n);
	printf ("\nHay nhap vao x: ");
	scanf ("%d",&x);

	inx(p,n,x);
	inFile(p,n);
	return 0;
	
}
