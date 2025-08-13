set(PLUGIN_NAME PreventivaMaintenancePlugin)
add_library(${PLUGIN_NAME} SHARED
    MaintenanceServicePlugin.cpp
    MaintenanceServicePlugin.h
    plugin.json
)
target_link_libraries(${PLUGIN_NAME} PRIVATE Qt6::Core PreventivaSDK)
set_target_properties(${PLUGIN_NAME} PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
# No need for Qt UI in plugin; only Core + SDK.
