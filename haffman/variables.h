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
long int kol[256];//kol-vo kazhdogo simvola v faile
__int64 KOL;//kol-vo simvolov v faile
const int buf_size=4096;
const int buf_bitsize=buf_size*8;
const char ErrorStr[50]="Error opening file!\nPress any key to continue...\n";

unsigned char buf_in[buf_size],buf_out[buf_size*8];//vvod

struct{short int size;unsigned char code[256];}codes[256];//kody simvolov

void *buf_out_pointer;
FILE *in,*out,*TESTF;//FILES

long int bufs;short int rest_in_bytes;
int outc=0;
