#include <stdio.h>
#include <stdlib.h>

int nm (int *p, int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("a[%d] = ",i);
		scanf ("%d",&p[i]);
	}
}

int inm (int *p,int n)
{

	for (int i=0;i<n;i++)
	{
		printf ("   %d",p[i]);
	}
}

int amnn (int *p,int n)
{
	int amnn=p[0];
	int vt=0;
	for (int i=1;i<n;i++)
	{
		if (amnn>p[i])
		{
			vt = i;
			amnn = p[i];
		}
	}
	if (amnn<0) {
	printf ("\nVi tri am nho nhat la a[%d]",vt);
	printf ("\nGia tri am nho nhat la: %d",amnn);
}
	else printf ("\nKhong co gia tri am nho nhat");
}

int tima(int *p,int n, int a)
{
	int tg=0;
	bool tg1=false;
	for (int i=0;i<n;i++)
{
	if (a==p[i])
	{
		tg=i;
		tg1=true;
	}
}
if (tg1) 
printf ("Vi tri cua a trong day la: a[%d]",tg);
else printf ("Khong co a trong day");
}

bool ktrnt(int n)
{
    if (n < 2){
        return false;
    }       
    for (int i = 2; i < (n - 1); i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

int mdg (int *p,int n)
{
	int tg=p[0];
	for (int i=0;i<n;i++)
	for (int j=i+1;j<n;j++)
	{
		if (p[i]<p[j])
		{
			tg=p[i];
			p[i]=p[j];
			p[j]=tg;
		}
	}
}

int main()
{
	printf ("Hay nhap vao so phan tu: ");
	int n,*p,a;
	bool ktrnt1;
	p=(int*)malloc(n*sizeof(int*));
	scanf ("%d",&n);
	nm(p,n);
	printf ("Mang da nhap la:");
	inm(p,n);
	amnn (p,n);
	printf ("\nHay nhap vao a: ");
	scanf ("%d",&a);
	tima(p,n,a);
	printf ("\nCac so nguyen to trong day la:");
	for (int i = 0; i < n; i++) {
	if (ktrnt (p[i])){
	printf ("   %d",p[i]);
	}
}
	mdg(p,n);
	printf ("\nMang giam dan la: ");
	inm(p,n);
	return 0;
}
