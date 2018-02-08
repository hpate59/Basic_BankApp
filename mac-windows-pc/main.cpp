/*main.cpp*/

//
// Banking program in modern C++.
//
// <<YOUR NAME>>
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 01
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "customer.h"

using namespace std;


int main()
{
  string  customerFilename, transactionsFilename;

  cin >> customerFilename;
  cout << customerFilename << endl;
  
  cin >> transactionsFilename;
  cout << transactionsFilename << endl;

  ifstream  custFile(customerFilename);
  ifstream  txFile(transactionsFilename);

  cout << std::fixed;
  cout << std::setprecision(2);

  if (!custFile.good())
  {
    cout << "**ERROR: cannot open customers file: '" << customerFilename << "'" << endl;
    return -1;
  }
  if (!txFile.good())
  {
    cout << "**ERROR: cannot open transactions file: '" << transactionsFilename << "'" << endl;
    return -1;
  }
    
 
  // 
  // TODO
  //
 
 
   return 0;
}
