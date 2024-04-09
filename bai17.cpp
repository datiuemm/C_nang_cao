#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nhapmang(int *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("a[%d] = ",i);
		scanf ("%d",&p[i]);
	}
}

void inmang(int *p,int n)
{
	printf ("\nMang da nhap la:");
		for (int i=0;i<n;i++)
	{
		printf ("   %d",p[i]);

	}
}

void tbcxy (int *p,int n, int x, int y)
{
	float sum=0;
	int dem=0;
	for (int i = x; i < y + 1 ; i++)
	{
		sum += p[i];
		dem++;
	}
	printf ("\nTrung binh cong chay tu khoang [%d;%d] la: %.2f",x,y,sum/dem);
}

void gtln(int *p,int n)
{
	int gtln = p[0];
	for (int i=0;i<n;i++)
	{
		if (p[i] > gtln)
		{
			gtln = p[i];
		}
	}
	printf ("\n\nGia tri lon nhat la: %d",gtln);
}

bool inFile (int *p,int n)
{
	FILE *f=fopen("soduong1.txt","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	if (p[i] > 0)
	{
		fprintf (f,"   %d",p[i]);
		a=true;
	}
	fclose(f);
	if (a) printf ("\n\nFile da duoc ghi tai ./soduong1.txt");
	else printf ("\n\nKhong co so duong");
	return a;
}

void docTep(int *p,int n)
{
	FILE *f=fopen("soduong1.txt","r");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	
	int x;
	printf ("\n\nDanh sach doc tu file la:");
	while (fscanf (f,"%d",&x) != EOF)
	{
	printf ("   %d",x);
}
	fclose(f);
}

int main()
{
	int n,x,y;
	bool a=false;
	printf ("Hay nhap vao n: ");
	scanf("%d",&n);
	int *p=(int*)malloc(n*sizeof(int));
	nhapmang(p,n);
	inmang(p,n);
	printf ("\nHay nhap vao x y: ");
	scanf ("%d %d",&x,&y);
	tbcxy(p,n,x,y);
	gtln(p,n);
	a=inFile(p,n);
	if (a)
	docTep(p,n);
	free(p);
	return 0;
}
