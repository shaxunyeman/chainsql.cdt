cmake_minimum_required(VERSION 3.5)

find_package(
    Boost
    1.70.0
)

if (Boost_FOUND)
    add_executable(
        simulator 
        ${CMAKE_SOURCE_DIR}/simulator/simulator.cc
        ${CMAKE_SOURCE_DIR}/simulator/vm/impl/action.cc
        ${CMAKE_SOURCE_DIR}/simulator/vm/impl/chainsqlWasmVm.cc
    )
    include_directories(
        ${CMAKE_SOURCE_DIR}/
        ${CMAKE_SOURCE_DIR}/simulator/wasm3/source
        ${CMAKE_SOURCE_DIR}/simulator/wasm3/platforms/cpp/wasm3_cpp/include
        ${Boost_INCLUDE_DIRS}
    )
    
    add_subdirectory(${CMAKE_SOURCE_DIR}/simulator/wasm3/)
    add_subdirectory(${CMAKE_SOURCE_DIR}/simulator/wasm3/platforms/cpp/wasm3_cpp)

    target_link_libraries(simulator PRIVATE wasm3_cpp m3)
    target_compile_features(simulator PRIVATE cxx_std_17)
endif()
