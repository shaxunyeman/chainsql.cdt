NAME=kv_map
ABI=$(NAME).abi
SRC=$(NAME).cc
WASM=$(NAME).wasm
HEADER=$(NAME).wasm.h

FLAGS = -O3 --abigen -lrt -lsf

all: $(HEADER)

clean:
	rm -f $(HEADER) $(WASM) ${ABI}

.PHONY: all clean

$(WASM): $(SRC)
	chainsql-cpp $< -o $@ $(FLAGS)

$(HEADER): $(WASM)
	xxd -i $< >$@
