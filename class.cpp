#include<fstream>
#include<iostream>
#include<string>
#include<stdlib.h>
#include"class.h"

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

int RAM[256][1000];
int busval;

class reg PC;
class reg OR;
class reg AR;
class reg MAr;
class reg RG[12];
class flagr FL;
class stackpointer* sp;

void initsim()
{
  busval=0;
  pc.val=0;
  OR.val=0;
  AR.val=0;
  mar.val=0;
  for(int i=0;i<12;i++)
    rg[i].val=0;
  flag.u=1;
  flag.z=1;
  flag.nz=0;
  flag.p=1;
  flag.m=0;
  flag.op=1;
  flag.ep=0;
  sp=(class stackpointer*)malloc(sizeof(class stackpointer));
  sp->val=0;
  sp->addr=255;
  sp->link=NULL;
  // readsettings();            //To read .settings
  cout<<"Initialised..."<<endl; // For debugging
}
