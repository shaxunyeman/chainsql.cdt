set(sources
    "m3_api_libc.c"
    "m3_api_wasi.c"
    "m3_api_uvwasi.c"
    "m3_api_meta_wasi.c"
    "m3_api_tracer.c"
    "m3_bind.c"
    "m3_code.c"
    "m3_compile.c"
    "m3_core.c"
    "m3_env.c"
    "m3_exec.c"
    "m3_function.c"
    "m3_info.c"
    "m3_module.c"
    "m3_parse.c"
)

set(headers
    "m3_api_libc.h"
    "m3_api_wasi.h"
    "m3_api_tracer.h"
    "m3_bind.h"
    "m3_code.h"
    "m3_compile.h"
    "m3_config_platforms.h"
    "m3_config.h"
    "m3_core.h"
    "m3_env.h"
    "m3_exception.h"
    "m3_exec_defs.h"
    "m3_exec.h"
    "m3_function.h"
    "m3_info.h"
    "m3_math_utils.h"
    "wasm3_defs.h"
    "wasm3.h"
)

add_library(m3 STATIC ${sources} ${headers})

target_include_directories(m3 PUBLIC .)

target_compile_features(m3 PRIVATE c_std_99)

if (CMAKE_C_COMPILER_ID MATCHES "MSVC")
    # add MSVC specific flags here
else()
    # Flags common for GCC and Clang


    # FIXME: comparison of integers of different signs: 'u32' and 'i32'
    set_source_files_properties(m3_env.c PROPERTIES COMPILE_FLAGS -Wno-sign-compare)

    if (WASIENV)
        # FIXME: declaration of 'struct sigaction' will not be visible outside of this function
        target_compile_options(m3 PUBLIC -Wno-visibility)
        # FIXME incompatible pointer types passing 'u32 *' to parameter of type 'char **'
        set_source_files_properties(m3_api_meta_wasi.c PROPERTIES COMPILE_FLAGS -Wno-incompatible-pointer-types)
    endif()

    if (CMAKE_C_COMPILER_ID MATCHES "Clang")
        # Clang specific flags here
    else()
        # GCC specific flags here
    endif()
endif()

if(BUILD_WASI MATCHES "simple")
    target_compile_definitions(m3 PUBLIC d_m3HasWASI)
elseif(BUILD_WASI MATCHES "metawasi")
    target_compile_definitions(m3 PUBLIC d_m3HasMetaWASI)
elseif(BUILD_WASI MATCHES "uvwasi")
    target_compile_definitions(m3 PUBLIC d_m3HasUVWASI)
    include_directories("${libuv_SOURCE_DIR}/include")
endif()
