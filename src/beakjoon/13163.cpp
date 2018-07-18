#include <iostream>

using namespace std;

int main() {
    int TC;

    scanf("%d ", &TC);

    while (TC--) {
        string str;

        getline(cin, str);

        printf("god");

        int start = 0;

        for (start = 0; start < str.size(); start++)
            if (str[start] == ' ')
                break;

        for (start = start + 1; start < str.size(); start++) {
            if (str[start] == ' ')
                continue;

            printf("%c", str[start]);
        }

        printf("\n");
    }
}
