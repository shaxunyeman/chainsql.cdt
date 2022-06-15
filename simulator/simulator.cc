#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <exception>

#include "simulator/vm/chainsqlWasmVm.h"
#include "simulator/vm/actionCallback.h"
#include "simulator/common/name.h"
#include "simulator/common/datastream.h"
#include "simulator/vm/imports/print.h"
#include "simulator/vm/imports/map.h"
#include "simulator/vm/imports/system.h"

#include "contract/hello/hello.wasm.h"
#include "contract/math/math.wasm.h"
#include "contract/kv_map/kv_map.wasm.h"

struct contract {
    std::string name;
    std::string function;
    std::string payload;
    const uint8_t* wasm;
    size_t wasm_size;
};

std::vector<char> execute_contract(const struct contract &c)
{
    // initailize an action
    chainsql::action action(
        chainsql::name(c.name), 
        chainsql::name(c.function), 
        c.payload);

    chainsql::chainsqlWasmVm vm(8192);
    wasm3::module mod = vm.loadWasm(c.wasm, c.wasm_size);

    chainsql::link_system(mod);
    chainsql::link_print(mod);
    chainsql::link_map(mod);

    // import functions to a specified action
    chainsql::actionCallback cb(action, mod);
    // invoke an action
    return  vm.apply(&cb);
}

void execute_hello_contract()
{
    auto hello_contract = [&](const std::string &name, const std::string &payload) -> std::vector<char> 
    {
        struct contract hello = {
            "hello",
            name,
            payload,
            hello_wasm,
            hello_wasm_len};

        return execute_contract(hello);
    };

    std::string payload;
    payload.resize(1024);
    chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
    ds << "peersafe. I'm mr hello.";

    hello_contract("hi", payload);
}

void execute_math_contract()
{
    auto math_contract = [&](const std::string &name, const std::string &payload) -> int 
    {
        struct contract math = {
            "math",
            name,
            payload,
            math_wasm,
            math_wasm_len};

        auto vec = execute_contract(math);
        int ret;
        std::memcpy(&ret, &vec[0], sizeof ret);
        return ret;
    };

    std::string payload;
    payload.resize(2 * sizeof(int));
    int a = 100;
    int b = 200;
    chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
    ds << a;
    ds << b;

    // test add in math
    int ret = math_contract("add", payload);
    assert(ret == 300);
    std::cout << "invoke math.add successfully. " << std::endl;

    // test mult in math
    ret = math_contract("mult", payload);
    assert(ret == 20000);
    std::cout << "invoke math.mult successfully. " << std::endl;
}

struct person
{
    std::string name;
    std::string title;
    int age;
};

template <typename DataStream>
inline DataStream &operator<<(DataStream &ds, const person &p)
{
    ds << p.name << p.title << p.age;
    return ds;
}

template <typename DataStream>
inline DataStream &operator>>(DataStream &ds, person &p)
{
    ds >> p.name >> p.title >> p.age;
    return ds;
}

void execute_kv_map_contract() {
   auto kv_map_contract = [&](const std::string &name, const std::string &payload) -> std::vector<char>
    {
        struct contract kv_map = {
            "kv.map",
            name,
            payload,
            kv_map_wasm,
            kv_map_wasm_len};

        return execute_contract(kv_map);
    };

    kv_map_contract("testkvmap", "");
    std::cout << "invoke kv_map.testkvmap successfully" << std::endl;
    kv_map_contract("testarray", "");
    std::cout << "invoke kv_map.testarray successfully" << std::endl;

    {
        person p1 = {"zhangxiaofei", "actor", 30};
        std::string payload;
        payload.resize(1024);
        chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
        ds << 3;
        ds << p1.name << p1.title << p1.age;
        kv_map_contract("insert", payload);
    }

    {
        person p1 = {"guodegang", "freetalker", 50};
        std::string payload;
        payload.resize(1024);
        chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
        ds << 4;
        ds << p1.name << p1.title << p1.age;
        kv_map_contract("insert", payload);
    }

    {
        std::string payload;
        payload.resize(4);
        chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
        ds << 3;
        auto vec = kv_map_contract("get", payload);
        person p = chainsql::unpack<person>(vec.data(), vec.size());
        assert(p.name == "zhangxiaofei" && p.title == "actor" && p.age == 30);
    }

    {
        std::string payload;
        payload.resize(4);
        chainsql::datastream<char *> ds = chainsql::datastream<char *>(payload.data(), payload.size());
        ds << 4;
        auto vec = kv_map_contract("get", payload);
        person p = chainsql::unpack<person>(vec.data(), vec.size());
        assert(p.name == "guodegang" && p.title == "freetalker" && p.age == 50);
    }
}

int main(int argc, char** argv) {
    try {
        execute_hello_contract();
        execute_math_contract();
        execute_kv_map_contract();
    }
    catch (wasm3::error &e)
    {
        std::cerr << "WASM3 error: " << e.what() << std::endl;
        return 1;
    }
    catch(std::exception& e) {
        std::cerr << "other error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
