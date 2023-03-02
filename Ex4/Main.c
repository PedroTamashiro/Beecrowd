#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvoreBin{
    int Num;
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
Parvore InstanciaArvore(Parvore a,int b){
    a = (Parvore)malloc(sizeof(Tarvore));
    a->DirArvore = NULL;
    a->EsqArvore = NULL;
    a->Num = b;
    return a;
}
Parvore InsereNaArvore(Parvore Pai, int Filho){
    if(ArvoreVazia(Pai)){
        Pai = InstanciaArvore(Pai ,Filho);
    }else{
        if(Filho < Pai->Num){
            Pai->EsqArvore = InsereNaArvore(Pai->EsqArvore, Filho);
        }else{
            Pai->DirArvore = InsereNaArvore(Pai->DirArvore, Filho);
        }
    }
    return Pai;
}
Parvore BuscaNaArvore(Parvore arvore,int dado){
    if(!ArvoreVazia(arvore)){
        if(arvore->Num>dado){
            return BuscaNaArvore(arvore->EsqArvore,dado);
        }else{
            if(arvore->Num<dado){
                return BuscaNaArvore(arvore->DirArvore,dado);
            }else
                return arvore;
        }
    }
    return NULL;
}
void ImprimePre(Parvore A){
  if(!ArvoreVazia(A)){
    printf("%i ",A->Num);
    ImprimePre(A->EsqArvore);
    ImprimePre(A->DirArvore);
  }
}

void ImprimeIn(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimeIn(A->EsqArvore);
    printf("%i ",A->Num);
    ImprimeIn(A->DirArvore);
  }
}

void ImprimePos(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimePos(A->EsqArvore);
    ImprimePos(A->DirArvore);
    printf("%i ",A->Num);
  }
}
Parvore maiorFilho(Parvore arvore){
    if(!ArvoreVazia(arvore->DirArvore)){
        return maiorFilho(arvore->DirArvore);
    }
    else{
        return arvore;
    }
}
Parvore RemoveItem(Parvore arvore, int Info){
    Parvore removido, maior;

    if(!ArvoreVazia(arvore)){
        if(Info > arvore->Num){
            arvore->DirArvore = RemoveItem(arvore->DirArvore, Info);
        }
        else if(Info < arvore->Num){
            arvore->EsqArvore = RemoveItem(arvore->EsqArvore, Info);
        }
        else{
            removido = arvore;
            if(ArvoreVazia(removido->EsqArvore) && ArvoreVazia(removido->DirArvore)){
                free(removido);
                return NULL;
            }
            else if(ArvoreVazia(removido->EsqArvore)){
                arvore = removido->DirArvore;
                free(removido);
                return arvore;
            }
            else if(ArvoreVazia(removido->DirArvore)){
                arvore = removido->EsqArvore;
                free(removido);
                return arvore;
            }
            else{
                maior = maiorFilho(removido->EsqArvore);
                arvore->Num = maior->Num;
                maior->Num = Info;
                arvore->EsqArvore = RemoveItem(arvore->EsqArvore, Info);
                return arvore;
            }
        }
    }
    return arvore;
}
int main(void){
    Parvore Arvore, buscado, Remove;
    char opcao[10];
    int num;

    Arvore = InicializaArvore();
    buscado = InicializaArvore();
    Remove = InicializaArvore();

    while(scanf("%s", opcao) != EOF){
        getchar();


        if(opcao != NULL){
            if(strcmp(opcao, "I") == 0){
                scanf("%i", &num);
                getchar();
                Arvore = InsereNaArvore(Arvore, num);
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
                scanf("%i", &num);
                getchar();
                buscado = BuscaNaArvore(Arvore,num);
                if(buscado == NULL){
                    printf("%i nao existe", num);
                }else if(buscado->Num == num){
                    printf("%i existe", num);
                }
                printf("\n");
            }else if(strcmp(opcao, "R") == 0){
                scanf("%i", &num);
                Arvore = RemoveItem(Arvore, num);
            }
        }
    }
}