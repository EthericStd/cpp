#include"CMatrice.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>

using namespace std;

CMatrix* CMatrix::sInstance = NULL;

CMatrix* CMatrix::getInstance()
{
  if (sInstance == NULL) sInstance = new CMatrix();
  return sInstance;
};

CMatrix* CMatrix::getInstance(int pnb)
{
  if (sInstance == NULL) sInstance = new CMatrix(pnb);
  return sInstance;
};

/*void CMatrix::deleteInstance()
{
  ~CMatrice();
};*/

CMatrix::CMatrix()
{
  mN = 0;
  mCMatrix = 0;
};

CMatrix::CMatrix(int pNb)
{
  mN = pNb;
  mCMatrix = new int* [mN];
  for (int i=0; i<mN; i++)
  {
      mCMatrix [i] = new int [mN];
      for (int j=0; j<mN; j++)
      {
        mCMatrix[i][j] = 0;
      }
  }
};

CMatrix::~CMatrix()
{
  for (int i=0; i<mN; i++)
  {
    delete [] mCMatrix[i];
  }
  delete [] mCMatrix;
};

void CMatrix::AfficheMatrix()
{
  for (int i=0; i<mN; i++)
  {
    cout << "[ ";
    for (int j=0; j<mN; j++)
    {
      cout << mCMatrix[i][j] << " ";
    }
    cout << "]\n";
  }
  cout << "\n";
}

int* CMatrix::CreateCity()
{
  srand(time(NULL));
  int rdn = rand() % mN;
  int rdn2 = rand() % mN;
  while (mCMatrix[rdn][rdn2] != 0)
  {
    rdn = rand() % mN;
    rdn2 = rand() % mN;
  }
  mCMatrix[rdn][rdn2] = 1;
  int couple[2] = {rdn,rdn2};
  return couple;
};

/*float CMatrix::GetDistBetween(const City& C1, const City& C2)
{
  int* coordC1 = C1.get_coords();
  int* coordC2 = C2.get_coords();
  int diff_x, diff_y;

  if (coordC1[0] > coordC2[0]) diff_x = coordC1[0] - coordC2[0];
  else diff_x = coordC2[0] - coordC1[0];

  if (coordC1[1] > coordC2[1]) diff_y = coordC1[1] - coordC2[1];
  else diff_y = coordC2[1] - coordC2[1];

  return sqrt(pow(diff_x, 2) + pow(diff_y, 2));
}*/
