#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt {
	char msv[20];
	char ten[20];
	int namsinh;
	int dtk;
};

void nhaptt(tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
	printf ("Sinh vien thu %d",i+1);
	printf ("\nMa sinh vien: ");
	fflush(stdin);
	gets((p+i)->msv);
	printf ("Ho ten sinh vien: ");
	fflush(stdin);
	gets((p+i)->ten);
	printf ("Nam sinh sinh vien: ");
	scanf("%d",&(p+i)->namsinh);
	printf ("Diem tong ket sinh vien: ");
	scanf("%d",&(p+i)->dtk);
}
}

void intt(tt *p, int n)
{
	printf ("in danh sach da nhap: ");
	for (int i=0;i<n;i++){
		printf ("\n%s\t|%s\t|%d\t|%d\t|",(p+i)->msv,(p+i)->ten,(p+i)->namsinh,(p+i)->dtk);
	}
}

void timsv(tt *p,int n,char msv1[])
{
	bool a=false;
	printf ("\nSinh vien co ma sinh vien %s la: ",msv1);
	for (int i=0;i<n;i++)
	{	
	if (strcmp((p+i)->msv,msv1)==0)
	{
		printf ("\n%s\t|%s\t|%d\t|%d\t|",(p+i)->msv,(p+i)->ten,(p+i)->namsinh,(p+i)->dtk);
		a=true;
	}
}
if (a==false) printf ("\nKhong co sinh vien nao co ma sinh vien %s",msv1);
}

void tinhtongdiem(tt *p,int n)
{
	int sum=0;
	for (int i=0;i<n;i++)
	{
		sum += (p+i)->dtk;
	}
	printf ("\nTong diem cua %d sinh vien la: %d",n,sum);
}

void inFile(tt *p,int n)
{
	FILE *f=fopen("D:/svgioi.dat","w");
	if (f==NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	{	
	if ((p+i)->dtk > 8.5)
	{
		fprintf (f,"\n%s\t|%s\t|%d\t|%d\t|",(p+i)->msv,(p+i)->ten,(p+i)->namsinh,(p+i)->dtk);
		a=true;
	}
}
fclose(f);
if (a) printf ("\nFile da duoc ghi tai D:/svgioi.dat");
else printf ("\nKhong co sinh vien nao co diem tong ket > 8.5");
}

int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt(p,n);
	char msv1[20];
	printf ("\nHay nhap vao msv can tim: ");
	fflush(stdin);
	gets(msv1);
	timsv(p,n,msv1);
	tinhtongdiem(p,n);
	inFile(p,n);
	free(p);
	return 0;
	
}

