file(GLOB HEADERS "*.hpp"
                  "*.h")

add_library(chainsql
            chainsqllib.cc
            crypto.cc
            ${HEADERS})

add_library(chainsql_malloc
            malloc.cc
            ${HEADERS})

add_library(chainsql_dsm
            simple_malloc.cc
            ${HEADERS})

add_library(chainsql_cmem
            memory.cc
            ${HEADERS})


set_target_properties(chainsql_malloc PROPERTIES LINKER_LANGUAGE C)

target_include_directories(chainsql PUBLIC
                                 ${CMAKE_SOURCE_DIR}/libc/musl/include
                                 ${CMAKE_SOURCE_DIR}/libc/musl/src/internal
                                 ${CMAKE_SOURCE_DIR}/libc/musl/src/crypt
                                 ${CMAKE_SOURCE_DIR}/libc/musl/arch/eos
                                 ${CMAKE_SOURCE_DIR}/libcxx/include
                                 ${CMAKE_SOURCE_DIR}
                                 ${CMAKE_SOURCE_DIR}/boost/include)

target_link_libraries( chainsql c c++ )
add_custom_command( TARGET chainsql POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:chainsql> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET chainsql_malloc POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:chainsql_malloc> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET chainsql_dsm POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:chainsql_dsm> ${BASE_BINARY_DIR}/lib )
add_custom_command( TARGET chainsql_cmem POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:chainsql_cmem> ${BASE_BINARY_DIR}/lib )

if (ENABLE_NATIVE_COMPILER)
   add_native_library(native_chainsql
                      chainsqllib.cc
                      crypto.cc
                      malloc.cc
                      ${HEADERS})

   add_dependencies( native_chainsql chainsql)
   add_custom_command( TARGET native_chainsql POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:native_chainsql> ${BASE_BINARY_DIR}/lib )
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/../chainsqlib DESTINATION ${BASE_BINARY_DIR}/include FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")
