#include <iostream>

using namespace std;

void SkipLine(int n);

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;
  SkipLine(n);
}

void SkipLine(int n) {
  int i = 1;
  while (i <= n) {
    if (i % 4 == 0 && i % 9 == 0) {
      cout << "SkipLine\n";
    } else if (i % 4 == 0) {
      cout << "Skip\n";
    } else if (i % 9 == 0) {
      cout << "Line\n";
    } else {
      cout << i << "\n";
    }
    i++;
  }
}