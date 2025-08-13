# Cenários BDD (para o vídeo)

## Cenário 1: Listagem inicial de máquinas
**Given** que o usuário abriu o aplicativo  
**When** a janela principal aparece  
**Then** a tabela deve exibir ao menos uma máquina cadastrada

## Cenário 2: Clique em “Agendar Manutenção” sem seleção
**Given** que o usuário abriu o aplicativo e não selecionou nenhuma máquina  
**When** ele clica no botão “Agendar Manutenção”  
**Then** nenhuma OS deve ser criada e nenhuma notificação deve ser enviada ao cliente

## Cenário 3: Agendar manutenção com seleção
**Given** que o usuário abriu o aplicativo e selecionou uma máquina na tabela  
**When** ele clica no botão “Agendar Manutenção”  
**Then** uma OS é criada e o sistema envia uma notificação ao cliente (simulada por log)
