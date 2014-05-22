browser: src/quicksand.c src/quicksandwrap.js
	mkdir -p lib
	emcc src/quicksand.c -o lib/quicksand.js -O3 -s EXPORTED_FUNCTIONS="['_fill_sandpile', '_print_sandpile', '_update_sandpile', '_get_identity']" -s TOTAL_MEMORY=134217728
	cp src/quicksandwrap.js lib/quicksandwrap.js

cli: src/quicksand.c
	clang src/quicksand.c -o quicksand
