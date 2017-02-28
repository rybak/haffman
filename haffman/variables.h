#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct {
	short int l,r,p;
}tree[1000];//spisok uzlov
struct {unsigned char c;__int64 w;int i;}alph[256];//v kakom uzle nohoditsya char c
struct {__int64 w;int r;}forest[1000];//les
unsigned short int K,t,t2;//K= kol-vo raznyh simvolov//t= kol-vo derev'ev v lesu//t2=kol-vo uslov v lesu
unsigned int kol[1000];//kol-vo kazhdogo simvola v faile
unsigned int KOL;//kol-vo simvolov v faile
const char ErrorStr[50]="Error opening file!\nPress any key to continue...\n";

struct{short int size;unsigned char code[256];}codes[256];//kody simvolov

FILE *in,*out,*TESTF;//FILES

long int bufs;
