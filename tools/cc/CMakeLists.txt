configure_file(${CMAKE_CURRENT_SOURCE_DIR}/chainsql-cc.cpp.in ${CMAKE_BINARY_DIR}/chainsql-cc.cpp)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/chainsql-cpp.cpp.in ${CMAKE_BINARY_DIR}/chainsql-cpp.cpp)

add_tool(chainsql-cc)
add_tool(chainsql-cpp)

set_target_properties(chainsql-cc PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
set_target_properties(chainsql-cpp PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
