#ifndef INSTR_H
#define INSTR_H

void fetch();
void iopr(char);
void ret();
void nopr(char);
void movs();
void movd();
void movi();
void stor();
void load();
void push();
void pop();
void jumpd();
void jumpr();
void cd();
void cr();

#endif
