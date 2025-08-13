# PreventivaMecQt (Demo c/ Testes GUI)

PreventivaMec é um programa de Gestão de Manutenção de Maquinas Pesadas em Oficinas Mecanicas.
Projeto Qt/CMake com padrões, camadas, plugin DLL e **testes automatizados de GUI (Qt Test)**.
Use `ctest -R Gui` para rodar.

## Build rápido (WSL/Ubuntu)
```bash
sudo apt update && sudo apt install -y build-essential cmake ninja-build qt6-base-dev qt6-base-dev-tools libgl1-mesa-dev doxygen graphviz
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build -R Gui -V
```
