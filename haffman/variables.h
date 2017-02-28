#ifndef VARIABLES_H
#define VARIABLES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// for int64_t
#include <cstdint>

struct {
	short int l,r,p;
} tree[1000];//spisok uzlov

struct {
	unsigned char c;
	// __int64 w;
	int64_t w;
	int i;
} alph[256]; //v kakom uzle nohoditsya char c

struct {
	// __int64 w;
	int64_t w;
	int r;
} forest[1000]; //les

unsigned short int K; // K = kol-vo raznyh simvolov // size of the alphabet
unsigned short int t; // t = kol-vo derev'ev v lesu
unsigned short int t2; // t2 = kol-vo uzlov v lesu
unsigned int kol[1000]; //kol-vo kazhdogo simvola v faile // why not 256?
unsigned int KOL; //kol-vo simvolov v faile // file size in bytes
// const char ErrorStr[50]="Error opening file!\nPress any key to continue...\n";
const char *ErrorStr = "Error opening file!\nPress any key to continue...\n";

struct{
	short int size;
	unsigned char code[256];
} codes[256]; //kody simvolov

FILE *in, *out, *TESTF; //FILES

long int bufs;

#endif
