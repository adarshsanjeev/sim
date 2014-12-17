#ifndef CLASS_H
#define CLASS_H

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;

extern int RAM[256];                              /* To store the compiled code*/
extern int busval;                                /* Only Bus value */

class reg                                         /* Main register class */
{
 public:
  int val;
  inline void e(){busval=val;}        // Functions declared here and as inline as they are small
  inline void l(){val=busval;}        //Just for usage
  inline void r(){val=0;}  
};

class flagr                                        /*Flag class*/
{
 public:
  int u;
  int z;
  int nz;
  int p;
  int m;
  int op;
  int ep;
  void flagupdate(int);                /* Parameter is result of ALU opr */
};

class stackpointer
{
 public:
  int val;
  int addr;
  stackpointer* link;
};

extern class reg PC;                       /*All object declarations */
extern class reg OR;
extern class reg AR;
extern class reg MAR;
extern class reg RG[12];
extern class flagr FLAG;
extern class stackpointer* SP;

inline void RD(int addr){busval=RAM[MAR.val];}
inline void WR(int addr){RAM[MAR.val]=busval;}

void initsim();                         /* To initialise the file */
int ALU(char);                           /*Parameter is the operand */
void readsettings();                   /* To read from .settings file */
int cfile();                       /* To compile and copy the program */
int cmemfile();                 /* To compile and read the memfile */

void printreg();                /* To print the contents of the registers */
void printmem();                /* To print the contents of the memory */

#endif
