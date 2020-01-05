#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
	int R; scanf("%d", &R);
	
	double ur = M_PI * (double)(R * R);
	double xr = ((R + R) * (R + R)) / (double)2;
	
	printf("%f\n%f\n", ur, xr);
	
	return 0;
}