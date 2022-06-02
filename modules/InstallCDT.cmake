add_custom_command( TARGET ChainSQLClang POST_BUILD COMMAND mkdir -p ${CMAKE_BINARY_DIR}/bin )
macro( chainsql_clang_install file )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/chainsql_llvm/bin)
   add_custom_command( TARGET ChainSQLClang POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endmacro( chainsql_clang_install )

macro( chainsql_clang_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/chainsql_llvm/bin)
   add_custom_command( TARGET ChainSQLClang POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   add_custom_command( TARGET ChainSQLClang POST_BUILD COMMAND cd ${CMAKE_BINARY_DIR}/bin && ln -sf ${file} ${symlink} )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/bin/${file} ${CMAKE_INSTALL_PREFIX}/bin/${symlink})")
endmacro( chainsql_clang_install_and_symlink )

macro( chainsql_tool_install file )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/tools/bin)
   add_custom_command( TARGET ChainSQLTools POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
endmacro( chainsql_tool_install )

macro( chainsql_tool_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/tools/bin)
   add_custom_command( TARGET ChainSQLTools POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${BINARY_DIR}/${file} ${CMAKE_BINARY_DIR}/bin/ )
   install(FILES ${BINARY_DIR}/${file}
      DESTINATION ${CDT_INSTALL_PREFIX}/bin
      PERMISSIONS OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/bin)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/bin/${file} ${CMAKE_INSTALL_PREFIX}/bin/${symlink})")
endmacro( chainsql_tool_install_and_symlink )

macro( chainsql_cmake_install_and_symlink file symlink )
   set(BINARY_DIR ${CMAKE_BINARY_DIR}/modules)
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_INSTALL_PREFIX}/lib/cmake/chainsql.cdt)")
   install(CODE "execute_process( COMMAND ${CMAKE_COMMAND} -E create_symlink ${CDT_INSTALL_PREFIX}/lib/cmake/chainsql.cdt/${file} ${CMAKE_INSTALL_PREFIX}/lib/cmake/chainsql.cdt/${symlink})")
endmacro( chainsql_cmake_install_and_symlink )

macro( chainsql_libraries_install)
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/lib)
   execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include)
   install(DIRECTORY ${CMAKE_BINARY_DIR}/lib/ DESTINATION ${CDT_INSTALL_PREFIX}/lib)
   install(DIRECTORY ${CMAKE_BINARY_DIR}/include/ DESTINATION ${CDT_INSTALL_PREFIX}/include)
endmacro( chainsql_libraries_install )

chainsql_clang_install_and_symlink(llvm-ranlib chainsql-ranlib)
chainsql_clang_install_and_symlink(llvm-ar chainsql-ar)
chainsql_clang_install_and_symlink(llvm-nm chainsql-nm)
chainsql_clang_install_and_symlink(llvm-objcopy chainsql-objcopy)
chainsql_clang_install_and_symlink(llvm-objdump chainsql-objdump)
chainsql_clang_install_and_symlink(llvm-readobj chainsql-readobj)
chainsql_clang_install_and_symlink(llvm-readelf chainsql-readelf)
chainsql_clang_install_and_symlink(llvm-strip chainsql-strip)

chainsql_clang_install(opt)
chainsql_clang_install(llc)
chainsql_clang_install(lld)
chainsql_clang_install(ld.lld)
chainsql_clang_install(ld64.lld)
chainsql_clang_install(clang-9)
chainsql_clang_install(wasm-ld)

chainsql_tool_install_and_symlink(chainsql-pp chainsql-pp)
chainsql_tool_install_and_symlink(chainsql-wast2wasm chainsql-wast2wasm)
chainsql_tool_install_and_symlink(chainsql-wasm2wast chainsql-wasm2wast)
chainsql_tool_install_and_symlink(chainsql-cc chainsql-cc)
chainsql_tool_install_and_symlink(chainsql-cpp chainsql-cpp)
chainsql_tool_install_and_symlink(chainsql-ld chainsql-ld)
chainsql_tool_install_and_symlink(chainsql-abidiff chainsql-abidiff)
chainsql_tool_install_and_symlink(chainsql-init chainsql-init)

chainsql_clang_install(../lib/LLVMEosioApply${CMAKE_SHARED_LIBRARY_SUFFIX})
chainsql_clang_install(../lib/LLVMEosioSoftfloat${CMAKE_SHARED_LIBRARY_SUFFIX})

chainsql_cmake_install_and_symlink(chainsql.cdt-config.cmake chainsql.cdt-config.cmake)
chainsql_cmake_install_and_symlink(chainsqlWasmToolchain.cmake chainsqlWasmToolchain.cmake)
chainsql_cmake_install_and_symlink(ChainSQLCDTMacros.cmake ChainSQLCDTMacros.cmake)

chainsql_libraries_install()
