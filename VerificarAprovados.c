/*6 - Faça um programa que leia os dados de 10 alunos (Nome, matrícula, Média Final), armazenando em um vetor.
Uma vez lidos os dados, divida estes dados em 2 novos vetores, o vetor dos aprovados e o vetor dos reprovados, considerando a média mínima para a aprovação como sendo 5.0.
Exibir na tela os dados do vetor de aprovados, seguido dos dados do vetor de reprovados.
*/

#include <stdio.h>

typedef struct{
    char nome[30];
    int matricula;
    float nota;
} Alunos;

void verificarAprovacoes(Alunos *alunos,Alunos *aprovados,Alunos *reprovados, int n){
    int auxA = 0,auxR = 0;
    for(int i = 0;i<n;i++){
        if(alunos[i].nota >= 5){
            aprovados[auxA] = alunos[i];
            auxA++;
        }else{
            reprovados[auxR] = alunos[i];
            auxR++;
        }
    }
    printf("Aprovados:");
    for(int i = 0;i<auxA;i++){
        printf("Nome: %s\n", aprovados[i].nome);
        printf("Matricula: %d\n", aprovados[i].matricula);
        printf("Media Final: %.2f\n", aprovados[i].nota);
    }
    printf("Reprovados:");
    for(int i  = 0;i<auxR;i++){
        printf("Nome: %s\n", reprovados[i].nome);
        printf("Matricula: %d\n", reprovados[i].matricula);
        printf("Media Final: %.2f\n", reprovados[i].nota);
    }
}

int main(){
    Alunos alunos[10] = {
        {"Joao Silva", 1001, 8.5},
        {"Maria Santos", 1002, 9.2},
        {"Pedro Oliveira", 1003, 1.0},
        {"Ana Costa", 1004, 6.9},
        {"Carlos Lima", 1005, 8.7},
        {"Julia Pereira", 1006, 2.0},
        {"Lucas Rodrigues", 1007, 9.8},
        {"Fernanda Alves", 1008, 7.2},
        {"Rafael Souza", 1009, 6.5},
        {"Amanda Martins", 1010, 8.9}
    } , aprovados[10] = {0}, reprovados[10] = {0};
    verificarAprovacoes(alunos,aprovados,reprovados,10);
}
