
../haff: haff
	cp haff ../haff

haff: haffman.cpp arh.h bufiz.h other.h tree.h variables.h
	g++ --std=c++11 -O2 -Wall haffman.cpp -o haff

clean:
	rm -f haff
