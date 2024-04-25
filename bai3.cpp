#include <stdio.h>
#include <stdlib.h>


void nhaptt (int *p,int n,int m){
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		printf ("a[%d][%d] = ",i,j);
		scanf("%d",&p[i*m+j]);
	}
}



void intt (int *p,int n,int m){
	printf ("\nMang da nhap la:");
	for (int i=0;i<n;i++)
	{
		printf ("\n");
		for (int j=0;j<m;j++)
		{
			printf("%d\t",p[i*m+j]);
		}
	}
}



void tbc (int *p,int n,int m){
	int dem=0;
	float sum=0;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		sum += p[i*m+j];
		dem++;
	}
	
	printf ("\n\nTrung binh cong cac phan tu la: %.2f",sum/dem);
}



void amln0 (int *p,int n,int m){
	int max=1;
	for (int j=0;j<m;j++)
	{
		if (p[j] < 0)
		{
			max = p[j];
			break;
		}
	}
	
	if (max==1) printf ("\n\nKhong co so am tren hang 0");
	else {
		for (int j=0;j<m;j++)
		{
			if (p[j] < 0 && p[j] > max)
			max = p[j];
		}
		printf ("\n\nSo am lon nhat tren hang 0 la: %d",max);
	}
}



void docFile (int *p,int n,int m){
	FILE *f = fopen("matranthuc.txt","w");
	if (f==NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	bool a=0;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
		{
			fprintf(f,"%d\t",p[i*m+j]);
			a=1;
		}
	fclose (f);
	if (a) printf ("\n\nFile da duoc ghi tai ./matranthuc.txt");
}



void inFile (int *p,int n,int m){
	FILE *f = fopen("matranthuc.txt","r");
	if (f==NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	int x;
	printf ("\n\nDu lieu doc tu file la:\n");
	while (fscanf(f,"%d",&x) != EOF)
	printf ("%d\t",x);
	fclose (f);
}



int main(){
	int n,m,*p;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	printf ("Hay nhap vao m: ");
	scanf ("%d",&m);
	p=(int*)malloc(n*m*sizeof(int));
	nhaptt(p,n,m);
	intt(p,n,m);
	tbc(p,n,m);
	amln0(p,n,m);
	docFile(p,n,m);
	inFile(p,n,m);
	
	
	free(p);
	return 0;
}
