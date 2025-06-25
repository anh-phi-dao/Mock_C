function(target_set_warning TARGET ENABLE ENABLE_AS_ERRORS)
    if(NOT ${ENABLED})
        message(STATUS "Warning disabled for : ${TARGET}")
        return()
    endif()
    
    set(MSVC_WARNINGS
        /W4
        /permissive-)

    set(CLANG_WARNINGS
        -Wall
        -Wextra
        -Wpedantic)

    set(GCC_WARNINGS ${CLANG_WARNINGS})

    if(${ENABLE_AS_ERRORS})
        list(APPEND ${MSVC_WARNINGS} /WX)
        list(APPEND ${CLANG_WARNINGS} -Werror)
        list(APPEND ${GCC_WARNINGS} -Werror)
    endif()

    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        set(WARNINGS ${MSVC_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "CLANG")
        set(WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")    
        set(WARNINGS ${GCC_WARNINGS})   
        message(STATUS ${CMAKE_CXX_COMPILER_ID})
    endif()

    target_compile_options(${TARGET} PRIVATE ${WARNINGS})
    message(STATUS "${WARNINGS}")
    message(STATUS ${CMAKE_CXX_COMPILER_ID})

endfunction(target_set_warning)

