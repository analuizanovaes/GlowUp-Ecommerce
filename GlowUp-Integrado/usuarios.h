// ============================================================
// ARQUIVO: usuarios.h
// MÓDULO: Gestão de Usuários
// DESCRIÇÃO: Índice do módulo usuarios.c. Inclua este arquivo
//            para usar cadastro, login e edição de perfil.
// AUTORES: Grupo GlowUP
// ============================================================

#ifndef USUARIOS_H
#define USUARIOS_H

#include "variaveis_globais.h"

#define MAX_TENTATIVAS 3 // Limite de erros antes de bloquear a conta

// ==========================================
// ASSINATURAS DAS FUNCOES (INDICE)
// Isso permite que o main.c saiba que essas funcoes existem.
// ==========================================
int cpfExiste(char cpf[]);
int emailExiste(char email[]);
void cadastrarUsuario();
int realizarLogin();
void editarDados(int indice);
void listarUsuarios();

#endif