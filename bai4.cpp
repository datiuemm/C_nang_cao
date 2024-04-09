#include <stdio.h>
#include <stdlib.h>

int nhapmt(int *p,int n,int m){
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		printf ("Nhap vao a[%d][%d] = ",i,j);
		scanf ("%d",&p[i*m+j]);
	}
}

int inmt (int *p, int n,int m)
{
	for (int i=0;i<n;i++){
	printf ("\n");
	for (int j=0;j<m;j++)
	{
		printf ("%d\t",p[i*m+j]);
	}
}
}

float tbcle(int *p,int n,int m)
{
	float sum=0;
	bool a=false;
	int dem=0;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if ((p[i*m+j]) % 2 == 1) 	
		{
			sum += p[i*m+j];
			a = true;
			dem++;
		}
	}
	if (a)
	{
		printf ("\nTBC cac phan tu le la: %.2f",sum/dem);
	}
	else printf ("\nKhong co phan tu le");
}

int leln (int *p,int n,int m)
{
	int leln=0;
	bool a=false;
	for (int i=0;i<n;i++){
	if ((p[i*m+0] % 2 == 1)  && p[i*m+0]>leln) {
	leln=p[i*m+0];
	a=true;
	}
}
	if (a){
	printf ("\nSo le lon nhat tren cot 0 la: %d",leln);
	}
	else printf ("\nTren cot 0 khong co so le");
}


int sochan (int *p,int n,int m)
{
	printf ("\nCac so chan trong ma tran la: ");
	int dem=0;
	bool a=false;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		if ((p[i*m+j]) % 2 == 0) 	
		{
			printf ("   %d",(p[i*m+j]));
			dem++;
			a=true;
		}
		}
	if (a) printf ("\nCo %d so chan trong mang",dem);
	else printf ("Khong co so chan trong mang");
		
}

int sapxepk(int *p,int n,int m,int k)
{
	int tg = (p[k*m+0]);
	for (int j=0;j<m;j++)
	for (int d=j+1;d<m;d++)
	if ((p[k*m+j])>(p[k*m+d]))
	{
		tg=p[k*m+j];
		p[k*m+j]=p[k*m+d];
		p[k*m+d]=tg;
	}
	return 0;
}

//p[k*m+j]
int main()
{
	int n,m,*p,k;
	p=(int*)malloc(n*m*sizeof(int));
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	printf ("Hay nhap vao m: ");
	scanf ("%d",&m);
	nhapmt(p,n,m);
	inmt(p,n,m);
	tbcle(p,n,m);
	leln (p,n,m);
	sochan(p,n,m);
	printf ("\nHay nhap vao k: ");
	scanf ("%d",&k);
	sapxepk(p,n,m,k);
	printf ("\nMa tran voi hang %d duoc sap xep tang dan la:",k);
	inmt(p,n,m);
	free(p);
	return 0;
}
