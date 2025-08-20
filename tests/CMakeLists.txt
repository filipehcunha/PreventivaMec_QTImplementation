add_executable(preventiva_tests
    test_scheduling.cpp
    test_functional.cpp
)
target_link_libraries(preventiva_tests PRIVATE Qt6::Core Qt6::Test preventiva_core preventiva_app preventiva_infra_memory)

add_test(NAME preventiva_tests COMMAND preventiva_tests)
