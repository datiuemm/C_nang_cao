#include <stdio.h>
#include <stdlib.h>

int nm (int *p,int n, int m)
{
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		printf ("a[%d][%d] = ",i,j);
		scanf ("%d", &p[i*m+j]);
	}
}

int inm (int *p, int n,int m)
{
	for (int i=0;i<n;i++) {
	
	printf ("\n");
	for (int j=0;j<m;j++) 
	printf ("%d   ",p[i*m+j]);
}
}

float tbc (int *p,int n,int m)
{
	float tong=0;
	int dem=0;
	float tbc;
	for (int i=0;i<n;i++)
	for (int j=0;j<m;j++)
	{
		tong += p[i*m+j];
		dem++;
	}
	tbc = tong/dem;
	
	printf ("\nTBC cua cac so trong day la: %.2f",tbc);
	
}

void amln (int *p,int n,int m)
{
	int amln=p[0];
	for (int j=0;j<m;j++)
	{
		if (amln<p[j])
		amln=p[j];
	}
	if (amln<0) {
	printf ("\nGia tri am lon nhat la: %d",amln);
}
	else printf ("\nKhong co gia tri am nho nhat");
}
int main()
{
	int *p,n,m;
	p=(int*)malloc(n*m*sizeof(int));
	printf ("Hay nhap vao n: ");
	scanf ("%d", &n);
	printf ("Hay nhap vao m: ");
	scanf ("%d", &m);
	nm (p,n,m);
	inm (p,n,m);
	tbc(p,n,m);
	return 0;
}
