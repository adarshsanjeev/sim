#include<iostream>
#include"class.h"

using std::cin;
using std::cout;         // Necessary parts only
using std::endl;

void ALU(char);          // Parameter is the operand

int main(int argc,char *argv[])
{
  initsim();                // To load starting values and read .seeting file
  return 0;
}
