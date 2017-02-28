
../rehaff: rehaff
	cp $^ $@

rehaff: rehaff.cpp arh.h bufiz.h other.h tree.h variables.h
	g++ --std=c++11 -O2 -Wall rehaff.cpp -o $@

clean:
	rm -f rehaff
