#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt {
	char msv[20];
	char hoten[20];
	int namsinh;
	char lop[20];
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
		gets((p+i)->hoten);
		printf ("Nam sinh: ");
		scanf ("%d",&(p+i)->namsinh);
		printf ("Lop sinh vien: ");
		fflush(stdin);
		gets((p+i)->lop);
		printf ("Diem tong ket: ");
		scanf ("%d",&(p+i)->dtk);	
	}
}

void intt (tt *p, int n)
{
	printf ("\n\nDanh sach da nhap la: ");
	for (int i=0;i<n;i++)
	{
		printf ("\n%s\t|%s\t|%d\t|%s\t|%d\t",(p+i)->msv,(p+i)->hoten,(p+i)->namsinh,(p+i)->lop,(p+i)->dtk);
	}
}


void indtkl4(tt *p,int n)
{
	bool a=false;
	printf ("\n\nDanh sach co DTK > 4 la: ");
	for (int i=0;i<n;i++)
	if (((p+i)->dtk) > 4)
	{
		printf ("\n%s\t|%s\t|%d\t|%s\t|%d\t",(p+i)->msv,(p+i)->hoten,(p+i)->namsinh,(p+i)->lop,(p+i)->dtk);
		a=true;
	}	
	if (a==false) printf ("khong co sinh vien nao co diem lon hon 4");
}

void inD14CNPM6(tt *p,int n)
{
	bool a=false;
	printf ("\n\nDanh sach sinh vien lop D14CNPM6 la: ");
	for (int i=0;i<n;i++)
	if (strcmp((p+i)->lop,"D14CNPM6") == 0)
	{
		printf ("\n%s\t|%s\t|%d\t|%s\t|%d\t",(p+i)->msv,(p+i)->hoten,(p+i)->namsinh,(p+i)->lop,(p+i)->dtk);
		a=true;
	}	
	if (a==false) printf ("khong co sinh vien nao lop D14CNPM6");	
}

void inFile(tt *p,int n)
{
	FILE *f=fopen("D:/dulieu.dat","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	if ((p+i)->namsinh == 2001)
	{
		fprintf (f,"\n%s\t|%s\t|%d\t|%s\t|%d\t",(p+i)->msv,(p+i)->hoten,(p+i)->namsinh,(p+i)->lop,(p+i)->dtk);
		a=true;
	}	
	if (a==false) printf ("\n\nKhong co sinh vien nao sinh 2001");
	else printf ("\n\nFile da duoc ghi tai D:/dulieu.dat");	
	fclose(f);
}

int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt(p,n);
	indtkl4(p,n);
	inD14CNPM6(p,n);
	inFile(p,n);
	free(p);
	return 0;
	
}
