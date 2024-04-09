#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct date {
	int ngay,thang,nam;
};

struct tt{
	char sbd[20];
	char ten[20];
	date ngaysinh;
	char que[20];
	float tongdiem;
};

void nhaptt (tt *p, int n)  {
	for (int i=0;i<n;i++)
	{
		printf ("Hay nhap vao thi sinh thu %d",i+1);
		printf ("\nHay nhap vao so bao danh thi sinh thu %d: ",i+1);
		fflush (stdin);
		gets ((p+i)->sbd);
		printf ("Hay nhap vao ten thi sinh thu %d: ",i+1);
		fflush (stdin);
		gets ((p+i)->ten);
		printf ("Hay nhap vao ngay sinh thi sinh thu %d: ",i+1);
		scanf ("%d",&(p+i)->ngaysinh.ngay);
		printf ("Hay nhap vao thang sinh thi sinh thu %d: ",i+1);
		scanf ("%d",&(p+i)->ngaysinh.thang);
		printf ("Hay nhap vao nam sinh thi sinh thu %d: ",i+1);
		scanf ("%d",&(p+i)->ngaysinh.nam);
		printf ("Hay nhap vao que cua thi sinh thu %d: ",i+1);
		fflush (stdin);
		gets ((p+i)->que);
		printf ("Hay nhap vao tong diem cua sinh thi sinh thu %d: ",i+1);
		scanf ("%f",&(p+i)->tongdiem);
	}
}

void intt (tt *p,int n){
	printf ("\n");
	printf ("\n");
	printf ("_________________________________________________________________");
	printf ("\n|STT\t|SBD\t|Ten\t|Ngay sinh\t|Que quan\t|T.Diem\t|");
	printf ("\n_________________________________________________________________");
	
	for (int i=0;i<n;i++)
	{
		printf ("\n|%d\t|%s\t|%s\t|%d/%d/%d\t|%s\t|%.2f\t|",i+1,(p+i)->sbd,(p+i)->ten,(p+i)->ngaysinh.ngay,(p+i)->ngaysinh.thang,(p+i)->ngaysinh.nam,(p+i)->que,(p+i)->tongdiem);
		printf ("\n-----------------------------------------------------------------");
	}
	printf ("\n");
	printf ("\n");
}

int main()
{
	int n;
	printf ("Hay nhap vao n: ");
	scanf ("%d",&n);
	tt *p;
	p=(tt*)malloc(n*sizeof(tt));
	nhaptt(p,n);
	intt(p,n);
}
