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
Parvore RemoveItem(Parvore Raiz, int Referencia){
    Parvore Pai, Filho, aux;
  
    if(ArvoreVazia(Raiz)){
      return NULL;
    }else if(Raiz->Num != Referencia){
      if(Raiz->Num > Referencia){
        Raiz->EsqArvore = RemoveItem(Raiz->EsqArvore, Referencia);
      }else{
        Raiz->DirArvore = RemoveItem(Raiz->DirArvore, Referencia);      
      }
    }else if(Raiz->EsqArvore == NULL && Raiz->DirArvore == NULL){
      free(Raiz);
      Raiz = NULL;
    }else{
      Pai = Raiz;
      Filho = Raiz->EsqArvore;

      while(Filho->DirArvore != NULL){
        Pai = Filho;
        Filho = Filho->DirArvore;
      }
      Raiz->Num = Filho->Num;
      if(Pai!= Raiz){
        Pai->DirArvore = Filho->EsqArvore;
      }else{
        Pai->EsqArvore = Filho->EsqArvore;
      }
      free(Filho);
    }
    return Raiz;
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
                getchar();
                Remove = RemoveItem(Arvore, num);
                if(Remove != NULL){
                    Arvore = Remove;
                }
            }
        }
    }
}