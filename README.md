# PreventivaMec (Qt/C++) — Arquitetura limpa, baixo acoplamento e testes funcionais

## Stack
- **Qt 6 (Core, Test)** — sinais/slots, containers, QDate, QTest
- **CMake 3.21+** — build moderno
- **Padrões**: Repository, Policy/Strategy, Composite, Observer (signals/slots), DI via factory (`wireApp`)

## Como compilar
```bash
mkdir build && cd build
cmake -DCMAKE_PREFIX_PATH=/path/para/Qt/6.x/gcc_64 ..
cmake --build . -j
ctest --output-on-failure
```

- Binários:
  - `preventiva_cli` — demonstração de fluxo
  - `preventiva_tests` — testes (unitários + funcionais end-to-end simples)

## Organização
```
src/
  core/         # Entidades de domínio
  app/          # Casos de uso, serviços e políticas (Strategy/Composite)
  infrastructure/
    memory/     # Repositórios em memória (para testes/MVP)
    email/      # Dispatcher fake p/ captura de alertas
  cli/          # App de linha de comando de demonstração
tests/          # Qt Test: cenários funcionais automatizados
```

## Extensões sugeridas
- Adicionar `Qt::Sql` com repositório SQLite; manter as interfaces para baixo acoplamento.
- Serviço em segundo plano (PreventivAlert) usando `QTimer` e `QSettings` para intervalo de verificação.
- Camada de apresentação (Qt Widgets/QML) conectando-se apenas à API de casos de uso.
