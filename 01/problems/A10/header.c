#include <inttypes.h>
#include <stdio.h>


int extractExp(float f);

int main()
{
	float f;
	scanf("%f",&f);
	int res = extractExp(f);
	printf("%d",res);
	return 0;
}
