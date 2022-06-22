NAME=crowdfunding
ABI=$(NAME).abi
SRC=$(NAME).cc
WASM=$(NAME).wasm
HEADER=$(NAME).wasm.h
#EMCC_FLAGS=-O3 -Wl,--no-entry -Wl,--export=apply -Wl,--allow-undefined \
#			-s STANDALONE_WASM -s ERROR_ON_UNDEFINED_SYMBOLS=0 \
#			-std=c++17 \
#			-I ../ \
#			-I ../../vm/ \
#			-I ../../contract/ \
#			-I ../../libraries	\
#			-I ../../libraries/boost/include	\
#			-v

FLAGS = -O3 --abigen

all: $(HEADER)

clean:
	rm -f $(HEADER) $(WASM) ${ABI}

.PHONY: all clean

#$(WASM): $(SRC)
#	emcc $< -o $@ $(EMCC_FLAGS)

$(WASM): $(SRC)
	chainsql-cpp $< -o $@ $(FLAGS)

$(HEADER): $(WASM)
	xxd -i $< >$@
