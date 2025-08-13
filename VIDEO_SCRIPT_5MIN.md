# Roteiro (≤ 5 min)

1. **Abertura (15s)** — Nome do grupo/fornecedor, objetivo: mostrar padrões, camadas, DLLs, organização e Doxygen.
2. **Arquitetura (45s)** — Diagrama verbal:
   - SDK (interfaces) → App (UI+domínio+infra) → Plugin DLL (serviço).
   - Mostre `sdk/include/preventiva/*.h` e explique desacoplamento.
3. **Padrões (2min)**
   - **Strategy** (`app/domain/SchedulingStrategy.*`): como cálculo de próxima manutenção muda sem if/else.
   - **Factory** (`app/domain/MaintenanceFactory.*`): escolhe a Strategy pela policy.
   - **Observer** (signals/slots): `MainWindow` conecta botão à ação.
   - **Repository** (`IMachineRepository` + `JsonMachineRepository`): troca de persistência sem mudar o app.
   - **Adapter** (`QtEmailAdapter` implementa `IAlertService`): hoje loga, amanhã envia e-mail real.
   - **Facade/DI** (`ServiceLocator`): centraliza obtenção do plugin e injeta dependências.
4. **Componentização (60s)**
   - Mostrar `plugins/maintenance_service/*`.
   - Explicar `Q_PLUGIN_METADATA`, `Q_INTERFACES`, `Q_DECLARE_INTERFACE` e `QPluginLoader` em `ServiceLocator`.
   - Rodar app: clicar em **Agendar Manutenção** e mostrar mensagem de OS criada (log simula e-mail).
5. **Organização & Qualidade (45s)**
   - Nomeação e identação consistentes.
   - Mostrar estrutura de pastas e CMake.
6. **Documentação (30s)**
   - Como gerar Doxygen (`cmake --build build --target docs`) e abrir `build/docs/html/index.html`.
7. **Encerramento (15s)** — Reforçar evidências e próximos passos (testes automatizados, CI, etc.).
