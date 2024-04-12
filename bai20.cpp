#include <stdio.h>
#include <stdlib.h>

void nhaptt(int *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao a[%d] = ",i);
		scanf ("%d",&p[i]);
	}
}

void intt(int *p,int n)
{

	for (int i=0;i<n;i++)
	{
		printf ("   %d",p[i]);
	}
}

void ktra(int *p,int n)
{
	bool a=false;
	for (int i=0;i<n;i++)
	for (int j=i+1;j<n;j++)
	{
		if (p[i] == p[j] )
		a=true;
	}
	if (a) printf ("\n\nCo hai so duong lien ke bang nhau");
	else printf ("\n\nKhong co hai so duong lien ke bang nhau");
}

void sapxep(int *p,int n)
{
	int tg=0;
	for (int i=0;i<n;i++)
	for (int j=i+1;j<n;j++)
	{
		if (p[i] < p[j])
		{
			tg=p[i];
			p[i]=p[j];
			p[j]=tg;
		}
	}
}

void inFile (int *p,int n)
{
	FILE *f=fopen("soduong20.txt","w");
	if (f == NULL)
	{
		printf ("\n\nKhong the mo file.");
		exit (1);
	}
	bool a=false;
		for (int i=0;i<n;i++)
	{
		if (p[i] > 0){
		
		fprintf (f,"%d   ",p[i]);
		a=true;
	}
	}
	fclose(f);
	if (a) printf ("\n\nFile da duoc ghi tai ./soduong20.txt");
	else printf ("\n\nKhong co gia tri duong de ghi file");
	

}

int main()
{
	int n,*p;
	printf ("Hay nhap vao n: ");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	nhaptt(p,n);
	printf ("\nMang da nhap la:");
	intt(p,n);
	ktra(p,n);
	sapxep(p,n);
	printf ("\n\nMang da duoc sap xep giam dan la:");
	intt(p,n);
	inFile(p,n);
	free(p);
	return 0;
}
