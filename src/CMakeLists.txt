add_library(preventiva_core
    core/Machine.h
    core/Machine.cpp
    core/MaintenanceTypes.h
    core/MaintenanceOrder.h
    core/MaintenanceOrder.cpp
)

target_link_libraries(preventiva_core PRIVATE Qt6::Core)
target_include_directories(preventiva_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(preventiva_app
    app/IMachineRepository.h
    app/IMaintenanceOrderRepository.h
    app/IAlertDispatcher.h
    app/Scheduler.h
    app/Scheduler.cpp
    app/AlertService.h
    app/AlertService.cpp
    app/UseCases.h
    app/UseCases.cpp
    app/policies/MaintenancePolicy.h
    app/policies/PolicyComposite.h
    app/policies/PolicyComposite.cpp
    app/policies/HoursPolicy.h
    app/policies/HoursPolicy.cpp
    app/policies/SemiannualPolicy.h
    app/policies/SemiannualPolicy.cpp
)

target_link_libraries(preventiva_app PRIVATE Qt6::Core preventiva_core)
target_include_directories(preventiva_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(preventiva_infra_memory
    infrastructure/memory/InMemoryMachineRepository.h
    infrastructure/memory/InMemoryMachineRepository.cpp
    infrastructure/memory/InMemoryMaintenanceOrderRepository.h
    infrastructure/memory/InMemoryMaintenanceOrderRepository.cpp
    infrastructure/email/FakeEmailDispatcher.h
    infrastructure/email/FakeEmailDispatcher.cpp
)
target_link_libraries(preventiva_infra_memory PRIVATE Qt6::Core preventiva_core preventiva_app)
target_include_directories(preventiva_infra_memory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# CLI app (MVP)
add_executable(preventiva_cli
    cli/main.cpp
)
target_link_libraries(preventiva_cli PRIVATE Qt6::Core preventiva_core preventiva_app preventiva_infra_memory)
