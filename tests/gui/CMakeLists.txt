# tests/gui/CMakeLists.txt
set(TEST_NAME GuiTests)

add_executable(${TEST_NAME}
  TestMainWindow.cpp
)

target_include_directories(${TEST_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}/app
)

# 👇 Linka na lib com a UI/infra
target_link_libraries(${TEST_NAME} PRIVATE Qt6::Test PreventivaUI)

set_target_properties(${TEST_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_custom_command(TARGET ${TEST_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${TEST_NAME}>/../plugins"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" "$<TARGET_FILE_DIR:${TEST_NAME}>/../plugins"
)

add_test(NAME ${TEST_NAME} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME})
set_tests_properties(${TEST_NAME} PROPERTIES LABELS "functional")