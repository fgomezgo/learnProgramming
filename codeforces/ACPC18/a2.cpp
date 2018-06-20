#include <bits/stdc++.h>
using namespace std;

struct node {
  int a, b, c;
  node() {}
  node(int a, int b, int c):
    a(a), b(b), c(c) {}
  bool operator < (const node & n) const {
    return a < n.a;
  }
};

int const N = 1e5 + 10;
int t, n, x;
long long cs[N];
node a[N];

int main() {
  scanf("%d", & t);
  while (t-- != 0) {
    scanf("%d %d", & n, & x);
    for (int i = 1; i <= n; ++i)
      scanf("%d %d %d", & a[i].a, & a[i].b, & a[i].c);
    ++n;
    a[n] = node(-1, -1, 0);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
      cs[i] = 1ll * (a[i].b - a[i].a + 1) * a[i].c + cs[i - 1];
    long long best = 0;
    for (int i = 1, nw; i <= n; ++i) {
      nw = a[i].a + x - 1;
      int idx = upper_bound(a + 1, a + n + 1, node(nw, 2e9, 2e9)) - a;
      --idx;
      if (nw >= a[idx].b)
        best = max(best, cs[idx] - cs[i - 1]);
      else
        best = max(best, cs[idx - 1] - cs[i - 1] + 1ll * (nw - a[idx].a + 1) * a[idx].c);
    }
    for (int i = n, nw; i > 0; --i) {
      nw = max(0, a[i].b - x + 1);
      int idx = upper_bound(a + 1, a + n + 1, node(nw, 2e9, 2e9)) - a;
      --idx;
      if (nw <= a[idx].a)
        best = max(best, cs[i] - cs[idx - 1]);
      else
        best = max(best, cs[i] - cs[idx] + 1ll * (a[idx].b - nw + 1) * a[idx].c);
    }
    printf("%lld\n", best);
  }
  return 0;
}