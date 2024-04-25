#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct tt{
	char masach[20];
	char tensach[20];
	int namxb;
	char nsx[20];
	int gia;
	};
	
void nhaptt(tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("\nSach thu %d",i+1);
		printf ("\nMa sach: ");
		fflush(stdin);
		gets((p+i)->masach);
		
		printf ("Ten sach: ");
		fflush(stdin);
		gets((p+i)->tensach);
		
		printf ("Nam xuat ban: ");
		scanf ("%d",&(p+i)->namxb);
		
		printf ("Nha san xuat: ");
		fflush(stdin);
		gets((p+i)->nsx);
		
		printf ("Gia sach: ");
		scanf ("%d",&(p+i)->gia);
	}
}

void intt(tt *p,int n)
{
	printf ("\nDanh sach da nhap la:");
	for (int i=0;i<n;i++)
	{
		printf ("\n%s\t|%s\t|%d\t|%s\t|%d\t|",(p+i)->masach,(p+i)->tensach,(p+i)->namxb,(p+i)->nsx,(p+i)->gia);
	}
}

void inKHKT(tt *p,int n)
{
	bool a=false;
	printf ("\n\nDanh sach sach cua nha xuat ban KHKT la: ");
		for (int i=0;i<n;i++)
		if(strcmp((p+i)->nsx,"KHKT") == 0)
	{
		
		printf ("\n%s\t|%s\t|%d\t|%s\t|%d\t|",(p+i)->masach,(p+i)->tensach,(p+i)->namxb,(p+i)->nsx,(p+i)->gia);
		a=1;
	}
	if (a==0) printf ("Khong co quyen sach nao cua nha xuat ban KHKT");
}

void inFile(tt *p,int n)
{
	FILE *f=fopen("giaban.dat","w");
	if (f == NULL)
	{
		printf ("\n\nKhong the mo file.");
		exit(1);
	}
		bool a=false;
	for (int i=0;i<n;i++)
	if((p+i)->gia > 100000)
	{
		
		fprintf (f,"\n%s\t|%s\t|%d\t|%s\t|%d\t|",(p+i)->masach,(p+i)->tensach,(p+i)->namxb,(p+i)->nsx,(p+i)->gia);
		a=1;
	}
	if (a) printf ("\n\nFile duoc ghi tai ./giaban.dat");
	else printf ("\n\nKhong co sach nao co gia lon hon 100000");
	
	fclose (f);
}

void inTien(tt *p,int n,int x){
		bool a=false;
	printf ("\nDanh sach sach co gia %d la: ",x);
		for (int i=0;i<n;i++)
		if((p+i)->gia == x)
	{
		
		printf ("\n%s\t|%s\t|%d\t|%s\t|%d\t|",(p+i)->masach,(p+i)->tensach,(p+i)->namxb,(p+i)->nsx,(p+i)->gia);
		a=1;
	}
	if (a==0) printf ("Khong co quyen sach co gia %d",x);
}

int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt(p,n);
	inKHKT(p,n);
	inFile(p,n);
	int x;
	printf ("\n\nHay nhap vao gia tri: ");
	scanf ("%d",&x);
	inTien(p,n,x);
	free(p);
	return 0;
}
