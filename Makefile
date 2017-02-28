
all: haff rehaff

haff: haffman/*.cpp haffman/*.h
	cd haffman && make

rehaff: rehaffman/*.cpp rehaffman/*.h
	cd rehaffman && make

clean:
	rm -f haff rehaff
	cd haffman && make clean
	cd rehaffman && make clean
	rm -f txt.test
	rm -f bin.test

txt.test:
	base64 /dev/urandom | head -c 10000000 > $@

test: txt.test test.sh haff rehaff
	./test.sh $<

bin.test:
	dd if=/dev/urandom of=$@ bs=10MB count=1

bin-test: bin.test test.sh haff rehaff 
	./test.sh $<

empty-test: empty-file.test test.sh haff rehaff
	./test.sh $<

tests: test bin-test empty-test
	echo "All tests finished"

.PHONY: test clean bin-test tests

