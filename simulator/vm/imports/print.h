#pragma once

#include <iostream>
#include <string>
#include <functional>

#include <wasm3_cpp.h>

namespace chainsql {
    std::function<void(const char *)> prints = [](const char *msg)
    {
        std::string s(msg);
        std::cout << s;
    };

    std::function<void(const char *, uint32_t)> prints_l = [](const char *msg, uint32_t len)
    {
        std::string s(msg, len);
        std::cout << s;
    };

    std::function<void(int64_t)> printi = [](int64_t i)
    {
        std::cout << i;
    };

    std::function<void(uint64_t)> printui = [](uint64_t i)
    {
        std::cout << i;
    };

    std::function<void(const void /*int128_t*/ *)> printi128 = [](const void /*int128_t*/ *v)
    {
        using int128_t = int32_t[4];
        int128_t i;
        memcpy(&i, v, sizeof(i));
        std::cout << "[0]" << i[0]
                  << "[1]" << i[1]
                  << "[2]" << i[2]
                  << "[3]" << i[3]
                  << std::endl;
    };

    std::function<void(const void /*uint128_t*/ *)> printui128 = [](const void /*uint128_t*/ *v)
    {
        using uint128_t = uint32_t[4];
        uint128_t i;
        memcpy(&i, v, sizeof(i));
        std::cout << "[0]" << i[0]
                  << "[1]" << i[1]
                  << "[2]" << i[2]
                  << "[3]" << i[3]
                  << std::endl;
    };

    std::function<void(float)> printsf = [](float f)
    {
        std::cout << f;
    };

    std::function<void(double)> printdf = [](double d)
    {
        std::cout << d;
    };

    std::function<void(const void /*long double*/ *)> printqf = [](const void /*long double*/ *p)
    {
        std::cout << p;
    };

    std::function<void(uint64_t)> printn = [](uint64_t u)
    {
        std::cout << u;
    };

    std::function<void(const void *, uint32_t)> printhex = [](const void *data, uint32_t size)
    {
        std::string hex((const char *)data, size);
        std::cout << hex;
    };

    void link_print(wasm3::module &mod)
    {
        mod.link_optional("*", "prints", &prints);
        mod.link_optional("*", "prints_l", &prints_l);
        mod.link_optional("*", "printi", &printi);
        mod.link_optional("*", "printui", &printui);
        mod.link_optional("*", "printi128", &printi128);
        mod.link_optional("*", "printui128", &printui128);
        mod.link_optional("*", "printsf", &printsf);
        mod.link_optional("*", "printdf", &printdf);
        mod.link_optional("*", "printqf", &printqf);
        mod.link_optional("*", "printn", &printn);
        mod.link_optional("*", "printhex", &printhex);
    }
}