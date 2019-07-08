#include <iostream>
#include <string>
#include <vector>

using namespace std;

int union_set[100001];

char GetType(string &type, int i) { return type[i - 1]; }

int main() {
  int n, m;
  string type;
  vector<int> result;

  cin >> n >> m;
  cin >> type;

  for (int i = 1; i <= n; i++) {
    union_set[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int s, e;

    cin >> s >> e;

    if (GetType(type, s) != GetType(type, e) && union_set[s] != union_set[e]) {
      int previous = union_set[e];

      for (int j = 1; j <= n; j++) {
        if (union_set[j] == previous) {
          union_set[j] = union_set[s];
        }
      }

      result.push_back(i + 1);
    }
  }

  cout << result.size() << endl;
  for (int each : result) {
    cout << each << " ";
  }
  cout << endl;

  return 0;
}
