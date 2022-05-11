#include <iostream>
#include <tuple>
#include <chainsqlWasmVm.h>

#include "chainsqlib/core/name.h"
#include "chainsqlib/core/datastream.h"
#include "vm/action.h"

#include "contract/math/math.wasm.h"

int main(int argc, char** argv) {
    try {
        // serilize args
        std::tuple<int, int> args = std::make_tuple(100,200);
        std::string payload;
        payload.resize(2*sizeof(int));
        chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
        ds << args;

        // invoke an action
        chainsql::action<int> action(chainsql::name("math"), chainsql::name("add"), payload);
        chainsql::chainsqlWasmVm vm(1024, &action);
        vm.loadWasm(math_wasm, math_wasm_len);
        int ret = action.call(vm);

        std::cout << "action result = " << ret << std::endl;
    }
    catch (std::runtime_error &e)
    {
        std::cerr << "WASM3 error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
