configure_file(${CMAKE_CURRENT_SOURCE_DIR}/chainsql-ld.cpp.in ${CMAKE_BINARY_DIR}/chainsql-ld.cpp)

add_tool(chainsql-ld)

set_target_properties(chainsql-ld PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
