/*4 - Faça um programa em C que armazene em uma estrutura de dados (estrutura composta) os dados de um funcionário de uma empresa,
compostos de: Nome, Idade, Sexo (M/F), CPF, ´
Data de Nascimento, Codigo do Setor onde trabalha (0-99), Cargo que ocupa (string de ateé 30 caracteres) e Salario.
Os dados devem ser digitados pelo usuario, armazenados na estrutura e exibidos na tela.
Considere que a empresa tem até 10 funcionários, sendo assim, para armazenar todos os funcionários você deve definir um vetor do que armanzena a struct definida.
Implemente funções que recebe o vetor como argumento e:
a) retornar a quantidade de mulheres;
b) retorne e média de idade;
c) Retorne a quantidade de pessoas que recebem entre R$ 5000 e R$10000;
*/
#include <stdio.h>
typedef struct{
    char nome[30];
    int idade;
    char sexo;
    int cpf;
    int data;
    int setor;
    char cargo[50];
    float salario;
} Funcionario;
void calcularDados(Funcionario *funcionarios, int *p, int n){
    
    int qtdm = 0,sumIdade = 0,qtdS = 0;
    for(int i = 0;i<n;i++){
        //calcular QTD mulheres
        if(funcionarios[i].sexo == 'F')
            qtdm++;
        //média idade
        sumIdade += funcionarios[i].idade;
        //Retonar QTD 5k a 10k
        if(funcionarios[i].salario >= 5000 && funcionarios[i].salario <= 10000)
            qtdS++;
    }

    p[0] = qtdm;
    p[1] = sumIdade/n;
    p[2] = qtdS;
}
int main()
{
    Funcionario funcionarios[10] = {
        {"Ana Silva", 28, 'F', 123456789, 20200115, 1, "Analista de Dados", 4500.50},
        {"Bruno Costa", 35, 'M', 987654321, 20190310, 2, "Engenheiro de Software", 7200.00},
        {"Carla Souza", 30, 'F', 111222333, 20210401, 3, "Gerente de Projetos", 8500.75},
        {"Diego Ramos", 25, 'M', 444555666, 20220720, 1, "Suporte Técnico", 3200.00},
        {"Elisa Martins", 27, 'F', 777888999, 20230505, 4, "UX Designer", 4800.00},
        {"Felipe Rocha", 32, 'M', 112233445, 20200101, 2, "Desenvolvedor Back-end", 6500.25},
        {"Gabriela Lima", 29, 'F', 556677889, 20191212, 5, "Analista Financeira", 5300.90},
        {"Henrique Alves", 40, 'M', 998877665, 20170322, 3, "Coordenador de TI", 9100.00},
        {"Isabela Ferreira", 26, 'F', 334455667, 20230810, 4, "Desenvolvedora Front-end", 4700.50},
        {"João Pereira", 38, 'M', 223344556, 20180130, 5, "Administrador de Redes", 6100.00}
    };
    int p[3];
    calcularDados(funcionarios,p,10);
    printf("Quantidade de mulheres: %d \n" , p[0]);
    printf("Média Idade: %d \n" , p[1]);
    printf("Quantidade de pessoas que recebem entre 5k e 10k: %d" , p[2]);
    return 0;
}