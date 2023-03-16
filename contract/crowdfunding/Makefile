NAME=crowdfunding
ABI=$(NAME).abi
SRC=$(NAME).cc
WASM=$(NAME).wasm
HEADER=$(NAME).wasm.h

CC=gcc
WASM2CODE=wasm2code
#EMCC_FLAGS=-O3 -Wl,--no-entry -Wl,--export=apply -Wl,--allow-undefined \
#			-s STANDALONE_WASM -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
#			-std=c++17 \
#			-I ../ \
#			-I ../../vm/ \
#			-I ../../contract/ \
#			-I ../../libraries	\
#			-I ../../libraries/boost/include	\
#			-v

FLAGS = -O3 --abigen -lrt -lsf

all: $(HEADER) print

print: $(WASM2CODE)
	$(info $(shell ./$(WASM2CODE)))

clean:
	rm -f $(HEADER) $(WASM) $(ABI) $(WASM2CODE)

.PHONY: all clean

#$(WASM): $(SRC)
#	emcc $< -o $@ $(EMCC_FLAGS)

$(WASM): $(SRC)
	chainsql-cpp $< -o $@ $(FLAGS)

$(HEADER): $(WASM)
	xxd -i $< >$@

$(WASM2CODE): $(WASM2CODE).c $(HEADER)
	$(CC) $< -o $@

