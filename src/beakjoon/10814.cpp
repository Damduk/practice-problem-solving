#include <cstdio>
#include <algorithm>

using namespace std;

const int PLAYER_MAX = 100001;
const int NAME_MAX = 101;

typedef struct player {
    int id;
    int age;
    char name[NAME_MAX];
    
    bool operator<(const player& a) const {
        if (age == a.age)
            return id < a.id;
        
        return age < a.age;
    }
} Player;

Player arr[PLAYER_MAX];

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        Player p = { i + 1 };
        
        scanf("%d %s", &p.age, p.name);
        
        arr[i] = p;
    }
    
    sort(arr, arr + n);
    
    for (int i = 0; i < n; i++)
        printf("%d %s\n", arr[i].age, arr[i].name);
}