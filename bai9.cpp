#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt {
	char mamay[20];
	char tenmay[20];
	char sosr[20];
	float gia;
};

void nhaptt(tt *p,int n)
{
	
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao may tinh thu %d",i+1);
		printf ("\nMa may: ");
		fflush (stdin);
		gets ((p+i)->mamay);
		
		printf ("Ten may: ");
		fflush (stdin);
		gets ((p+i)->tenmay);
		
		printf ("So seri: ");
		fflush (stdin);
		gets ((p+i)->sosr);
		
		printf ("Gia tien: ");
		scanf ("%f",&(p+i)->gia);	
}		
}

void intt (tt *p,int n)
{
	printf ("Thong tin cac may da nhap: ");
	printf ("\n_________________________________________________");
	printf ("\n|STT\t|M.May\t|Ten May\t|So sr\t|Gia tien");
	printf ("\n_________________________________________________");
		for (int i=0;i<n;i++)
	{
		printf ("\n|%d\t|%s\t|%s\t|%s\t|%.2f",i+1,(p+i)->mamay,(p+i)->tenmay,(p+i)->sosr,(p+i)->gia);
		printf ("\n-------------------------------------------------");
	}
}

void in3k (tt *p,int n)
{
	bool a=false;
	printf ("\n\nThong tin cac may co gia > 3000: ");
		for (int i=0;i<n;i++)
		if (((p+i)->gia) > 3000)
	{
		printf ("\n|%s\t|%s\t|%s\t|%.2f",(p+i)->mamay,(p+i)->tenmay,(p+i)->sosr,(p+i)->gia);
	a=true;
	}
	if (a==false) printf ("\nKhong co may co gia tien lon hon 3000");
}

void inmm (tt *p,int n,char x[])
{
	bool a=false;
	printf ("\n\nThong tin cac may co ma may la %s:",x);
		for (int i=0;i<n;i++)
		if (strcmp(((p+i)->mamay),x)==0)
	{
		printf ("\n|%s\t|%s\t|%s\t|%.2f",(p+i)->mamay,(p+i)->tenmay,(p+i)->sosr,(p+i)->gia);
		a=true;
	}
	if (a==false) printf ("\nKhong co ma may %s",x);
}


void inFile (tt *p,int n)
{
	FILE *f=fopen("maytinh1.txt","w");
	if (f==NULL) {
		printf ("\nKhong the mo file.");
		exit (1);
	}
	bool a=false;
	for (int i=0;i<n;i++)
	{
	fprintf (f,"\n|%s\t|%s\t|%s\t|%.2f\t",(p+i)->mamay,(p+i)->tenmay,(p+i)->sosr,(p+i)->gia);
	a=true;
	}
	fclose (f);
	if (a) printf ("\n\nFile da duoc ghi tai ./maytinh1.txt");
	free(f);
}

int main()
{
	int n;
	char x[20];
	tt *p;
	p=(tt*)malloc(n*sizeof(tt));
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	nhaptt(p,n);
	intt(p,n);
	in3k(p,n);
	printf ("\n\nHay nhap vao x: ");
	fflush (stdin);
	gets (x);
	inmm(p,n,x);
	inFile(p,n);
	free(p);
	return 0;
}
