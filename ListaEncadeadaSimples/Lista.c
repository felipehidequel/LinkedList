/*
Listas encadeadas são estruturas de dados que permitem armazenar uma coleção
 de elementos de um mesmo tipo.

Neste arquivo, temos a implementação de uma lista encadeada simples de inteiros.
*/

#include "lista.h"
/*Struct representa lista encadeada de inteiros*/
struct lista
{
	int info;			// inteiro
	struct lista *prox; // Aponta para o proximo item da lista de inteiros
};
/*Cria uma lista vazia*/
Lista *lst_cria(void)
{
	return NULL;
}
/*Insere inteiro em uma lista encadeada
** @param *l: Lista a ser incrementada
** @param *v: inteiro que vai ser inserido na lista l
*/
Lista *lst_insere(Lista *l, int v)
{
	Lista *novo = (Lista *)malloc(sizeof(Lista)); // Aloca memoria para um tipo estruturado Lista
	if (novo == NULL)							  // Verifica se a alocação foi bem sucedida
	{
		printf("[ERRO] memoria insuficiente!");
		exit(1);
	}
	novo->info = v; // Insere o item na nó
	novo->prox = l; // Novo nó aponta para a posição do nó anterior
	return novo;	// retona novo nó

	/* Ou para alterar diretamente

	void lst_insere(Lista** t, int v){
	Lista* novo = (Lista*) malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = *t;
	*t = novo; */
}
/*Verifica se uma lista está vazia*/
int lst_vazia(Lista *l)
{
	return (l == NULL); // Se a lista estiver vazia retorne 1;
}
/*Imprime os itens de uma lista*/
void lst_imprime(Lista *l)
{
	Lista *p;							// contador do tipo Lista
	for (p = l; p != NULL; p = p->prox) // Na primeira iteração p recebe o nó raiz da lista; Enquanto a lista não estiver vazia; Contador recebe o proximo nó
	{
		printf("\tInfo = %d \n", p->info); // imprime a informação do nó
	}
}
/*Busca por elemento em uma lista encadeada utlizando busca sequencial
** @param elemento: valor que está sendo buscado
** @param l; nó raiz
*/
Lista *lst_busca(int elemento, Lista *l)
{
	Lista *p;							// contador do tipo lista
	for (p = l; p != NULL; p = p->prox) // (Pecorrendo os nós)
	{
		if (p->info == elemento) // se o nó atual contém o elemento buscado
			return p;			 // retorna o nó atual
	}

	return NULL; // O elemento não consta
}

Lista *lst_retira(Lista *l, int v)
{
	Lista *ant = NULL; /* ponteiro para elemento anterior */
	Lista *p = l;	   /* ponteiro para percorrer a lista*/
	/* procura elemento na lista, guardando anterior */
	while (p->info != v)
	{
		if (p == NULL)
			return l; /* n�o achou: retorna lista original */
		ant = p;
		p = p->prox;
		/* verifica se achou elemento */
	}
	/* retira elemento */
	if (ant == NULL)
		/* retira elemento do inicio */
		l = p->prox;
	else
		/* retira elemento do meio da lista */
		ant->prox = p->prox;
	free(p);
	return l;
}

void lst_libera(Lista *l)
{
	Lista *p = l;	  // ponteiro para pecorrrer a lista
	Lista *t;		  // ponteiro para receber o proximo nó (variavel auxiliar)
	while (p != NULL) // enquanto p não for o ultimo nó
	{
		t = p->prox; // t aponta para o proximo nó
		free(p);	 // nó atual é liberado
		p = t;		 // p recebe o proximo nó
	}
}

Lista *lst_insere_ordenada(Lista *l, int v)
{
	Lista *novo;	   // Novo nó a ser inserido a lista
	Lista *ant = NULL; // ponteiro para elemento anterior
	Lista *p = l;	   // ponteiro para pecorrer a lista
	// Ordenação
	while (p != NULL && p->info < v) // enquanto P não for o ultimo nó && A informação do nó atual for menor que a informação a ser inserida:
	{
		ant = p;	 // nó anterior vai receber o nó atual
		p = p->prox; // p aponta para o proximo nó
	}
	novo = (Lista *)malloc(sizeof(Lista)); // aloca memoria para novo nó
	novo->info = v;						   // inicializa informação para o novo nó
	if (ant == NULL)					   // se o nó anterior for vazio
	{
		novo->prox = l; // novo nó aponta para a posição do nó raiz anterior
		l = novo;		// novo nó assume a posição de nó raiz
	}
	else
	{
		novo->prox = ant->prox; // novo nó aponta para o nó anterior
		ant->prox = novo;		// nó anterior aponta para o novo nó
	}
	return l; // retonra novo nó raiz
}

Lista *lst_ler_arquivo(char *nome_arquivo)
{
	FILE *arquivo;						// cria arquivo
	int valor;							// variavel que irá receber os valores contidos no arquivo
	Lista *l = lst_cria();				// cria uma lista vazia
	arquivo = fopen(nome_arquivo, "r"); // abre um arquivo no modo leitura
	if (arquivo == NULL)				// verifica se a alocação para arquivo foi bem sucedida
	{
		printf("Erro ao abrir o arquivo!\n");
		exit(1);
	}
	while (fscanf(arquivo, "%d", &valor) != EOF) // ler um valor inteiro e armazena na variavel valor, enquanto não estiver no fim do arquivo de texto
	{
		l = lst_insere(l, valor); // insere valor lido na lista vazia N vezes
	}
	fclose(arquivo); // fecha o arquivo
	return l;		 // retorna a nova lista
}
