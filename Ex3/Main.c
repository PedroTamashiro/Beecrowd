#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvoreBin{
    char Num;
    struct ArvoreBin* EsqArvore;
    struct ArvoreBin* DirArvore;
}Tarvore;

typedef Tarvore* Parvore;

int ArvoreVazia(Parvore a){
    return a==NULL;
}
void DestroiArvore(Parvore a){
    if(!ArvoreVazia(a)){
        DestroiArvore(a->EsqArvore);
        DestroiArvore(a->DirArvore);
        free(a);
    }
}
Parvore InicializaArvore(){
  return NULL;
}
Parvore InstanciaArvore(Parvore a,char b){
    a = (Parvore)malloc(sizeof(Tarvore));
    a->DirArvore = NULL;
    a->EsqArvore = NULL;
    a->Num = b;
    return a;
}
Parvore InsereNaArvore(Parvore Pai, char Filho){
    if(ArvoreVazia(Pai)){
        Pai = InstanciaArvore(Pai ,Filho);
    }else{
        int aux1, aux2;
        aux1 = (int)Pai->Num;
        aux2 = (int)Filho;
        if(aux2 < aux1){
            Pai->EsqArvore = InsereNaArvore(Pai->EsqArvore, Filho);
        }else{
            Pai->DirArvore = InsereNaArvore(Pai->DirArvore, Filho);
        }
    }
    return Pai;
}
Parvore BuscaNaArvore(Parvore arvore,char dado){
    if(!ArvoreVazia(arvore)){
        int aux1, aux2;
        aux1 = (int)arvore->Num;
        aux2 = (int)dado;
        if(aux1 > aux2){
            return BuscaNaArvore(arvore->EsqArvore,dado);
        }else{
            if(aux1 < aux2){
                return BuscaNaArvore(arvore->DirArvore,dado);
            }else
                return arvore;
        }
    }
    return NULL;
}
void ImprimePre(Parvore A){
  if(!ArvoreVazia(A)){
    printf("%c ",A->Num);
    ImprimePre(A->EsqArvore);
    ImprimePre(A->DirArvore);
  }
}

void ImprimeIn(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimeIn(A->EsqArvore);
    printf("%c ",A->Num);
    ImprimeIn(A->DirArvore);
  }
}

void ImprimePos(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimePos(A->EsqArvore);
    ImprimePos(A->DirArvore);
    printf("%c ",A->Num);
  }
}
int main(void){
    Parvore Arvore, buscado;
    char opcao[10], letra;

    Arvore = InicializaArvore();
    buscado = InicializaArvore();

    while(scanf("%s", opcao) != EOF){

        getchar();

        if(strcmp(opcao, "I") == 0){
            scanf("%c", &letra);
            getchar();
            Arvore = InsereNaArvore(Arvore, letra);
        }else if(strcmp(opcao, "INFIXA") == 0){
            ImprimeIn(Arvore);
            printf("\n");
        }else if(strcmp(opcao, "PREFIXA") == 0){
            ImprimePre(Arvore);
            printf("\n");
        }else if(strcmp(opcao, "POSFIXA") == 0){
            ImprimePos(Arvore); 
            printf("\n");
        }else if(strcmp(opcao, "P") == 0){
            scanf("%c", &letra);
            getchar();
            buscado = BuscaNaArvore(Arvore,letra);
            if(buscado == NULL){
                printf("%c nao existe", letra);
            }else if(buscado->Num == letra){
                printf("%c existe", letra);
            }
            printf("\n");
        }
    }
}