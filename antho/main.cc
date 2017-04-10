#include"CMatrice.h"


int main(int argc, char* argv[])
{
  CMatrix Mat = CMatrix::getInstance(3);
  Mat.AfficheMatrix();
  return 0;
}
