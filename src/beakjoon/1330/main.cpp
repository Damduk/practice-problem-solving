#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int A, B; 
	
	scanf("%d %d", &A, &B);

	string result;
	if (A > B) {
		result = ">";
	} else if (A < B) {
		result = "<";
	} else {
		result = "==";
	}

	printf("%s\n", result.c_str());
		
	return 0;
}
