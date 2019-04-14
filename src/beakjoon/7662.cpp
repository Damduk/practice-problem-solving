#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <functional>
#define P 1
#define N -1

using namespace std;

typedef priority_queue<int> pq;
typedef map<int, int> mii;

int T, K;
char OP;
int IN;

pq pset;
priority_queue <int, vector<int>, greater<int>> nset;

mii pcache, ncache;

void ensureQ(int d) {
   if (d == P) {
      while (pset.size() && pcache[pset.top()] > 0) {
         int top = pset.top();

         pset.pop();

         pcache[top]--;
      }
   }
   else {
      while (nset.size() && ncache[nset.top()] > 0) {
         int top = nset.top();

         nset.pop();

         ncache[top]--;
      }
   }
}

void remove(int d) {
   ensureQ(d);

   if (d == P) {
      if (pset.empty())
         return;

      int top = pset.top();

      pset.pop();

      ncache[top]++;
   }
   else {
      if (nset.empty())
         return;

      int top = nset.top();

      nset.pop();

      pcache[top]++;
   }
}

void print() {
   if (pcache.size() < ncache.size()) {
      ensureQ(P);

      if (pset.empty()) {
         printf("EMPTY\n");
         return;
      }

      ensureQ(N);
   } else {
      ensureQ(N);

      if (nset.empty()) {
         printf("EMPTY\n");
         return;
      }

      ensureQ(P);
   }

   printf("%d %d\n", max(pset.top(), nset.top()), min(pset.top(), nset.top()));
}

int main(void) {
#ifdef local
   freopen("D.in.txt", "r", stdin);
#endif
   scanf("%d", &T);

   while (T--) {
      pset = pq();
      nset = priority_queue<int, vector<int>, greater<int>>();
      
      pcache = mii();
      ncache = mii();
      
      scanf("%d", &K);

      while (K--) {
         scanf(" %c %d", &OP, &IN);

         if (OP == 'I') {
            pset.push(IN);
            nset.push(IN);
         }
         else {
            remove(IN);
         }
      }

      print();
   }

   return 0;
}
