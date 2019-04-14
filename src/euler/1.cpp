#include <iostream>
#include <set>

using namespace std;

set<int> a;

int main(void) {
    int limit = 1000;

    for (int i = 1; i * 3 < limit; i++) 
        a.insert(i * 3);

    for (int i = 1; i * 5 < limit; i++)
        a.insert(i * 5);

    int sum = 0;

    for (auto& item : a) 
        sum += item;

    printf("%d\n", sum);

    return 0;
}
