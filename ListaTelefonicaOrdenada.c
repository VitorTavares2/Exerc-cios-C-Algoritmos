/*5 - Utilizando uma estrutura, faça um programa que permita a entrada de nome, endereço e telefone de 10 pessoas e os imprima em ordem alfabética.
PS: use a função strcmp(s1, s2) para comparar as duas strings.*/
#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[3]; // 2 letras + '\0'
    char cidade[30];
    char bairro[30];
    char rua[30];
    int numero;
} Endereco;

typedef struct {
    char nome[30];
    int telefone;
    Endereco newEndereco;
} Pessoas;
void ordenarAlfabetica(Pessoas *pessoas,int n){
    Pessoas temp;
    for(int i = 0;i<n;i++){
        for(int j = i+1; j<n;j++){
            if(strcmp(pessoas[i].nome,pessoas[j].nome) > 0){
                temp  = pessoas[i];
                pessoas[i] = pessoas[j];
                pessoas[j] = temp;
            }
        }
    }
}

int main() {
    Pessoas pessoas[10] = {
        {"Ana Silva", 119876543, {"SP", "São Paulo", "Centro", "Rua das Flores", 101}},
        {"Bruno Costa", 219234567, {"RJ", "Rio de Janeiro", "Copacabana", "Av. Atlântica", 202}},
        {"Carlos Souza", 319112233, {"MG", "Belo Horizonte", "Savassi", "Rua da Liberdade", 303}},
        {"Daniela Rocha", 419998877, {"PR", "Curitiba", "Batel", "Rua XV de Novembro", 404}},
        {"Eduardo Lima", 519887766, {"RS", "Porto Alegre", "Moinhos", "Rua Padre Chagas", 505}},
        {"Fernanda Alves", 619776655, {"DF", "Brasília", "Asa Sul", "SQN 107", 606}},
        {"Gabriel Torres", 719665544, {"BA", "Salvador", "Barra", "Av. Oceânica", 707}},
        {"Helena Martins", 819554433, {"PE", "Recife", "Boa Viagem", "Rua Setúbal", 808}},
        {"Igor Ribeiro", 919443322, {"PA", "Belém", "Nazaré", "Av. Nazaré", 909}},
        {"Julia Fernandes", 679332211, {"MS", "Campo Grande", "Centro", "Rua 14 de Julho", 1001}}
    };
    ordenarAlfabetica(pessoas,10);
    for (int i = 0; i < 10; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Telefone: %d\n", pessoas[i].telefone);
        printf("Endereco: %s, %d - %s, %s, %s\n\n",
               pessoas[i].newEndereco.rua,
               pessoas[i].newEndereco.numero,
               pessoas[i].newEndereco.bairro,
               pessoas[i].newEndereco.cidade,
               pessoas[i].newEndereco.estado);
    }
    return 0;
}
