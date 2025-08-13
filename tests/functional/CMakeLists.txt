# tests/functional/CMakeLists.txt
set(FUNCTIONAL FunctionalGuiTests)
add_executable(${FUNCTIONAL} FunctionalGuiTests.cpp)
target_include_directories(${FUNCTIONAL} PRIVATE ${CMAKE_SOURCE_DIR}/app)
target_link_libraries(${FUNCTIONAL} PRIVATE Qt6::Test PreventivaUI)
set_target_properties(${FUNCTIONAL} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_custom_command(TARGET ${FUNCTIONAL} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${FUNCTIONAL}>/../plugins"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" "$<TARGET_FILE_DIR:${FUNCTIONAL}>/../plugins"
)
add_test(NAME ${FUNCTIONAL} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${FUNCTIONAL})
set_tests_properties(${FUNCTIONAL} PROPERTIES LABELS "functional")