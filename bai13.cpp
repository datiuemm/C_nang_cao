#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date{
	int ngay, thang,nam;
};

struct tt {
	char manv[20];
	char hoten[20];
	date ngaysinh;
	char que[20];
	float luong;
};

void nhaptt(tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao thong tin nhan vien thu %d",i+1);
		printf ("\nMa nhan vien: ");
		fflush(stdin);
		gets ((p+i)->manv);
		printf ("Ho ten nhan vien: ");
		fflush(stdin);
		gets ((p+i)->hoten);
		printf ("Ngay sinh quan nhan vien: ");
		scanf ("%d %d %d",&(p+i)->ngaysinh.ngay,&(p+i)->ngaysinh.thang,&(p+i)->ngaysinh.nam);
		printf ("Que quan nhan vien: ");
		fflush(stdin);
		gets ((p+i)->que);
		printf ("Luong nhan vien: ");
		scanf ("%f",&(p+i)->luong);
	}
}

void intt(tt *p,int n)
{
	printf ("\n\nDanh sach nhan vien la: ");
	for (int i=0;i<n;i++)
	{
		printf ("\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t",(p+i)->manv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
	}
}


void luongb800(tt *p,int n)
{
	bool a=false;
	printf ("\n\nDanh sach nhan vien co luong be hon 800 la: ");
	for (int i=0;i<n;i++)
	if ((p+i)->luong < 800)
	{
		printf ("\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t",(p+i)->manv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
		a=true;
	}
	if (a==false) printf ("khong co nhan vien nao be hon 800");
}

void queHG(tt *p,int n)
{
	bool a=false;
	printf ("\n\nDanh sach nhan vien co que Ha Giang la: ");
	for (int i=0;i<n;i++)
	if (strcmp(((p+i)->que),"Ha Giang") == 0)
	{
		printf ("\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t",(p+i)->manv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
		a=true;
	}
	if (a==false) printf ("khong co nhan vien nao que Ha Giang");
}

void inFile(tt *p,int n)
{
	FILE *f=fopen ("nhanvien.txt","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	if ((p+i)->ngaysinh.nam == 2000)
	{
		fprintf (f,"\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t",(p+i)->manv,(p+i)->hoten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
		a=true;
	}
	fclose (f);
	if (a) printf ("\nFile da duoc ghi tai ./nhanvien.txt");
	else printf ("\nKhong co nhan vien co nam sinh la 2000");
}

int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt(p,n);
	luongb800(p,n);
	queHG(p,n);
	inFile(p,n);
	free (p);
	return 0;
}
