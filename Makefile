
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

test: haff rehaff test.txt test.sh
	./test.sh test.txt

.PHONY: test
