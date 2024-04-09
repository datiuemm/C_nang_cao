#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct date{
	int ngay,thang,nam;
};

struct tt{
	char manv[20];
	char ten[20];
	date ngaysinh;
	char que[20];
	float luong;
};

void nhaptt (tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("\nNhap thong tin nhan vien thu %d",i+1);
		printf ("\nHay nhap ma nhan vien: ");
		fflush (stdin);
		gets ((p+i)->manv);
		printf ("Hay nhap ho ten nhan vien: ");
		fflush (stdin);
		gets ((p+i)->ten);
		printf ("Hay nhap ngay sinh nhan vien: ");
		scanf ("%d %d %d",&(p+i)->ngaysinh.ngay,&(p+i)->ngaysinh.thang,&(p+i)->ngaysinh.nam);
		printf ("Hay nhap que quan nhan vien: ");
		fflush (stdin);
		gets ((p+i)->que);
		printf ("Hay nhap luong nhan vien: ");
		scanf ("%f",&(p+i)->luong);
	}
}


void intt (tt *p,int n)
{
	printf ("\nDanh sach da in la: ");
	for (int i=0;i<n;i++)
	{
		printf ("\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t|",(p+i)->manv,(p+i)->ten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
	}
}

void inns(tt *p,int n,tt *ptr)
{
	bool a=false;
	printf ("\nDanh sach nhan vien co ngay sinh la %d/%d/%d:  ",ptr->ngaysinh.ngay,ptr->ngaysinh.thang,ptr->ngaysinh.nam);
	for (int i=0;i<n;i++)
	if ((p+i)->ngaysinh.ngay == ptr->ngaysinh.ngay && ((p+i)->ngaysinh.thang) == (ptr->ngaysinh.thang)&& ptr->ngaysinh.nam == ((p+i)->ngaysinh.nam))
	{
		printf ("\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t|",(p+i)->manv,(p+i)->ten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
		a=true;
	}	
	if (a==false) printf ("\nKhong co nhan vien nao sinh ngay %d/%d/%d",ptr->ngaysinh.ngay,ptr->ngaysinh.thang,ptr->ngaysinh.nam);
}

void innv(tt *p,int n)
{
	bool a=false;
	printf ("\n\nNhan vien co ma nhan vien la NV0120: ");
	for (int i=0;i<n;i++)
	if (strcmp((p+i)->manv,"NV0120") == 0)
	{
		printf ("\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t|",(p+i)->manv,(p+i)->ten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
		a=true;
	}	
	if (a==false) printf ("\nKhong co nhan vien co ma nhan vien la NV0120");
}

void inFile (tt *p,int n)
{
	FILE *f = fopen ("trocap.txt","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	if ((p+i)->luong < 500)
	{
		fprintf (f,"\n|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t|",(p+i)->manv,(p+i)->ten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->luong);
		a=true;
	}	
	if (a) printf ("\n\nDa in file tai ./trocap.txt");
	else printf ("\n\nKhong co NV nao luong < 500");
}



int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p=(tt*)malloc(n*sizeof(tt));
	tt *ptr=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt (p,n);
	printf ("\n\nHay nhap ngay sinh nhan vien can tim: ");
	scanf ("%d %d %d",&ptr->ngaysinh.ngay,&ptr->ngaysinh.thang,&ptr->ngaysinh.nam);
	inns(p,n,ptr);
	innv(p,n);
	inFile(p,n);
	free(p);
	free(ptr);
	return 0;
	
}
