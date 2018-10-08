if(NOT DEFINED ENV{CFLAGS})
    if(CMAKE_C_COMPILER_ID MATCHES Clang)
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Weverything")
        set(CMAKE_C_FLAGS_RELEASE "-Ofast -DNDEBUG")
        set(CMAKE_C_FLAGS_DEBUG "-O0 -g -DDEBUG")
    endif()
endif()