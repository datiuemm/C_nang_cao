#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhapmt (int **p,int n)
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("a[%d][%d] = ", i, j);
      scanf("%d", &p[i][j]);
    }
  }
}

void inmt (int **p,int n)
{
	for (int i=0;i<n;i++)
	{
	printf ("\n");
	for (int j=0;j<n;j++)
	{
		printf ("%d\t",p[i][j]); 
	}
}
}

int tongcheo(int **p,int n)
{
	int sum=0;
	for (int i=0;i<n;i++)
	{
		sum += p[i][i];
	}	
	printf ("\nTong cac so tren duong cheo chinh la: %d",sum);
}

int tongh(int **p,int n,int h)
{
	int sum=0;
	for (int i=0;i<n;i++)
	{
		sum += p[i][h];
	}	
	printf ("Tong cot %d la: %d",h,sum);
}

void infile(int **p,int n)
{
	bool a=false;
	int dem=0;
	FILE *f=fopen("matran.txt","w");
	if (f==NULL)
	{
		printf ("\nLoi file.");
		exit(1);
	}
	fprintf (f,"%d\t",0);
	fprintf (f,"%d\t",0);
	  for (int i = 0; i < n; i++) 
      for (int j = 0; j < n; j++) {
    	if ((p[i][j]) % 2 == 0) {
		fprintf (f,"%d\t",p[i][j]);
		a=true;
		dem++;
	}
	}   
	fseek (f,0,SEEK_SET);
	fprintf (f,"%d\t",dem);
	fclose (f);
    if (a) printf ("\nFile da duoc ghi tai ./matran.txt");
    else printf ("\nKhong co so chan trong ma tran");

}


int DocTep() {
	int n=0;
	int *p1;

  	FILE *f = fopen("matran.txt", "r");
 	if (f == NULL) {
    printf("\nLoi file.");
    exit (1);
    }
    fscanf(f,"%d",&n);
    p1=(int*)malloc(n*sizeof(int));
    printf ("\n");
//    fseek (f,0,SEEK_SET);
    for(int i=0;i<n;i++)
    fscanf(f,"%d",(p1+i));
    fclose(f);
    printf ("Day so chan la: ");
	for(int i=0;i<n;i++)	printf("\t%d",p1[i]);
	return 0;
}

//int test() {
//    int n = 100;
//    int** matran = (int**)malloc(n * sizeof(int*));
//    int value = 1;
//    for (int i = 0; i < n; i++) {
//        matran[i] = (int*)malloc(n * sizeof(int));
//        for (int j = 0; j < n; j++) {
//        	value ++;
//            matran[i][j] = value ++;
//        }
//    }
//    printf("\nMa tran vua nhap:\n");
//    inmt(matran, n);
//    infile(matran, n);
//    printf("\nCac phan tu chan cua ma tran trong file matran.txt:\n");
//    DocTep();
//}

int main()
{
	int **p,n,h;
	test();
	printf ("Hay nhap vao n: ");
	scanf("%d",&n);
	p=(int**)malloc(n*sizeof(int*));
	for (int i=0;i<n;i++){
	p[i]=(int*)malloc(n*sizeof(int));
	}
	nhapmt(p,n);
	inmt(p,n);
	tongcheo(p,n);
	printf ("\nHay nhap vao h: ");
	scanf("%d",&h);	
	tongh(p,n,h);
	infile (p,n);
	DocTep();
	free(p);
	return 0;
}


