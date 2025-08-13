# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "")
  file(REMOVE_RECURSE
  "app/CMakeFiles/PreventivaApp_autogen.dir/AutogenUsed.txt"
  "app/CMakeFiles/PreventivaApp_autogen.dir/ParseCache.txt"
  "app/CMakeFiles/PreventivaUI_autogen.dir/AutogenUsed.txt"
  "app/CMakeFiles/PreventivaUI_autogen.dir/ParseCache.txt"
  "app/PreventivaApp_autogen"
  "app/PreventivaUI_autogen"
  "plugins/maintenance_service/CMakeFiles/PreventivaMaintenancePlugin_autogen.dir/AutogenUsed.txt"
  "plugins/maintenance_service/CMakeFiles/PreventivaMaintenancePlugin_autogen.dir/ParseCache.txt"
  "plugins/maintenance_service/PreventivaMaintenancePlugin_autogen"
  "tests/functional/CMakeFiles/FunctionalGuiTests_autogen.dir/AutogenUsed.txt"
  "tests/functional/CMakeFiles/FunctionalGuiTests_autogen.dir/ParseCache.txt"
  "tests/functional/FunctionalGuiTests_autogen"
  "tests/gui/CMakeFiles/GuiTests_autogen.dir/AutogenUsed.txt"
  "tests/gui/CMakeFiles/GuiTests_autogen.dir/ParseCache.txt"
  "tests/gui/GuiTests_autogen"
  "tests/unit/CMakeFiles/UnitDomainTests_autogen.dir/AutogenUsed.txt"
  "tests/unit/CMakeFiles/UnitDomainTests_autogen.dir/ParseCache.txt"
  "tests/unit/CMakeFiles/UnitInfraTests_autogen.dir/AutogenUsed.txt"
  "tests/unit/CMakeFiles/UnitInfraTests_autogen.dir/ParseCache.txt"
  "tests/unit/UnitDomainTests_autogen"
  "tests/unit/UnitInfraTests_autogen"
  )
endif()
