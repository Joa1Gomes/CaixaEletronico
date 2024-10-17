/******************************************************************/
/* Aluno1: João Victor Gomes - Número de matrícula: 12345678 */
/* Número de matrícula: 8159415 */
/* Exercício-Programa 1 — Caixa Eletrônico */
/* Programação Avançada - 2024 - Professor: Bruno Perillo */
/* Compilador: ... (DevC++ ou gcc) versão ... */
/******************************************************************/
#include <stdio.h>
   
int calculaTotal(int total, int qtdNotas[], int notas[]);
int mostraNotas(int qtdNotas[], int notas[]);
int realizaOperacoes(int operacao, int qtdNotas[], int notas[], int notasDeposito[], int valorSaque);
int totalDeposito(int notas[], int notasDeposito[]);
int realizaSaque(int qtdNotas[], int valorSaque, int notas[]); 

int main()
{
    //Define variáveis globais do código
    
	int operacao = 0;
	int qtdNotas[] = {0, 0, 0, 0, 0, 0, 0};
	int notasDeposito[] = {0, 0, 0, 0, 0, 0, 0};
	int notas[] = {100, 50, 20, 10, 5, 2, 1};
	int total = 0;
	int valorSaque = 0;

	/*
	Cada indice do array "notas" se refere a um valor.
	0= 100
	1= 50
	2= 20
	3= 10
	4= 5
	5= 2
	6= 1
	*/

    //Recebe quantas notas de cada tem no início das operações
	printf("Digite a quantidade de notas de 100, 50, 20, 10, 5, 2 e 1 respectivamente: \n");
    scanf("%i %i %i %i %i %i %i", &qtdNotas[0], &qtdNotas[1], &qtdNotas[2], &qtdNotas[3], &qtdNotas[4], &qtdNotas[5], &qtdNotas[6]);
    
	for (int i = 0; i < 7; i++)
	{
		printf("%i = %i\n ", notas[i], qtdNotas[i]);
	}
	
	realizaOperacoes(operacao, qtdNotas, notas, notasDeposito, valorSaque);
}

int realizaOperacoes(int operacao, int qtdNotas[], int notas[], int notasDeposito[], int valorSaque){
    printf("Digite o número da operação (0 = Saque | 1 = Depósito | -1 = Encerrar) \n");
	scanf("%i", &operacao);
    
    if(operacao == 0){
       printf("Digite o valor que deseja sacar: ");
        scanf("%d", &valorSaque);
        realizaSaque(qtdNotas, valorSaque, notas);
        realizaOperacoes(operacao, qtdNotas, notas, notasDeposito, valorSaque);
    
        
        
    }else if (operacao == 1){
        printf("Digite a quantidade de cada nota a ser depositada (100, 50, 20, 10, 5 , 2, 1 respectivamente) \n");
        scanf("%i %i %i %i %i %i %i", &notasDeposito[0], &notasDeposito[1], &notasDeposito[2], &notasDeposito[3], &notasDeposito[4], &notasDeposito[5], &notasDeposito[6]);
        
        for(int i = 0; i < 7; i++){
            qtdNotas[i] += notasDeposito[i];
        }
        
        printf("Total do depósito: ");
        totalDeposito(notas, notasDeposito);
        printf("\n");
        
        printf("Notas depositadas: \n");
        mostraNotas(notas, qtdNotas);
        
        realizaOperacoes(operacao, qtdNotas, notas, notasDeposito, valorSaque);
        
    } else if (operacao == -1){
        return 0;
        
    } else {
        realizaOperacoes(operacao, qtdNotas, notas, notasDeposito, valorSaque);
    } 
}

int totalDeposito(int notas[], int notasDeposito[]){
    int total = 0;
    for (int i = 0; i < 7; i++){
        total += notasDeposito[i] * notas[i];
    }
    printf("%i", total);
}

//Calcula valor total das notas
int calculaTotal(int total, int qtdNotas[], int notas[]){
    total = 0;
    for (int i = 0; i < 7; i++)
    {
        total += qtdNotas[i] * notas[i];   
    }
    return total;
}

int mostraNotas(int notas[], int qtdNotas[]){
    for (int i = 0; i < 7; i++)
	{
		printf("%i = %i\n ", notas[i], qtdNotas[i]);
	}
}

int realizaSaque(int qtdNotas[], int valorSaque, int notas[]) {
    int notas_usadas[7] = {0};

    for (int i = 0; i < 7; i++) {
        int qtd_notas_necessarias = valorSaque / notas[i];  
        int qtd_notas_disponiveis = qtdNotas[i];            

        if (qtd_notas_necessarias > 0) {
            int qtd_notas_usadas = (qtd_notas_necessarias <= qtd_notas_disponiveis) ? qtd_notas_necessarias : qtd_notas_disponiveis;

            valorSaque -= qtd_notas_usadas * notas[i]; 
            qtdNotas[i] -= qtd_notas_usadas;           
            notas_usadas[i] = qtd_notas_usadas;        
        }
    }

    if (valorSaque > 0) {
        printf("Não há notas suficientes para realizar o saque.\n\n\n");
        return 0;
    }
    printf("Notas usadas para o saque:\n");
    for (int i = 0; i < 7; i++) {
        if (notas_usadas[i] > 0) {
            printf("Notas de %d: %d\n\n\n", notas[i], notas_usadas[i]);
        }
    }
}