#include <bits/stdc++.h>

int main() {
  srandom(time(NULL)); 
  int n = rand()%4 + 4;
  std::cout << n << std::endl;
  n = rand()%20 + n;
  std::string s;
  char str[4] = {'A', 'H', 'I', 'O'};
  while(n--) s += str[rand()%4];
  std::cout << s << std::endl;
  return 0;
}
