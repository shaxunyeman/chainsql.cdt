#include "chainsqlWasmVm.h"

namespace chainsql {

chainsqlWasmVm::chainsqlWasmVm(size_t stack_size_bytes, wasmImport* import) throw()
: env_()
, runtime_(env_.new_runtime(stack_size_bytes))
, import_(std::bind(&wasmImport::load, import, std::placeholders::_1)) {

}

chainsqlWasmVm::~chainsqlWasmVm() {

}

void chainsqlWasmVm::loadWasm(const uint8_t *data, size_t size) throw() {
    wasm3::module mod = env_.parse_module(data, size);
    runtime_.load(mod);
    import_(mod);
}

}
