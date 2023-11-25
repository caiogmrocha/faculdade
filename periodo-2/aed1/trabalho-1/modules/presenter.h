#ifndef PRESENTER_H
#define PRESENTER_H

/**
 * Escolhe a tela a ser exibida
 * 
 * @return void
*/
void escolher_tela();

/**
 * Exibe a tela inicial
 * 
 * @return void
*/
void tela_inicial();

/**
 * Exibe a tela de cadastro no inicio
 * 
 * @return void
*/
void tela_cadastro_inicio();

/**
 * Exibe a tela de cadastro no fim
 * 
 * @return void
*/
void tela_cadastro_fim();

/**
 * Exibe a tela de cadastro em uma posicao especifica
 * 
 * @return void
*/
void tela_cadastro_posicao_especifica();

/**
 * Exibe a tela de listagem de todos os livros
 * 
 * @return void
*/
void tela_listagem_todos();

/**
 * Exibe a tela de listagem de livros disponiveis
 * 
 * @return void
*/
void tela_listagem_disponiveis();

/**
 * Exibe a tela de listagem de livros emprestados
 * 
 * @return void
*/
void tela_listagem_emprestados();

/**
 * Exibe a tela de listagem de livros por editora
 * 
 * @return void
*/
void tela_listagem_por_editora();

/**
 * Exibe a tela de remocao de um livro
 * 
 * @return void
*/
void tela_remocao();

/**
 * Exibe a tela de visualizacao de detalhes de um livro
 * 
 * @return void
*/
void tela_visualizar_detalhes();

#endif