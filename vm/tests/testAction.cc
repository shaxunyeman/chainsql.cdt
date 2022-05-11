#include <tuple>
#include <vm/action.h>
#include <vm/chainsqlWasmVm.h>

#include <contract/math/math.wasm.h>
#include <chainsql/core/datestream.h>

int main(int argc, char **argv) {
    std::tuple<int, int> args = std::make_tuple(100,200);
    std::string payload;
    payload.resize(2*sizeof(int));
    chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
    chainsql::action action(chainsql::name("math"), chainsql::name("add"), payload);
    chainsql::chainsqlWasmVm vm(1024, &action);
    vm.loadWasm(math_wasm, math_wasm_len);
    int ret = action.call(vm)
    return 0;
}