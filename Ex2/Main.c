#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvoreBin{
    char letra;
    struct ArvoreBin* EsqArvore;
    struct ArvoreBin* DirArvore;
}Tarvore;

typedef Tarvore* Parvore;

int ArvoreVazia(Parvore a){
    return a==NULL;
}
Parvore DestroiArvore(Parvore a){
    if(!ArvoreVazia(a)){
        DestroiArvore(a->EsqArvore);
        DestroiArvore(a->DirArvore);
        free(a);
    }
    return NULL;
}
Parvore InstanciaArvore(char b){
    Parvore a;
    a = (Parvore)malloc(sizeof(Tarvore));
    a->DirArvore = NULL;
    a->EsqArvore = NULL;
    a->letra = b;
    return a;
}
Parvore InsereNaArvore(Parvore Pai, char Pre, char* EmO){
    if(ArvoreVazia(Pai)){
        Parvore aux;
        aux = InstanciaArvore(Pre);
        return aux;
    }else{
        int i=0, j=0;
        while (EmO[i] != Pai->letra){
            i++;
        }
        while (EmO[j] != Pre){
            j++;
        }
        if(j < i){
            Pai->EsqArvore = InsereNaArvore(Pai->EsqArvore, Pre, EmO);
        }else{
            Pai->DirArvore = InsereNaArvore(Pai->DirArvore, Pre, EmO);
        }
    }
    return Pai;
}
void ImprimePos(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimePos(A->EsqArvore);
    ImprimePos(A->DirArvore);
    printf("%c",A->letra);
  }
}
int main(void){
    int i, j, num, testes, nodos;
    char preC[52], emC[52];

    scanf("%i", &testes);
    for(i=0;i<testes;i++){
        Parvore Arvore = NULL;
        scanf("%i", &nodos);
        scanf("%s", preC);
        scanf("%s", emC);

        for(j=0;j<nodos;j++){
            
            Arvore = InsereNaArvore(Arvore, preC[j], &emC[0]);
        }
        ImprimePos(Arvore);
        printf("\n");
    }
}