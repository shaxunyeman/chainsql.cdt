cmake_minimum_required(VERSION 3.5)

project(chainsqlWasmVm)
set(target ${CMAKE_PROJECT_NAME})

set(sources
    "./vm/impl/chainsqlWasmVm.cc"
    "./vm/impl/action.cc"
    "./libraries/native/intrinsics.cc"
)

add_library(${target} STATIC ${sources})

include_directories(
    "./vm"
    "./wasm3/source"
    "./wasm3/platforms/cpp/wasm3_cpp/include"
    "./libraries"
    "./libraries/boost/include"
)

target_include_directories(${target} PUBLIC ./vm)
target_compile_features(${target} PRIVATE cxx_std_17)

add_subdirectory(example)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/wasm3)
target_link_libraries(${target} PRIVATE m3)