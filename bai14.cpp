#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tt {
	char msv[20];
	char hoten[20];
	int namsinh;
	char lop[20];
	float dtk;
};

void nhaptt(tt *p,int n)
{
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao sinh vien thu %d",i+1);
		printf ("\nMa sinh vien: ");
		fflush(stdin);
		gets((p+i)->msv);
		printf ("Ho ten sinh vien: ");
		fflush(stdin);
		gets((p+i)->hoten);
		printf ("Nam sinh sinh vien: ");
		scanf ("%d",&(p+i)->namsinh);
		printf ("Lop sinh vien: ");
		fflush(stdin);
		gets((p+i)->lop);
		printf ("Diem tong ket sinh vien: ");
		scanf ("%f",&(p+i)->dtk);
	}
}


void intt(tt *p,int n)
{

	for (int i=0;i<n;i++)
	{

	printf ("\n%s\t|%s\t|%d\t|%s\t|%.2f\t|",(p+i)->msv,(p+i)->hoten,(p+i)->namsinh,(p+i)->lop,(p+i)->dtk);
}
}


void sxtd (tt *p,int n)
{
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (p[i].dtk > p[j].dtk) {
        tt temp = p[i];
        p[i] = p[j];
        p[j] = temp;
      }
    }
  }	
}

void svtkln (tt *p,int n)
{
	int temp;
	temp=n-1;
	printf ("\nSinh vien co diem trung binh cao nhat la: ");
	printf ("\n%s\t|%s\t|%d\t|%s\t|%.2f\t|",(p+temp)->msv,(p+temp)->hoten,(p+temp)->namsinh,(p+temp)->lop,(p+temp)->dtk);

}


void inFile(tt *p,int n)
{
	FILE *f=fopen("thilai.dat","w");
	if (f == NULL)
	{
		printf ("\nKhong the mo file.");
		exit(1);
		
	}
	bool a=false;
	for (int i=0;i<n;i++)
	{
		if ((p+i)->dtk < 5)
		{
		fprintf (f,"\n%s\t|%s\t|%d\t|%s\t|%.2f\t|",(p+i)->msv,(p+i)->hoten,(p+i)->namsinh,(p+i)->lop,(p+i)->dtk);
		a=true;	
		}
	}
	if (a) printf ("\nFile da duoc ghi tai ./thilai.dat");
	else printf ("\nKhong co sinh vien nao diem tong ket be hon 5");
}

int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p=(tt*)malloc(n*sizeof(tt));
	
	nhaptt(p,n);
	printf ("\n\nDanh sach da nhap la: ");
	intt(p,n);
	sxtd(p,n);
	printf ("\n\nDanh sach da sap xep la: ");	
	intt(p,n);
	svtkln(p,n);
	inFile(p,n);
	free(p);
	return 0;
	
}

