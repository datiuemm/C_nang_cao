#include <stdio.h>
#include <math.h>

int CP(float a)
{
	float N;
	bool b;
	N=sqrt(a);
	if (N==(int)N)
	b=true;
	else 
	b=false;
	return b;
}
int main()
{
	float c;
	
	printf ("hay nhap vao a: ");
	scanf ("%f",&c);
	bool b=CP(c);
	if (b)
	printf ("a la so chinh phuong");
	else 
	printf("a kp la so chinh phuong");
	return 0;
}
