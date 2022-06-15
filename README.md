# chainsql.cdt (Contract Development Toolkit)
## Version : 1.0.0

 chainsql.cdt is a toolchain for WebAssembly (WASM) and set of tools to facilitate smart contract development for the chainsql platform. In addition to being a general purpose WebAssembly toolchain, [chainsql](https://gitlab.peersafe.cn/chainsql/chainsqld) specific optimizations are available to support building chainsql smart contracts.  This new toolchain is built around [Clang 7](https://gitlab.peersafe.cn/chainsql/chainsql_llvm), which means that chainsql.cdt has the most currently available optimizations and analyses from LLVM, but as the WASM target is still considered experimental, some optimizations are incomplete or not available.

## How to build from source code 
```sh
git clone --recursive https://gitlab.peersafe.cn/chainsql/chainsql.cdt
cd chainsql.cdt
mkdir build
cd build
cmake ..
make -j8
```

From here onward you can build your contracts code by simply exporting the `build` directory to your path, so you don't have to install globally (makes things cleaner).
Or you can install globally by running this command:

```sh
sudo make install
```

### Uninstall after manual installation

```sh
sudo rm -fr /usr/local/chainsql.cdt
sudo rm -fr /usr/local/lib/cmake/chainsql.cdt
sudo rm /usr/local/bin/chainsql-*
```

## Installed Tools
---
* chainsql-cpp
* chainsql-cc
* chainsql-ld
* chainsql-init
* chainsql-abidiff
* chainsql-wasm2wast
* chainsql-wast2wasm
* chainsql-ranlib
* chainsql-ar
* chainsql-objdump
* chainsql-readelf

## License

[MIT](../LICENSE)

## Important

See [LICENSE](./LICENSE) for copyright and license terms.

All repositories and other materials are provided subject to the terms of this [IMPORTANT](./IMPORTANT.md) notice and you must familiarize yourself with its terms.  The notice contains important information, limitations and restrictions relating to our software, publications, trademarks, third-party resources, and forward-looking statements.  By accessing any of our repositories and other materials, you accept and agree to the terms of the notice.
