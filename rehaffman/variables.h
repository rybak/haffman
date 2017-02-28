#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>

struct
{
	short int l, r, p;
} tree[1000];//spisok uzlov

struct
{
	uc c;
	int64_t w;
	int i;
}alph[256];//v kakom uzle nohoditsya char c

struct
{
	int64_t w;
	int r;
}forest[1000];//les

unsigned short int K, t, t2;//K= kol-vo raznyh simvolov//t= kol-vo derev'ev v lesu//t2=kol-vo uslov v lesu

unsigned int kol[256];//kol-vo kazhdogo simvola v faile

unsigned int KOL, KOL2, KOLOUT;//kol-vo simvolov v faile
/*
const int buf_size=100;
const int buf_bitsize=buf_size*8;
*/
const char ErrorStr[50]="Error opening file!\nPress any key to continue...\n";
/*
unsigned char buf_out[buf_size*10],buf_in[buf_size];//vvod
*/
struct
{
	int size;
	uc code[256];
}codes[256];//kody simvolov


FILE *in, *out, *TESTF;//FILES

/*
long int bufs;
short int rest_in_bytes;//kol-vo v FILE *in
*/
int outc=0;//counters of FILE *in/*out//ukazatel' na tekuschii bit

int bor[600][3];
/*struct Tbor {
	int n[2];
	int c;
}bor;
*/
int borc=0;

long int beg=0;///tech bytes in begining of archibe
