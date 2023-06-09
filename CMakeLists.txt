cmake_minimum_required(VERSION 3.5)

# Sanity check our source directory to make sure that we are not trying to
# generate an in-source build, and to make
# sure that we don't have any stray generated files lying around in the tree
if( CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed.
Please create a directory and run cmake from there, passing the path
to this source directory as the last argument.
This process created the file `CMakeCache.txt' and the directory `CMakeFiles'.
Please delete them.")
endif()

project(chainsql_cdt)

find_program(SCCACHE_FOUND sccache)
if (SCCACHE_FOUND)
   message(STATUS "Using sccache")
   set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE sccache)
else()
   find_program(CCACHE_FOUND ccache)
   if (CCACHE_FOUND)
      message(STATUS "Using ccache")
      set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
   endif()
endif()

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)
set(VERSION_SUFFIX rc1)

if (VERSION_SUFFIX)
   set(VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}-${VERSION_SUFFIX}")
else()
   set(VERSION_FULL "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
endif()

set(CDT_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX}/chainsql.cdt)

option(ENABLE_NATIVE_COMPILER "enable native builds with the chainsql.cdt toolchain" ON)
option(ENABLE_TESTS "enable building tests" ON)

include(GNUInstallDirs)

if(NOT TOOLS_BUILD_TYPE)
   set(TOOLS_BUILD_TYPE "Release")
endif()

if(NOT LIBS_BUILD_TYPE)
   set(LIBS_BUILD_TYPE "Release")
endif()

include(modules/ClangExternalProject.txt)
include(modules/ToolsExternalProject.txt)

set(WASM_SDK_BUILD true)

### Configure the chainsqlWasmToolchain.cmakes
set(CDT_ROOT_DIR ${CMAKE_BINARY_DIR})

configure_file(${CMAKE_SOURCE_DIR}/modules/chainsql.cdt-config.cmake ${CMAKE_BINARY_DIR}/lib/cmake/chainsql.cdt/chainsql.cdt-config.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/ChainSQLCDTMacros.cmake.in ${CMAKE_BINARY_DIR}/lib/cmake/chainsql.cdt/ChainSQLCDTMacros.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/chainsqlWasmToolchain.cmake.in ${CMAKE_BINARY_DIR}/lib/cmake/chainsql.cdt/chainsqlWasmToolchain.cmake @ONLY)

set(CDT_ROOT_DIR ${CDT_INSTALL_PREFIX})

configure_file(${CMAKE_SOURCE_DIR}/modules/chainsql.cdt-config.cmake ${CMAKE_BINARY_DIR}/modules/chainsql.cdt-config.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/ChainSQLCDTMacros.cmake.in ${CMAKE_BINARY_DIR}/modules/ChainSQLCDTMacros.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/chainsqlWasmToolchain.cmake.in ${CMAKE_BINARY_DIR}/modules/chainsqlWasmToolchain.cmake @ONLY)

set(CDT_ROOT_DIR "_PREFIX_")
configure_file(${CMAKE_SOURCE_DIR}/modules/ChainSQLCDTMacros.cmake.in ${CMAKE_BINARY_DIR}/modules/ChainSQLCDTMacrosPackage.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/chainsqlWasmToolchain.cmake.in ${CMAKE_BINARY_DIR}/modules/chainsqlWasmToolchainPackage.cmake @ONLY)
configure_file(${CMAKE_SOURCE_DIR}/modules/chainsql.cdt-config.cmake ${CMAKE_BINARY_DIR}/modules/chainsql.cdt-config.cmake.package @ONLY)

include(modules/LibrariesExternalProject.txt)

include(modules/InstallCDT.cmake)

configure_file(${CMAKE_SOURCE_DIR}/imports/chainsql.imports.in ${CMAKE_BINARY_DIR}/chainsql.imports COPYONLY)
install(FILES ${CMAKE_BINARY_DIR}/chainsql.imports DESTINATION ${CDT_INSTALL_PREFIX})

configure_file(${CMAKE_SOURCE_DIR}/scripts/ricardeos/ricardeos.py ${CMAKE_BINARY_DIR}/scripts/ricardeos.py COPYONLY)
install(FILES ${CMAKE_BINARY_DIR}/scripts/ricardeos.py DESTINATION ${CDT_INSTALL_PREFIX}/scripts)

# add licenses
configure_file(${CMAKE_SOURCE_DIR}/chainsql_llvm/LICENSE.TXT ${CMAKE_BINARY_DIR}/licenses/llvm.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/libraries/boost/boost.license ${CMAKE_BINARY_DIR}/licenses/boost.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/libraries/meta_refl/LICENSE ${CMAKE_BINARY_DIR}/licenses/meta_refl.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/tools/external/wabt/LICENSE ${CMAKE_BINARY_DIR}/licenses/wabt.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/tools/jsoncons/LICENSE ${CMAKE_BINARY_DIR}/licenses/jsoncons.license COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/LICENSE ${CMAKE_BINARY_DIR}/licenses/chainsql.cdt.license COPYONLY)

add_subdirectory(simulator)
