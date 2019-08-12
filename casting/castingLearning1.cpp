/*Learning Link

https://docs.microsoft.com/en-us/cpp/cpp/casting-operators?view=vs-2019
*/

#include <iostream>

class BaseTest
{


  int _param;

public:
    BaseTest (int param):_param (param)
  {
  }
  virtual int getParam ()
  {
    return _param;
  }
  void increment()
  {
      _param = _param +10;
  }
};

class DerivedTest:public BaseTest
{
  int _param;
public:
    DerivedTest (int param):BaseTest (param), _param (param)
  {

  }
  virtual int getParam () override 
  {
    return _param;
  }
  void increment()
  {
      _param = _param +10;
  }
};

class RandomTest
{
    int _param;
    public :
     RandomTest(int param):_param(param)
     {
         
     }
     int getParam()
     {
        return _param;
     }
};

using namespace std;

int
main ()
{
  BaseTest baseObj (100);
  DerivedTest derivedObj (200);
  
  cout << "Base = " << baseObj.getParam () << endl;
  cout << "Derived = " << derivedObj.getParam () << endl;
  
  constexpr int numberOfRecords = 50;
  
  BaseTest * base1 = new BaseTest(10);
  DerivedTest * derived1 = new DerivedTest(20);
  
  
  cout << "Base 1 = " << base1->getParam ()<< endl;
  cout << "Derived 1 = " << derived1->getParam ()<< endl;

  
  base1 = dynamic_cast<BaseTest*>(derived1);
  cout << "Base 1 = " << base1->getParam ()<< endl;
  
  BaseTest *  derivedTwo = new DerivedTest(30);
  cout << "derivedTwo = " << derivedTwo->getParam ()<< endl;
  derivedTwo->increment();
  cout << "derivedTwo = " << derivedTwo->getParam ()<< endl;
  
  DerivedTest * derivedThree = static_cast<DerivedTest*>(derivedTwo);
  cout << "derivedThree = " << derivedThree->getParam ()<< endl;
  derivedThree->increment();
  cout << "derivedThree = " << derivedThree->getParam ()<< endl;
  
  return 0;
}

