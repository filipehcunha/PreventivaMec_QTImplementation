find_package(Doxygen)
if (DOXYGEN_FOUND)
  set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
  set(DOXYGEN_OUT ${CMAKE_BINARY_DIR}/docs)
  file(MAKE_DIRECTORY ${DOXYGEN_OUT})
  add_custom_target(docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_IN}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Gerando documentação Doxygen..."
    VERBATIM)
endif()
