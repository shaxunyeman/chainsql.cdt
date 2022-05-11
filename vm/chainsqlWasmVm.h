#pragma once

#include <functional>

#include "wasm3_cpp.h"

namespace chainsql {

class wasmImport {
public:
    virtual void load(wasm3::module& module) = 0;
};

class chainsqlWasmVm
{
    using ImportFunction = std::function<void(wasm3::module& module)>;
private:
    wasm3::environment env_;
    wasm3::runtime runtime_;
    ImportFunction import_;
public:
    chainsqlWasmVm(size_t stack_size_bytes, wasmImport* import) throw();
    ~chainsqlWasmVm();
    
    void loadWasm(const uint8_t *data, size_t size) throw();

    template<typename Ret = void, typename ... Args>
    Ret invoke(const char* function, Args ...args) {
        wasm3::function fn = runtime_.find_function(function);
        return fn.call<Ret>(args...);
    }
};
} // namesapce chainsql

