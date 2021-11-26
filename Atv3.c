#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//NoArvore* -> ptrNoArvore
typedef struct NoArvore* ptrNoArvore;

//NoArvore (pode ter 2 conexões - filhos)
typedef struct NoArvore{
  //int chave(info)
  int x;
  char termos[1000];
  //filho esquerda (ptrNoArvore)
  ptrNoArvore esquerda;
  //filho direita (ptrNoArvore)
  ptrNoArvore direita;
}NoArvore;



//1- inicializar
void iniciaArvore(ptrNoArvore *arvore){
  (*arvore) = NULL;
}

//2- inserir(bool)
bool insereArvore(ptrNoArvore *arvore, int x){
  //condição parada de recursão(true )
  //passo 1- quando for inserir (ptr==NULL)://cheguei na folha
if( (*arvore)==NULL){
  // criar um novo no arvore, alocar memoria dele
  (*arvore) = malloc(sizeof(NoArvore));
  // copiar valor dentro do no
  (*arvore)->x = x;
  // filho direita && filho esquerda == NULL
  (*arvore)->esquerda = (*arvore)->direita = NULL;
  // return verdadeiro
  return (true);
}

//condição parada de recursão(false cahave iguais)
//se noCorrente.x == x
if( (*arvore)->x == x){
  //nao faz nada, return false
  printf("chave duplicada\n");
  return (false);
}

//passo da recursão
//passo 2 x > noCorrente.x
if(x> (*arvore)->x){
  //vai para direita
  //recursivamente(inserção - subarvore direita, no Corrente)
    //subarvore da direita -> filho direita
     return(insereArvore(& (*arvore)->direita,x));
} else{
  //passo 3
  //vai para esquerda
  //recursivamente ( inserção - subarvore esquerda, no corrente)
  //subarvore esquerda ->filho esquerda
  return(insereArvore(& (*arvore)->esquerda,x));

}


  }
  //3- consultar
//bool pesquisar(A, x) ->true/ false
bool pesquisaArvore(ptrNoArvore *arvore, int x){
  //se atingir o no == NULL -> return false
  if( (*arvore) ==NULL) return (false);
  // se (*arvore)->x == x-> return true
  if( (*arvore)-> x == x) return (true);
//recursão
  //chamar o filho da direita
  if( x > (*arvore)->x){
    return(pesquisaArvore(&(*arvore)->direita,x));
    //chamar o filho esquerda
  }
else{
    return(pesquisaArvore(&(*arvore)->esquerda,x));
  }
}

//5- imprimir
void percursoPreOrdem(ptrNoArvore *arvore){
  if( (*arvore) == NULL)return;
  //imprimir
  printf("%d ",(*arvore)->x);
  //esquerda
  percursoPreOrdem(&(*arvore)->esquerda);
  //direita
  percursoPreOrdem(&(*arvore)->direita);
}

void percursoPosOrdem(ptrNoArvore *arvore){
  if( (*arvore) == NULL)return;
  //esquerda
  percursoPosOrdem(&(*arvore)->esquerda);
  //direita
  percursoPosOrdem(&(*arvore)->direita);
  //imprimir
  printf("%d ",(*arvore)->x);
}

void percursoEmOrdem(ptrNoArvore *arvore){
  if( (*arvore) == NULL)return;
  //esquerda
  percursoEmOrdem(&(*arvore)->esquerda);
  //imprimir
  printf("%d ",(*arvore)->x);
  //direita
  percursoEmOrdem(&(*arvore)->direita);
}


// 4- está vazia
bool estaVazia(ptrNoArvore *arvore){
  return((*arvore)==NULL);
}
// destruir
void destruirArvore(ptrNoArvore *arvore){
  if( (*arvore)!= NULL){
    destruirArvore(&(*arvore)->esquerda);
    destruirArvore(&(*arvore)->direita);
    free(*arvore);
    *arvore = NULL;

  }
}

char LeArquivo(ptrNoArvore *arvore, FILE *entrada){
  fscanf(entrada,"%s,",&(*arvore)->termos);
  printf("aa %s\n",&(*arvore)->termos);
}


int main(int argc, char const *argv[]) {

  ptrNoArvore raiz;//criação da raiz da arvore
char texto[10000];
char caractere;

  FILE* entrada;
  entrada = fopen("entrada1.txt","r");
//  LeArquivo(&raiz,entrada);
int i=0;
while ((caractere = fgetc(entrada)) =='<') {
i++;
printf("%d\n",i);
  fscanf(entrada,"%s",&texto);
  printf("%s\n",&texto);
}

  // if(entrada == NULL ){//checagem de erro da abertura de arquivo de entrada
  //   printf("Arquivo de entrada Vazio\n");
  // }
  FILE* saida;
  saida = fopen("saida.txt","w");
  // if(saida == NULL ){//checagem de erro da abertura de arquivo de entrada
  //   printf("Erro ao abrir arquivo de saida\n");
  // }
  return 0;
}
