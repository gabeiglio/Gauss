
gauss:
	clang src/gauss.c src/main.c -o build/gauss && build/./gauss

clean:
	rm -rf build && mkdir build

tests:
	echo not yet implemented
