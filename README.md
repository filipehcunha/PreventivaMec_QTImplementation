# PreventivaMecQt (Demo)

Projeto Qt/CMake com **padrões de projeto**, **arquitetura em camadas**, **componentização via DLL (plugin Qt)** e **documentação Doxygen**.
Serve como referência rápida para apresentação de até **5 min**.

## Requisitos
- Qt 6.x (Core, Gui, Widgets) + CMake >= 3.21
- Compilador C++17 (MSVC/Clang/GCC)

## Build (Windows/MSVC)
```powershell
# Ajuste o caminho do Qt (ex.: C:\Qt\6.6.3\msvc2019_64)
$env:CMAKE_PREFIX_PATH="C:\Qt\6.6.3\msvc2019_64"
cmake -S . -B build -G "Ninja"
cmake --build build
```

## Executar
O executável fica em `build/bin/PreventivaApp` e os plugins em `build/plugins`.
Garanta que a pasta `plugins` esteja no mesmo nível do executável ou configure `PATH`/`QT_PLUGIN_PATH`.

## Doxygen
Se tiver Doxygen instalado:
```bash
cmake --build build --target docs
# Saída em build/docs/html/index.html
```

## Padrões implementados (onde ver no código)
- **Strategy**: `app/domain/SchedulingStrategy.*`
- **Factory**: `app/domain/MaintenanceFactory.*`
- **Observer (Qt signals/slots)**: interação UI ↔ serviço no `MainWindow.*`
- **Repository**: `sdk/include/preventiva/IMachineRepository.h` e impl `app/infrastructure/JsonMachineRepository.*`
- **Adapter**: `app/infrastructure/QtEmailAdapter.*` implementa `IAlertService`
- **Facade**: `app/ServiceLocator.*` centraliza obtenção de serviços
- **Inversão de Dependência**: app depende de **interfaces** (SDK), e plugin depende do SDK

## Camadas
- **SDK (interfaces)**: contrato estável e compartilhado entre app e plugins
- **App (UI + domínio + infra)**: implementação concreta e orquestração
- **Plugin (DLL Qt)**: `maintenance_service` carregado dinamicamente via `QPluginLoader`

