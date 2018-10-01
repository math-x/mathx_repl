set(dependencies
    assignment
    error
    evaluate
    function_map
    parser
    process_file
    run_repl
    tools
    variable_map
)

# Add math_repl components into a shared library
add_library(repl SHARED ${dependencies})

set(final_executable
    main.cpp
)

# Set executable location to build directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_executable(mathx_repl ${final_executable})
target_link_libraries(mathx_repl repl)