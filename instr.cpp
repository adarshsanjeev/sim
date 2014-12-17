#include<iostream>
#include"class.h"

void fetch()
{
  CP++;
  PC.e();MAR.l();PC.val++;
  CP++;
  RD();//MS.l()                   Not yet implemented
  //rom(RAM[PC.val]);  //this may eliminate IR and MS altogether. ROM function call
}

void iopr(char opr)
{
  CP++; 
  PC.e();MAR.l();PC.val++;
  CP++;
  RD();OR.l();
  CP++;
  AR.e();
  ALU(opr);
}

void nopr(char opr)
{
  CP++;
  RG[RAM[PC.val-26]].e();   // TODO Line to be improved to accept values like OR etc. also
  PC.val++;
  OR.l(); 
  CP++;
  AR.e(); ALU(opr);
}

void movs()
{
  CP++;
  RG[RAM[PC.val]-26].e();
  PC.val++;
  ALU('0');
}

void movd()
{
  CP++;
  AR.e();		
  RG[RAM[PC.val]-26].l();
  PC.val++;
}
