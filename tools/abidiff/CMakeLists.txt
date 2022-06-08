configure_file(${CMAKE_CURRENT_SOURCE_DIR}/chainsql-abidiff.cpp.in ${CMAKE_BINARY_DIR}/chainsql-abidiff.cpp)

add_tool(chainsql-abidiff)

set_target_properties(chainsql-abidiff PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
