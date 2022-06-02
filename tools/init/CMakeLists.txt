configure_file(${CMAKE_CURRENT_SOURCE_DIR}/chainsql-init.cpp ${CMAKE_BINARY_DIR}/chainsql-init.cpp @ONLY)

add_tool(chainsql-init)

set_target_properties(chainsql-init PROPERTIES LINK_FLAGS "-Wl,-rpath,\"\\$ORIGIN/../lib\"")
