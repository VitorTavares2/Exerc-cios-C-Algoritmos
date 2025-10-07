/*7 - Faça um programa que gerencie o estoque de um mercado e:
Crie e leia um vetor de 5 produtos, com os dados: código (inteiro), nome (máximo 15 letras), preço e 
quantidade.
Leia um pedido, composto por um código de produto e a quantidade. Localize este código no vetor e, 
se houver quantidade suficiente para atender ao pedido integralmente, atualize o estoque e informe o usuário. 
Repita este processo até ler um código igual a zero.
Se, por algum motivo, não for possível atender ao pedido, mostre uma mensagem informando qual erro ocorreu. */

#include <stdio.h>
typedef struct{
  int codigo;
  char nome[15];
  float preco;
  int quantidade;
} Produtos;

void comprarProduto(Produtos *produto,float *p, int code, int qtd, int n){
    int vrfy = 0;
    float preco,precoFinal = 0;
    for(int i  = 0;i<n;i++){
        if(produto[i].codigo == code){
            printf("Produto Encontrado!");
            if(produto[i].quantidade >= qtd){
                produto[i].quantidade -= qtd;
                preco = (produto[i].preco*qtd);
                printf("Quantidade selecionada Válida! \n");
                printf("Preco da sua compra será %f \n" , preco);
                printf("A quantidade atual após sua compra é : %d \n", produto[i].quantidade);
                printf("O total desta compra foi adicionado ao preco final \n");
                precoFinal += preco;
            }
            else{
                printf("Infelizmente não temos produtos o suficiente para a quantidade selecionada.\n");
                return;
            }
            vrfy++;
        }
    }
    
    if(vrfy == 0){
        printf("Produto não encontrado!\n");
        return;
    }
    p[0] = precoFinal;
}

int main(){
    Produtos produto[5] = {
        {101, "Arroz", 25.90, 50},
        {102, "Feijao", 8.50, 30},
        {103, "Macarrao", 4.75, 40},
        {104, "Leite", 5.20, 25},
        {105, "Cafe", 12.30, 20}
    };
    int code, qtd = 0;
    float p[1] = {0};
    do{
        printf("Escolha o Produto pelo Código:");
        scanf("%d" , &code);
        
        if(code == 0)
            break;
            
        printf("Escolha a quantidade:");
        scanf("%d" , &qtd);
        comprarProduto(produto,p,code,qtd,5);
    }while(code!=0);
    printf("O preco final da compra foi de : %f" , p[0]);
}
