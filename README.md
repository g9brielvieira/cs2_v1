# CS2 UEFI/SMM Cheat

Este é um hack/cheat para Counter-Strike 2 (CS2) que opera no nível de firmware UEFI através do System Management Mode (SMM).

## Como funciona

Este driver UEFI utiliza técnicas avançadas de acesso à memória em nível de firmware para manipular o jogo Counter-Strike 2:

- **Opera no nível de firmware (UEFI SMM)**: Executa em System Management Mode, um modo privilegiado do processador com acesso total ao sistema
- **Leitura/escrita de memória física**: Acessa diretamente a memória física do sistema, contornando proteções convencionais
- **Tradução de endereços virtuais**: Usa page tables para traduzir endereços virtuais para físicos
- **Manipulação de ConVars do Source Engine**: Localiza e modifica variáveis do console do jogo (ConVars)
- **Ativa `cl_player_proximity_debug`**: Especificamente ativa essa ConVar para mostrar informações de proximidade de jogadores

### Processo técnico

1. **Localização do processo**: Encontra o processo `cs2.exe` na memória do sistema
2. **Localização de módulos**: Identifica módulos carregados pelo jogo (como `tier0.dll`)
3. **Acesso a interfaces**: Acessa a interface `VEngineCvar` do Source Engine
4. **Modificação de ConVars**: Altera o valor de `cl_player_proximity_debug` para ativar recursos de debug

## Estrutura dos arquivos

- **`main.c`** - Código principal do driver SMM
  - Implementa handlers SMM
  - Funções de leitura/escrita de memória física
  - Tradução de endereços virtuais via page tables
  - Localização de processos e módulos
  - Manipulação de ConVars do CS2

- **`stdafx.h`** - Headers e definições EFI/UEFI
  - Inclui bibliotecas UEFI necessárias
  - Protocolos SMM (SmmBase2, SmmCpu, SmmSwDispatch2)
  - Definições padrão do ambiente UEFI

- **`util.c`** - Funções utilitárias
  - Implementação de CRC32
  - Chave de encriptação

- **`util.h`** - Definições de tipos
  - Type definitions para QWORD, DWORD
  - Tipos auxiliares

## ⚠️ AVISO / DISCLAIMER

**Este projeto é apenas para fins educacionais e de pesquisa em segurança.**

- O uso deste software em ambientes online pode resultar em **banimento permanente** do Counter-Strike 2 e de outros jogos Valve
- A manipulação de jogos online viola os Termos de Serviço da Steam e pode resultar em ações legais
- O autor não se responsabiliza pelo uso inadequado deste código
- Este código demonstra técnicas de low-level hacking para fins educacionais apenas

**NÃO USE EM SERVIDORES PÚBLICOS OU AMBIENTES COMPETITIVOS.**

## Requisitos

- Sistema com UEFI firmware
- Conhecimento avançado de desenvolvimento de drivers UEFI
- Ferramentas de desenvolvimento EDK II (UEFI Development Kit)
- Processador com suporte a System Management Mode (SMM)

## Compilação

Este projeto requer o EDK II (UEFI Development Kit) para compilação. Configure o ambiente de desenvolvimento UEFI apropriado antes de tentar compilar.

---

**Nota**: Este é um projeto de pesquisa de segurança. Entender como cheats funcionam é importante para desenvolver melhores sistemas anti-cheat e proteger a integridade dos jogos online.
