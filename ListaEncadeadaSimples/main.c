#include "lista.c"

int main() {
    Lista *lista = lst_cria();  // Cria uma lista encadeada vazia

    // Insere elementos na lista
    lista = lst_insere(lista, "Felipe");
    lista = lst_insere(lista, "Gabriel");
    lista = lst_insere(lista, "Alisson");
    lista = lst_insere(lista, "Jhoan");

    printf("Lista apos insercao de elementos:\n");
    lst_imprime(lista);
	printf("\n");

    // Verifica se a lista está vazia
    if (lst_vazia(lista)) {
        printf("A lista esta vazia.\n");
    } else {
        printf("A lista nao esta vazia.\n");
    }
	printf("\n");

    // Busca um elemento na lista
    Lista *resultadoBusca = lst_busca("Felipe", lista);
    if (resultadoBusca != NULL) {
        printf("Elemento %s encontrado na lista.\n", resultadoBusca->info);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
	printf("\n");

    // Remove um elemento da lista
    char remover_elemento[30];
    strcpy(remover_elemento, "Felipe");
    lista = lst_retira(lista, remover_elemento);
    printf("Lista apos a remocao do elemento %s:\n", remover_elemento);
    lst_imprime(lista);
	printf("\n");

    // Insere um elemento de forma ordenada na lista
    char elementoOrdenado[30];
    strcpy(elementoOrdenado, "Alexandre");
    lista = lst_insere_ordenada(lista, elementoOrdenado);
    printf("Lista apos a insercao ordenada do elemento %s:\n", elementoOrdenado);
    lst_imprime(lista);
	printf("\n");

    // Libera a memória da lista
    lst_libera(lista);

    // Lê valores de um arquivo e insere na lista
    lista = lst_ler_arquivo("entrada.txt");
    printf("Lista apos a leitura do arquivo:\n");
    lst_imprime(lista);

    // Libera a memória da lista novamente
    lst_libera(lista);

    return 0;
}
