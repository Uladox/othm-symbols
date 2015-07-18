
.PHONY : clean test install uninstall

clean :
	-rm test
test :
	gcc -static -g -o test test.c -lothm_hashmap
	./test
install :
	cp othm_symbols.h /usr/include/
uninstall :
	-rm /usr/include/othm_symbols.h
