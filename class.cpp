#include<iostream>
#include<stdlib.h>
#include"class.h"

int RAM[256];
int busval;
int CP;

class reg PC;
class reg OR;
class reg AR;
class reg MAR;
class reg RG[12];
class flagr FLAG;
class stackpointer* SP;

void initsim()
{
  CP=0;
  busval=0;
  PC.val=0;
  OR.val=0;
  AR.val=0;
  MAR.val=0;
  for(int i=0;i<12;i++)
    RG[i].val=0;
  FLAG.u=1;
  FLAG.z=1;
  FLAG.nz=0;
  FLAG.p=1;
  FLAG.m=0;
  FLAG.op=1;
  FLAG.ep=0;
  SP=(class stackpointer*)malloc(sizeof(class stackpointer));
  SP->val=0;
  SP->addr=255;
  SP->link=NULL;
  // readsettings();            //To read .settings file
  cout<<"Initialised..."<<endl; // For debugging
}
