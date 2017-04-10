#ifndef MATRIX
#define MATRIX

//#include"CCity.h"

class CMatrix
{
private:
  int mN;
  int** mCMatrix;
  static CMatrix* sInstance;
public:
  static CMatrix& getInstance();
  static CMatrix& getInstance(int);
  //static void deleteInstance();
  ~CMatrix();
  int* CreateCity();
  //float GetDistBetween(const City&, const City&);
  void AfficheMatrix();
private:
  CMatrix();
  CMatrix(int);
};

#endif
