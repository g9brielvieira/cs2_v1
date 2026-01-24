#pragma once

//
// util.h - Definições de tipos auxiliares
// 
// Este arquivo contém type definitions personalizados para facilitar
// a manipulação de dados de diferentes tamanhos no código do driver SMM
//

typedef UINTN QWORD;   // Inteiro de 64 bits sem sinal (ponteiro/endereço)
typedef UINT32 DWORD;  // Inteiro de 32 bits sem sinal
typedef long NTSTATUS; // Tipo de retorno de status do NT kernel
