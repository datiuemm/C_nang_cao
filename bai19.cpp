#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nhapmang(int *p,int n,int m)
{
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		printf ("a[%d][%d] = ",i,j);
		scanf ("%d", &p[i*m+j]);
	}
}

void inmang(int *p,int n,int m)
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

void tongcheo(int *p,int n,int m)
{
	int sum = 0;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if (i==j)
		sum += p[i*m+j];
	}
	printf ("\n\nTong cac phan tu tren duong cheo chinh la: %d",sum);
	
}

void lnc2(int *p,int n,int m)
{
	int max = p[0*m+2];
	for (int i=1;i<n;i++)
	{
		if (p[i*m+2] > max)
		max = p[i*m+2];
	}
	printf ("\n\nGia tri lon nhat cua cot 2 la: %d",max);
}

void inFile(int *p,int n,int m)
{
	FILE *f=fopen("D:/matran19.txt","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	bool a=0;
	for (int i=0;i<n;i++)
	{
	fprintf (f,"\n");
	for (int j=0;j<m;j++)
	{
		fprintf (f,"%d   ",p[i*m+j]);
		a=1;
	}
}
	if (a) printf ("\n\nFile da duoc ghi tai D:/matran19.txt");
	fclose(f);
}


int main()
{
	int *p, n,m;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	printf ("Hay nhap vao m: ");
	scanf ("%d",&m);
	p=(int*)malloc(n*m*sizeof(int));
	nhapmang(p,n,m);
	inmang(p,n,m);
	tongcheo(p,n,m);
	lnc2(p,n,m);
	inFile(p,n,m);
	free(p);
	return 0;
}
