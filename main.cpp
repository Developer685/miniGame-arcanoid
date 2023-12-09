#include <iostream>

#include "arcanoid.cpp"

using namespace std;

int main()
{
  ShowCursor(false);
  Menu elements;
  Objects racket;
  elements.gameFrame();
  elements.dataFrame();
  racket.move();
  return 0;
}
