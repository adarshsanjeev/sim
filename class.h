#ifndef CLASS_H
#define CLASS_H

extern char RAM[256][1000];
extern int busval;                                /* Only Bus value */

class reg
{
 public:
  int val;
  void e();
  void l();
  void r();
};

class flagr
{
 public:
  int u;
  int z;
  int nz;
  int p;
  int m;
  int op;
  int ep;
  void flagupdate(int);     /* Parameter is result of ALU opr */
};

class stackpointer
{
 public:
  int val;
  int addr;
  stackpointer* link;
};

extern class reg pc;
extern class reg OR;
extern class reg AR;
extern class reg mar;
extern class reg rg[12];
extern class flagr flag;
extern class stackpointer* sp;

void initsim();                         /* To initialise the file */
void readsettings();                   /* To read from .settings file */
void cfile();                       /* To compile and copy the program */
void cmemfile();                 /* To compile and read the memfile */

#endif
