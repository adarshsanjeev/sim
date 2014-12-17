#include<iostream>
#include"class.h"

int ALU(char opr)        //Function to perform ALU oprations. + Sum - Min | OR & And ^ Xor ~ Cmp
{
  int ans;
  switch(opr)
    {
    case '+':
      {
	ans=busval+OR.val;
	AR.val=ans;
	break;
      }
    case '-':
      {
	ans=busval-OR.val;
	AR.val=ans;
	break;
      }
    case '|':
      {
	ans=busval|OR.val;
	AR.val=ans;
	break;
      }
    case '&':
      {
	ans=busval&OR.val;
	AR.val=ans;
	break;
      }
    case '^':
      {
	ans=busval^OR.val;
	AR.val=ans;
	break;
      }      
    case '~':
      {
	ans=busval-OR.val;
	break;
      }
    default:
      {
	cerr<<"ALU error: Unknown opr\n";
	return 1;
      }
    }
  FLAG.flagupdate(ans);
  return 0;
}

void flagr::flagupdate(int result)    //Function to update flag register
{
  if(result)
    nz=1;
  else nz=0;
  z=1-nz;
  if(result>=0)
    p=1;
  else
    p=0;
  m=1-p;
  op=1;
  while(result)
    {
      if(result&1)
  	op=1-op;
      result=result>>1;
    }
  ep=1-op;
}
