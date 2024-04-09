#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt {
	char mkh[20];
	char hoten[20];
	char diachi[20];
	float sodien;
};

void nhaptt(tt *p,int n)
{
	
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao KH %d",i+1);
		printf ("\nNhap vao ma KH: ");
		fflush(stdin);
		gets ((p+i)->mkh);
		
		printf ("Nhap vao ten KH: ");
		fflush(stdin);
		gets ((p+i)->hoten);
		
		printf ("Nhap vao dia chi KH: ");
		fflush(stdin);
		gets ((p+i)->diachi);
		
		printf ("Nhap vao so dien KH: ");
		scanf ("%f",&(p+i)->sodien);
	}
}

void intt(tt *p,int n)
{
//	bool a=false;
	printf ("\nThong tin KH da nhap la: ");
	for (int i=0;i<n;i++)
	{
	printf ("\n%s\t|%s\t|%s\t|%.2f\t|",(p+i)->mkh,(p+i)->hoten,(p+i)->diachi,(p+i)->sodien);
	}
}

void inb100(tt *p,int n)
{
	bool a=false;
	printf ("\nThong tin KH co so dien < 100 la: ");
	for (int i=0;i<n;i++)
	{
	if (((p+i)->sodien) < 100){
	printf ("\n%s\t|%s\t|%s\t|%.2f\t|",(p+i)->mkh,(p+i)->hoten,(p+i)->diachi,(p+i)->sodien);
	a=true;
	}
	}
	if (a==false) printf ("\nKhong co KH nao co so dien < 100");
}

void inmkh(tt *p,int n,char mkh1[])
{
	bool a=false;
	printf ("\nThong tin KH co so MKH la %s",mkh1);
	for (int i=0;i<n;i++)
	{
	if (strcmp((p+i)->mkh,mkh1) == 0)
	{
	
	printf ("\n%s\t|%s\t|%s\t|%.2f\t|",(p+i)->mkh,(p+i)->hoten,(p+i)->diachi,(p+i)->sodien);
	a=true;
	}
}
	if (a==false) printf ("\nKhong co KH nao co MKH la %s",mkh1);
}


void inFile (tt *p,int n)
{
	bool a=false;
	FILE *f=fopen("doanhnghiep.txt","w");
	if (f==NULL)
	{
		printf ("\nKhong the mo file.");
		exit (1);
	}
	for (int i=0;i<n;i++)
	if (((p+i)->sodien) > 500){
	fprintf (f,"\n%s\t|%s\t|%s\t|%.2f\t|",(p+i)->mkh,(p+i)->hoten,(p+i)->diachi,(p+i)->sodien);
	a=true;
	}
	fclose(f);
	if (a) printf ("\n\nDa in tai ./doanhnghiep.txt");
	else printf ("\n\nKhong co khach hang nao tieu thu lon hon 500");
	
}

 int main()
 {
 	int n;
 	char mkh1[20];
 	tt *p;
 	p=(tt*)malloc(n*sizeof(tt));
 	printf ("Nhap vao n: ");
 	scanf ("%d",&n);
 	nhaptt(p,n);
 	intt(p,n);
 	inb100(p,n);
 	printf ("\nNhap thong tin KH can tim: ");
  	fflush(stdin);
 	gets (mkh1);
 	inmkh(p,n,mkh1);
 	inFile(p,n);
 	free(p);
 	return 0;
 }
