# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "app/CMakeFiles/PreventivaApp_autogen.dir/AutogenUsed.txt"
  "app/CMakeFiles/PreventivaApp_autogen.dir/ParseCache.txt"
  "app/PreventivaApp_autogen"
  "plugins/maintenance_service/CMakeFiles/PreventivaMaintenancePlugin_autogen.dir/AutogenUsed.txt"
  "plugins/maintenance_service/CMakeFiles/PreventivaMaintenancePlugin_autogen.dir/ParseCache.txt"
  "plugins/maintenance_service/PreventivaMaintenancePlugin_autogen"
  )
endif()
