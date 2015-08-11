all: libothm_symbols.so

libothm_symbols.so: othm_symbols.o
	gcc -shared -o libothm_symbols.so othm_symbols.o

othm_symbols.o: othm_symbols.c othm_symbols.h
	gcc -c -Wall -Werror -fPIC othm_symbols.c -o othm_symbols.o

.PHONY : clean test install uninstall

clean :
	-rm -f test othm_symbols.o libothm_symbols.so test.o test2.o
test :
	gcc -c test.c
	gcc -c test2.c
	gcc -Wall -o test test.o test2.o -lothm_symbols -lothm_hashmap
	./test
install :
	cp othm_symbols.h     /usr/include/
	cp libothm_symbols.so /usr/lib/
uninstall :
	-rm -f /usr/include/othm_symbols.h
	-rm -f /usr/lib/libothm_symbols.so
