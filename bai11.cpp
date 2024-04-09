#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date {
	int ngay,thang,nam;
};

struct tt{
	char mnv[20];
	char hoten[20];
	date ngaysinh;
	float hsl;
};

void nhaptt(tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao thong tin nhan vien thu %d",i+1);
		printf ("\nHay nhap vao ma nhan vien: ");
		fflush(stdin);
		gets ((p+i)->mnv);
		printf ("Hay nhap vao ho ten nhan vien: ");
		fflush(stdin);
		gets ((p+i)->hoten);
		printf ("Hay nhap vao ngay sinh nhan vien: ");
		scanf ("%d %d %d",&(p+i)->ngaysinh.ngay,&(p+i)->ngaysinh.thang,&(p+i)->ngaysinh.nam);
		printf ("Hay nhap vao he so luong nhan vien: ");
		scanf ("%f",&(p+i)->hsl);
	}
}

void intt (tt *p,int n)
{
	printf ("\nDanh sach nhan vien la: ");
	for (int i=0;i<n;i++)
	{
	printf ("\n|%s\t|%s\t|%d/%d/%d\t|%.2f\t",(p+i)->mnv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->hsl);
	}
}

void inluong (tt *p,int n)
{
	printf ("\nThong tin nhan vien co bang luong la: ");

	for (int i=0;i<n;i++)
	{
	printf ("\n|%s\t|%s\t|%d/%d/%d\t|%.2f\t|%.2f\t",(p+i)->mnv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->hsl,((p+i)->hsl)*1500);
}
}

void innv (tt *p,int n)
{
	bool a=false;
	printf ("\nThong tin nhan vien co ma nv6699 la: ");
	for (int i=0;i<n;i++)
	{
	if (strcmp((p+i)->mnv,"nv6699") == 0){
	
	printf ("\n|%s\t|%s\t|%d/%d/%d\t|%.2f\t|%.2f",(p+i)->mnv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->hsl,((p+i)->hsl)*1500);
	a=true;
}
}
	if (a==false) printf ("\nKhong co ma nhan vien co ma nhan vien nv6699");
}

void ghiFile(tt *p,int n)
{
	FILE *f = fopen("tangluong.txt","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
	}
	bool a=false;

	for (int i=0;i<n;i++)
	{
	if ((((p+i)->hsl)*1500) < 5000){
	
	fprintf (f,"\n|%s\t|%s\t|%d/%d/%d\t|%.2f\t|%.2f",(p+i)->mnv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->hsl,((p+i)->hsl)*1500);
	a=true;
}
}
	if (a) printf ("\nDa in thong tin tren file ./tangluong.txt");
	else printf ("\nKhong co nhan vien co luong thap hon 5000");
}

int main()
{
	int n;
	tt *p;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	p=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt(p,n);
	inluong(p,n);
	innv(p,n);
	ghiFile(p,n);
	free (p);
	return 0;
}



