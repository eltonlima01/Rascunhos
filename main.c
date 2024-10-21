#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

typedef struct usuario{
    char unome[50], uuser[50], uemail[50], usenha[50];
    struct usuario *proximo;
}usuario;

void exibirlista(usuario *topo);
void inserirusuario(usuario **topo, char s1[], char s2[], char s3[], char s4[]);
void liberarlista(usuario *topo);

int main(){
    setlocale(LC_ALL,"portuguese");
    FILE *file0; //Ponteiro de arquivos do texto de usuários;
    file0=fopen("usuarios.txt", "r");

    usuario *topo=NULL;
    char nome[50], user[50], email[50], senha[50];

    while(fscanf(file0, "%[^\n.]. %s %s %s\n", nome, user, email, senha)!=EOF){
        inserirusuario(&topo, nome, user, email, senha);
    }
    puts("[LISTA DE USUÁRIOS]");
    exibirlista(topo);
    liberarlista(topo);
    fclose(file0);
    return 0;
}

void exibirlista(usuario *topo){
    usuario *atual=topo;
    
    while(atual!=NULL){
        printf("Nome: %s / Usuário: %s / E-mail: %s / Senha: %s\n",
        (*atual).unome, (*atual).uuser, (*atual).uemail, (*atual).usenha);
        atual=(*atual).proximo;
    }
}

void liberarlista(usuario *topo){
    usuario *atual=topo, *tmprr;
    
    while(atual!=NULL){
        tmprr=atual;
        atual=(*atual).proximo;
        free(tmprr);
    }
}

usuario* criarusuario(char s1[], char s2[], char s3[], char s4[]){
    usuario *u=(usuario*)malloc(sizeof(usuario));
    
    if(u==NULL){
        perror("[ERRO]");
        return NULL;
    }
    
    strcpy((*u).unome, s1); strcpy((*u).uuser, s2);
    strcpy((*u).uemail, s3); strcpy((*u).usenha, s4);
    (*u).proximo=NULL;
    return u;
}

void inserirusuario(usuario **topo, char s1[], char s2[], char s3[], char s4[]){
    usuario *novousuario=criarusuario(s1, s2, s3, s4);
    
    if(novousuario!=NULL){
        (*novousuario).proximo=*topo;
        *topo=novousuario;
    }
}
