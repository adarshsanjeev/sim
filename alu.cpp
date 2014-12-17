#include<iostream>
#include"class.h"

/* ALU function:
  +=add
  -=sub
  &=and
  |=or
  ^=xor
  ~=cmp
  0=pass0

  IMPORTANT NOTE: AR.l() will never be used! ALU function automatically writes the ans to AR where necessary!

*/

int ALU(char opr)
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
    case '0':
      {
	ans=busval;
	AR.val=ans;
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
