#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int idade;
    float media;
} Aluno;

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno_2;

typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno_3;



int main(){
    Aluno aluno ={"Pedro",28,6.7};
    printf("Nome: %s\n",aluno.nome);
    printf("Idade: %d\n",aluno.idade);
    printf("Media: %.2f",aluno.media);

    Aluno_2 aluno1 ={"Jhonatan",29,8.9};
    printf("Nome: %s\n",aluno1.nome);
    printf("Idade: %d\n",aluno1.idade);
    printf("Media: %.2f",aluno1.media);

    Aluno_3 aluno2 = {"Felipe",30,7.0};
    printf("Nome: %s\n",aluno2.nome);
    printf("Idade: %d\n",aluno2.idade);
    printf("Media: %.2f",aluno2.media);

    return 0;
}
