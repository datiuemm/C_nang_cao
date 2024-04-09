#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nhapmang (int *p,int n)
{
	int i;
	for (i=0;i<n;i++)
	{
		printf ("nhap vao a[%d] = ",i);
		scanf ("%d",&*(p+i));
	}
}
int inmang (int *p,int n)
{
	for (int i=0;i<n;i++) 
	printf ("   %d",*(p+i));
}

void amnn(int *p,int n)
{

    // number of indexes that contain the minimum value
    int dem = 0;

    // list of indexes that contain the minimum value
#if ALLOC
    int *ptr = malloc(sizeof(*ptr) * n);
#else
    int ptr[n];
#endif

    // current minimum value
    // start with a positive value to handle initial case
    int amnn = 1;

    // loop through all array elements
    for (int i = 0;  i < n;  ++i) {
        int gtht = p[i];

        // we only want negative values
        if (gtht >= 0)
            continue;

        // ignore values that are greater than the current minimum
        if (gtht > amnn)
            continue;

        // we have a new minimum value
        if (gtht < amnn) {
//			dem=0;

            // set new minimum value
            amnn = gtht;
        }

        // current value is part of the set of minimum values
        if (gtht == amnn)
            ptr[dem++] = i;
    }

    // print results
    do {
        if (amnn >= 0) {
            printf("\nkhong co so am");
            break;
        }

        printf("\nso am nho nhat la: %d",amnn);

        printf("\ncac vi tri so am nho nhat trong mang:");
        for (int dsnn = 0;  dsnn < dem;  ++dsnn)
            printf("  a[%d]",ptr[dsnn]);
    } while (0);

#if ALLOC
    free(ptr);
#endif
}
int ktrx (int *p,int n,int a)
{
	int tg,i,tg1;
	for (i=0;i<n;i++)
	{
		if (a==*(p+i)) {
		tg=i;
		tg1=1;
		break;
	}
	}
	if (tg1==1){	
	for(int i = tg; i < n - 1; i++)
    *(p+i) = *(p+i+1);
    --n;
	for (int i=0;i<n;i++) 
	printf ("   %d",*(p+i));
}
	else printf ("ma tran ko co a");
}

bool sochinhphuong(int n) {
int sqrtN = sqrt(n);
return (sqrtN * sqrtN == n);
}

int sapxeptangdan (int *p, int n)
{
	int tg;
	tg=*(p+0);
	for (int i=0;i<n;i++)
	for (int j=i+1;j<n;j++)
	if (*(p+i)>*(p+j))
	{
		tg=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=tg;
	}
	}
	
void infile (int *p,int n)
{
	bool test=false;
	int dem=0;
	FILE *f=fopen("mangthuc.txt","w");
	if (f == NULL) {
		printf ("\nKhong the mo file");
		return;
	}
	for (int i=0;i<n;i++)
	{
		if (p[i] > 0) 
		{
		fprintf (f,"%d",p[i]);
		dem++;
		test = true;
		}
	}
	fprintf (f,"%d",dem);
	if (test)	printf ("\nTep ./mangthuc.txt da duoc ghi nhung phan tu duong cua mang");  
	else printf ("\nKhong co phan tu duong de in");
	fclose(f);
}

void docin (int *p,int n)
{	FILE *f;//khai báo contro file
	//mo file, neu file chua ton tai = tao file
	f=fopen("dsd16tdh1.txt","r");
	//kiem tra file file
	if(f==NULL)
	{
		printf("loi mo file");
		exit(1);
		}
		int *ptr;
		int g,i;
	//doc du lieu n tu file f
		fscanf(f,"%d",&g);
		p=(int*)malloc(g*sizeof(int));
		for( i=0;i<n;i++)
	//doc du lieu mang tu file f
		fscanf(f,"%d",(ptr+i));
	//dong file
		fclose(f); 
	for( i=0;i<n;i++)
	//doc du lieu mang tu file f
		printf(" %d ",*(ptr+i));	
}

//void docin() {
//    FILE *f = fopen("mangthuc.txt", "r");
//    if (f == NULL) {
//        printf("\nKhong the mo file");
//        return;
//    }
//    int phanTu;
//    printf("\nNoi dung file mangthuc.txt:\n");
//    while (fscanf(f, "%d", &phanTu) == 1) {
//        printf("%d\t", phanTu);
//    }
//    fclose(f);

//FILE *f;
//f=fopen("mangthuc.txt","r");
//if (f == NULL) {
//	printf ("\nKhong the mo file");
//	exit (1);
//}
//int *p;
//p=(int*)malloc(sizeof(int));
//for (int i=0;i<100;i++)
//fscanf (f,"%d",p[i]);
//fclose (f);
//for (int i=0;i<100;i++) printf ("   %d",p[i]);
//}


int main()
{
	int *p, n,a;
	bool test=false;
	printf ("nhap vao n: ");
	scanf ("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	nhapmang (p,n);
	printf ("\nin ma tran:");
	inmang(p,n);
	amnn(p,n);
	sapxeptangdan(p,n);
	printf ("\nin ma tran tang dan: ");
	inmang(p,n);
	infile (p,n);
//	docin();
	printf ("\nso chinh phuong trong day la:");
	for (int i = 0; i < n; i++) {
	if (sochinhphuong (*(p+i))){
	printf ("   %d",*(p+i));;
	test=true;
	}
	}
	if (test == false) printf (" Khong co so chinh phuong trong day");
	printf ("\nnhap vao a de xoa: ");
	scanf ("%d",&a);
	printf ("in ma tran da duoc xoa phan tu: ");
	ktrx (p,n,a);
	free (p);
	return 0;
}

