# app/CMakeLists.txt

# Biblioteca com a UI + domínio + infraestrutura
add_library(PreventivaUI STATIC
    MainWindow.h
    MainWindow.cpp
    MainWindow.ui
    ServiceLocator.h
    ServiceLocator.cpp
    domain/SchedulingStrategy.h
    domain/SchedulingStrategy.cpp
    domain/MaintenanceFactory.h
    domain/MaintenanceFactory.cpp
    infrastructure/JsonMachineRepository.h
    infrastructure/JsonMachineRepository.cpp
    infrastructure/ILogger.h
    infrastructure/ConsoleLogger.h
    infrastructure/ConsoleLogger.cpp
    infrastructure/QtEmailAdapter.h
    infrastructure/QtEmailAdapter.cpp
)
target_include_directories(PreventivaUI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(PreventivaUI PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets PreventivaSDK)

# Executável mínimo que linka na lib acima
set(APP_NAME PreventivaApp)
add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} PRIVATE PreventivaUI)

set_target_properties(${APP_NAME} PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

# Copiar plugins ao lado do executável
add_custom_command(TARGET ${APP_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:${APP_NAME}>/../plugins"
  COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}" "$<TARGET_FILE_DIR:${APP_NAME}>/../plugins"
)