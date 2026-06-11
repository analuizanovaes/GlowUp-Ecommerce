// ============================================================================
// ARQUIVO: usuarios.h
// DESCRIÇÃO: Funciona como um índice. Aqui listamos os nomes das funções 
//            de cadastro e verificação para que o resto do sistema saiba 
//            que elas existem e possa chamá-las.
// ============================================================================

#ifndef USUARIOS_H
#define USUARIOS_H

#include "variaveis_globais.h"
#include <ctype.h>  // Usamos isso para ajudar a ver se uma letra é letra ou se é número
#include <stdlib.h> // Usamos para transformar textos digitados em números reais (atoi)

// O cliente tem 3 chances de errar a senha. Depois disso, travamos a conta.
#define MAX_TENTATIVAS 3 

// ============================================================================
// FUNÇÕES DE VERIFICAÇÃO (Garantem que o cliente não digitou bobeira)
// ============================================================================
int validarNome(char nome[]);
int validarIdadeEntrada(char idade[]);
int validarIdade(int idade);
int validarCPF(char cpf[]);
int validarEmail(char email[]);
int validarEndereco(char endereco[]);
int validarTelefone(char telefone[]);

// ============================================================================
// FUNÇÕES PRINCIPAIS (Criam as contas, fazem o login e editam os dados)
// ============================================================================
int cpfJaCadastrado(char cpf[]);
int eh_apenas_numeros(char str[]);
int emailJaCadastrado(char email[]);
void cadastrarUsuario();
int realizarLogin();
void editarDados(int indice);

#endif