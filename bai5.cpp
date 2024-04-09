#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct date 
{
	int ngay, thang, nam;
};

struct ctmt {
	char mm[10];
	char tenmay[20];
	date nsx;
	char nhasx[20];
	float gia;
};

void nhaptt (ctmt *ds,int n)
{
	for (int i=0;i<n;i++)
	{	
	printf ("Hay nhap thong tin may thu: %d\n",i+1);
	printf ("Hay nhap ma may: ");
	fflush(stdin);
	gets ((ds+i)->mm);
	printf ("Hay nhap ten may: ");
	fflush(stdin);
	gets ((ds+i)->tenmay);
	printf ("Hay nhap ngay sx: ");
	fflush(stdin);
	scanf ("%d",&(ds+i)->nsx.ngay);
	printf ("Hay nhap thang sx: ");
	fflush(stdin);
	scanf ("%d",&(ds+i)->nsx.thang);
	printf ("Hay nhap nam sx: ");
	fflush(stdin);
	scanf ("%d",&(ds+i)->nsx.nam);
	printf ("Hay nhap nha sx: ");
	fflush(stdin);
	gets ((ds+i)->nhasx);
	printf ("Hay nhap gia: ");
	fflush(stdin);
	scanf ("%f",&(ds+i)->gia);
	fflush(stdin);
}
}
void inds(ctmt *ds,int n)
{
	for (int i=0;i<n;i++)
	{
	printf ("\n%s\t%s\t%d/%d/%d\t%s\t%.2f",(ds+i)->mm,(ds+i)->tenmay,(ds+i)->nsx.ngay,(ds+i)->nsx.thang,(ds+i)->nsx.nam,(ds+i)->nhasx,(ds+i)->gia);
	}
}

void inss(ctmt *ds, int n)
{
	printf ("\nCac may cua Samsung la: ");
	bool test= false;
	for (int i=0;i<n;i++)
	{
	if (strcmp(((ds+i)->nhasx), "Samsung") == 0)
	{
	printf ("\n%s\t%s\t%d/%d/%d\t%s\t%.2f",(ds+i)->mm,(ds+i)->tenmay,(ds+i)->nsx.ngay,(ds+i)->nsx.thang,(ds+i)->nsx.nam,(ds+i)->nhasx,(ds+i)->gia);
	test=true;
	}
	}
	if (test==false)
	{
		printf ("\nKhong co may tinh cua Samsung");
	}
}

void in2k(ctmt *ds, int n)
{
	bool test=false;
	printf ("\nNhung may tinh duoc sx nam 2020: ");
	for (int i=0;i<n;i++)
	{
		if (((ds+i)->nsx.nam)==2020)
		{
		printf ("\n%s\t%s\t%d/%d/%d\t%s\t%.2f",(ds+i)->mm,(ds+i)->tenmay,(ds+i)->nsx.ngay,(ds+i)->nsx.thang,(ds+i)->nsx.nam,(ds+i)->nhasx,(ds+i)->gia);
		test=true;
		}			
		}
		if (test == false) printf ("\nKhong co may tinh san xuat nam 2020");
	}
	
void ghiFile(ctmt *ds, int n) {
    FILE *file = fopen("maytinh.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        if ((ds+i)->gia > 2000) {
            fprintf(file, "\n%s\t%s\t%d/%d/%d\t%s\t%.2f",(ds+i)->mm,(ds+i)->tenmay,(ds+i)->nsx.ngay,(ds+i)->nsx.thang,(ds+i)->nsx.nam,(ds+i)->nhasx,(ds+i)->gia);
        }
    }
    fclose(file);
}

int main()
{
	int n;
	ctmt *ds;
	printf ("Nhap vao n (so may tinh): ");
	scanf ("%d",&n);
	ds=(ctmt*)malloc(n*sizeof(ctmt));
	nhaptt(ds,n);
	inds (ds,n);
	inss(ds,n);
	in2k(ds,n);
	ghiFile(ds,n);
	free(ds);
	return 0;
}
