#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define TRUE 1
#define FALSE -1

//--------------TAD---------------

typedef struct registro {
    int operacoes[MAX];
    int ultimo;
    int reservas;
    int retiradas;
} lista_livros;

//----------Operações TAD----------
void inicia_lista(lista_livros *listaAux){
    int x;
    for(x = 0; x < MAX; x++){
        listaAux->operacoes[x] = 0;
    }
    listaAux->ultimo = -1;
    listaAux->reservas = 0;
    listaAux->retiradas = 0;
}

int insere_elemento(lista_livros *listaAux, int n){
    if(listaAux->ultimo == (MAX - 1))
        return FALSE;

    listaAux->operacoes[listaAux->ultimo+1] = n;
    listaAux->ultimo++;
    listaAux->reservas++;


    return TRUE;
}

int busca_elemento(lista_livros *listaAux, int n){
    int i;

    if(listaAux->ultimo == -1)
        return FALSE;

    for (i = 0; i <= listaAux->ultimo; i++){
        if(listaAux->operacoes[i] == n)
            return i;   
    }

    return FALSE;
}

int remove_elemento(lista_livros *listaAux, int pos){
    int i;
    
        if(pos == listaAux->ultimo)
            listaAux->operacoes[pos] = 0;
        for(i = pos; i <= listaAux->ultimo; i++){
            listaAux->operacoes[i] = listaAux->operacoes[i+1];                    
        }
        listaAux->operacoes[listaAux->ultimo+1] = 0;
        listaAux->retiradas++;
        listaAux->ultimo--;
    

    return TRUE;
}

//----------Função PRINCIPAL----------
int main(void){

    int i, l, op, livro;
    lista_livros reg;

    inicia_lista(&reg);
    scanf("%d", &l);
    
    if (l >=1 && l<= 100){
        for(i = 1; i <= l; i++){
            scanf("%d %d", &op, &livro);
            if (livro >=1 && livro<= 100){
                switch (op) {

                    case 1: if (insere_elemento(&reg, livro) == TRUE){
                                    printf("Sua reserva foi realizada\n");
                                  }
                            else printf("Lista de reserva cheia\n");                  
                    break;

                    case 2: if (busca_elemento(&reg, livro) != FALSE){
                                    remove_elemento(&reg, busca_elemento(&reg, livro));
                                    printf("O livro foi retirado com sucesso\n");
                                }
                            else printf("Voce nao possui reserva desse livro\n");
              
                }
            }else exit(1);              
        } 
    }else exit(1);
    
    printf("Voce realizou %d reservas e %d retiradas\n", reg.reservas, reg.retiradas);   

return 0;
}
