#include <bits/stdc++.h>

int n, m;

int isnum(std::vector<std::string>& pic, int i, int j) {
  if(n-i > 4 && m-j > 2) { // horizontal 2
    if(      pic[i].substr(j, 3) == "###"
        && pic[i+1].substr(j, 3) == "..#"
        && pic[i+2].substr(j, 3) == "###"
        && pic[i+3].substr(j, 3) == "#.."
        && pic[i+4].substr(j, 3) == "###") {
      pic[i].replace(j, 3, "...");
      pic[i+1].replace(j, 3, "...");
      pic[i+2].replace(j, 3, "...");
      pic[i+3].replace(j, 3, "...");
      pic[i+4].replace(j, 3, "...");
      return 2;
    } 
  }
  if(n-i > 2 && m-j > 4) { // vertical 2
    if(     pic[i].substr(j, 5) == "###.#"
       && pic[i+1].substr(j, 5) == "#.#.#"
       && pic[i+2].substr(j, 5) == "#.###") {
      pic[i].replace(j, 5, "....."); 
      pic[i+1].replace(j, 5, "....."); 
      pic[i+2].replace(j, 5, "....."); 
      return 2;
    }
  }
  if(n-i > 6 && m-j > 3) { //horizontal 5
     if(     pic[i].substr(j, 4) == "####"
        && pic[i+1].substr(j, 4) == "#...,"
        && pic[i+2].substr(j, 4) == "#...,"
        && pic[i+3].substr(j, 4) == "####"
        && pic[i+4].substr(j, 4) == "...#"
        && pic[i+5].substr(j, 4) == "...#"
        && pic[i+6].substr(j, 4) == "####") {
      pic[i].replace(j, 4, "...."); 
      pic[i+1].replace(j, 4, "...."); 
      pic[i+2].replace(j, 4, "...."); 
      pic[i+3].replace(j, 4, "...."); 
      pic[i+4].replace(j, 4, "...."); 
      pic[i+5].replace(j, 4, "...."); 
      pic[i+6].replace(j, 4, "...."); 
      return 5;
     } 
  }
  if(n-i > 3 && m-j > 6) { // vertical 5
    if(     pic[i].substr(j, 7) == "#..####"
       && pic[i+1].substr(j, 7) == "#..#..#"
       && pic[i+2].substr(j, 7) == "#..#..#"
       && pic[i+3].substr(j, 7) == "####..#") {
      pic[i].replace(j, 7, ".......");   
      pic[i+1].replace(j, 7, ".......");   
      pic[i+2].replace(j, 7, ".......");   
      pic[i+3].replace(j, 7, ".......");   
      return 5;
    }
  }
  return 0;
}

int main() {
  int T;
  scanf("%d", &T);
  while(T--) {
    int n2 = 0, n5 = 0;
    scanf("%d%d", &n, &m); 
    std::vector<std::string> pic;
    std::string str;
    for(int i = 0; i < n; ++i) {
      std::cin >> str;
      pic.push_back(str);
    }
    for(int i = 0; i < n; ++i)
      for(int j = 0; j < m; ++j) {
        if(pic[i][j] == '.') continue;
        int x = isnum(pic, i, j);
        if(x == 2) ++n2;
        else if(x == 5) ++n5;
      }
    std::cout << n2 << " " << n5 << std::endl;
  }
  return 0;
}
