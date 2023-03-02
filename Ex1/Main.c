#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ArvoreBin{
    int nivel;
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
        }else if(arvore->Num<dado){
            return BuscaNaArvore(arvore->DirArvore,dado);
        }else{
            return arvore;
        }
    }
    return NULL;
}
void ImprimePre(Parvore A){
  if(!ArvoreVazia(A)){
    printf(" %i",A->Num);
    ImprimePre(A->EsqArvore);
    ImprimePre(A->DirArvore);
  }
}

void ImprimeIn(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimeIn(A->EsqArvore);
    printf(" %i",A->Num);
    ImprimeIn(A->DirArvore);
  }
}

void ImprimePos(Parvore A){
  if(!ArvoreVazia(A)){
    ImprimePos(A->EsqArvore);
    ImprimePos(A->DirArvore);
    printf(" %i",A->Num);
  }
}

int main(void) {
  Parvore raiz, novo;
  int casos, i, qtd, j, num;

  scanf("%d", &casos); 

  for(i=1;i<=casos;i++){

    raiz = InicializaArvore();

    scanf("%d", &qtd);

    for(j=0;j<qtd;j++){
      scanf("%d", &num);
      raiz = InsereNaArvore(raiz, num);
    }
    
    printf("Case %d:", i);
    printf("\nPre.:");
    ImprimePre(raiz);
    printf("\nIn..:");
    ImprimeIn(raiz);
    printf("\nPost:");
    ImprimePos(raiz);

    printf("\n\n");
  }
  
return 0;
}