#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nhaptt(int *p,int n,int m)
{
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		printf ("a[%d][%d] = ",i,j);
		scanf ("%d",&p[i*m+j]);
	}
}

void intt (int *p,int n,int m)
{
	printf ("\nMang da nhap la: ");
	for (int i=0;i<n;i++)
	{
	printf ("\n");
	for (int j=0;j<m;j++)
	{
	printf ("%d   ",p[i*m+j]);
	}
}
}

void sum (int *p,int n,int m)
{
	int sum = 0;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		sum += p[i*m+j];
	}
	printf ("\n\nTong cac phan tu trong mang la: %d",sum);
}

void gtnn0(int *p,int n,int m)
{
	int gtnn = p[0*m+0];
	for (int j=0;j<m;j++)
	{
		if (p[0*m+j] < gtnn)
		gtnn = p[0*m+j];
	}
	printf ("\n\nGia tri nho nhat tren hang 0 la: %d",gtnn);
}

bool inFile(int *p,int n,int m)
{
	FILE *f=fopen("matran1.txt","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if (p[i*m+j] % 3 == 0)
		{
			fprintf (f,"   %d",p[i*m+j]);
			a=true;
		}	
	}
	if (a) printf ("\n\nFile da duoc ghi tai ./matran1.txt");
	else printf ("\n\nKhong co phan tu nao chia het cho 3");
	fclose(f);
	return a;
}

void docFile(int *p,int n,int m)
{
	FILE *f=fopen("matran1.txt","r");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	int x;
	printf ("\n\nDoc tu file la:");
	while (fscanf(f,"%d",&x) != EOF)
	printf ("   %d",x);
	fclose(f);
}

int main()
{
	int n,m;
	bool a=false;
	printf ("Nhap vao n: ");
	scanf ("%d",&n);
	printf ("Nhap vao m: ");
	scanf ("%d",&m);
	int *p=(int*)malloc(n*m*sizeof(int));
	nhaptt(p,n,m);
	intt (p,n,m);
	sum (p,n,m);
	gtnn0(p,n,m);
	a=inFile(p,n,m);
	if (a) 
	docFile(p,n,m);
	free(p);
	return 0;
}
