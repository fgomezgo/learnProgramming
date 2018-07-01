#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 500010;
const int MAX = 1234567;
 
int tree[MAX][26];
int sz = 2;
char key[N], inv_key[N];
char str[N];
int prv[26];
 
inline void insert(char * str) {
  int x = 1;
  for (int i = 0; str[i]; i++) {
    int y = str[i] - 'A';
    if (!tree[x][y]) {
      tree[x][y] = sz++;
    }
    x = tree[x][y];
  }
}
 
inline bool find(char * str) {
  int x = 1;
  for (int i = 0; str[i]; i++) {
    int y = str[i] - 'A';
    if (!tree[x][y]) {
      return false;
    }
    x = tree[x][y];
  }
  return true;
}
 
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  scanf("%s", key);
  for (int i = 0; i < m; i++) {
    inv_key[key[i] - 'A'] = 'A' + i;
  }
  for (int i = 0; i < n; i++) {
    // state[i] = i;
    prv[i] = i;
  }
  bool first = false;
  while (m--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%s", str);
      if (first) {
        for (int i = 0; str[i]; i++) {
          str[i] = inv_key[prv[str[i] - 'A']];
        }
      }
      insert(str);
    } else if (t == 2) {
      if (!first) {
        first = true;
        continue;
      }
      for (int i = 0; i < n; i++) {
        // state[i] = key[state[i]] - 'A';
        prv[i] = inv_key[prv[i]] - 'A';
      }
    } else if (t == 3) {
      scanf("%s", str);
      if (first) {
        for (int i = 0; str[i]; i++) {
          str[i] = inv_key[prv[str[i] - 'A']];
        }
      }
      if (find(str)) {
        puts("YES");
      } else {
        puts("NO");
      }
    } else {
      assert(0);
    }
  }
  return 0;
}