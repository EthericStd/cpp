#include"CMatrice.h"
//#include"CMutation.h"


int main(int argc, char* argv[])
{
  CMatrix::getInstance(3)->AfficheMatrix();
  CMatrix::getInstance()->CreateCity();
  CMatrix::getInstance()->AfficheMatrix();
  return 0;
}
