
all: haff rehaff

haff: haffman/*.cpp haffman/*.h
	cd haffman && make

rehaff: rehaffman/*.cpp rehaffman/*.h
	cd rehaffman && make

clean:
	rm -f haff rehaff
	cd haffman && make clean
	cd rehaffman && make clean
	rm -f test2.txt

test.txt:
	base64 /dev/urandom | head -c 10000000 > $@

test: haff rehaff test.txt
	./haff test.txt
	echo
	./rehaff test.txt.ch test2.txt
	echo
	diff --report-identical-files test.txt test2.txt

.PHONY: test
