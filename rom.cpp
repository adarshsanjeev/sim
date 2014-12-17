#include<iostream>
#include"class.h"
#include"instr.h"

void rom(int n)
{
  switch(n)
    {
    case 0:
      fetch();
      break;
    case 1:
      iopr('+');               // Immediate operation iopr
      break;		
    case 2:
      iopr('-');
      break;
    case 3:
      iopr('^');
      break;
    case 4:
      iopr('&');
      break;
    case 5:
      iopr('|');
      break;
    case 6:
      iopr('~');
      break;
    case 7:                                                       // STOP function
      CP++;                                                       // To be finished later  
      return;			
    case 8:
      // ret();                                                        return flag function
      break;	
    case 9:
      nopr('+');
      break;
    case 10:
      nopr('-');
      break;
    case 11:
      nopr('^');
      break;
    case 12:
      nopr('&');
      break;
    case 13:
      nopr('|');
      break;
    case 14:
      nopr('~');
      break;
    case 15:
      movs();
      break;
    case 16:
      movd();
      break;
    }
}
