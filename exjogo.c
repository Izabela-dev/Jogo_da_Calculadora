#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int dificuldade;
  int valor1;
  int valor2;
  int operacao;
  int resultado;
} Calcular;

void jogar();
void mostraInfo(Calcular calc); 
int somar(int resposta,Calcular calc);
int diminuir(int resposta,Calcular calc);
int multiplicar(int resposta, Calcular calc);
int pontos = 0;

int main(){
  srand(time(NULL));
  jogar();
  return 2;
}

void jogar(){

  while (1){
  
    Calcular calc;
    int dificuldade;

    printf("Informe o nivel de dificuladade desejado[ 1,2,3 ou 4 ]:\n");
    scanf("%d", &dificuldade);

    if (dificuldade < 1 || dificuldade > 5){
      printf("Nível de dificuldade inválido! Por favor,escolha entre 1 e 4.\n");
      continue;
    }

    calc.dificuldade = dificuldade;

    if (dificuldade == 5){
      printf("\n ====SURPRESA! Um desafio inesperado foi gerado!====\n");
      printf("Você escolheu o nível surpresa! Boa sorte!\n");
    }
      
    calc.operacao = rand() %3;
    
    if (calc.dificuldade == 1){
      calc.valor1 = rand() % 11;
      calc.valor2 = rand() % 11;    
    }
    else if (calc.dificuldade == 2){
      calc.valor1 = rand() % 101;
      calc.valor2 = rand() % 101;
    }
    else if (calc.dificuldade == 3){
      calc.valor1 = rand() % 1001;
      calc.valor2 = rand() % 1001;
    }
    else if (calc.dificuldade == 4){
      calc.valor1 = rand() % 10001;
      calc.valor2 = rand() % 10001;
    }
    else if (calc.dificuldade == 5){
    calc.valor1 = rand() % 100001;
    calc.valor2 = rand() % 100001;
    }
    
    int resposta;
    printf("Informe o rasultado para a seguinte opreção: \n");

    if(calc.operacao == 0){
      printf("%d + %d = ", calc.valor1,calc.valor2);
      scanf("%d", &resposta);
      if (somar(resposta, calc)){
        pontos += 1;
       printf("Você tem %d ponto(s).\n",pontos);
      }
    }
    else if(calc.operacao == 1){
      printf("%d - %d = ",calc.valor1,calc.valor2);
      scanf("%d", &resposta);
      if (diminuir(resposta,calc)){
        pontos += 1;
        printf("Você tem %d ponto(s).\n",pontos);
      }  
    }   
    else if (calc.operacao == 2) {
      printf("%d * %d = ", calc.valor1,calc.valor2);
      scanf("%d", &resposta);
      if (multiplicar(resposta,calc)){
        pontos += 1;
        printf("Você tem %d ponto(s).\n",pontos);
      } 
    }
    else{
      printf("A operação %d não é reconhecida.\n",calc.operacao);
    }

    printf("Deseja continuar jogando?[1 - sim, 0 - não]:\n");
    int continuar;
    scanf("%d", &continuar);

    if (continuar == 0){
      printf("Você finalizou com %d pontos(s).\n",pontos);
      printf("Até a próxima.\n");
      exit(0);
   
    } 
  } 
}

void mostraInfo(Calcular calc){
  char op[25];

  if (calc.operacao == 0){
    sprintf(op,"Somar");
  }
  else if(calc.operacao == 1){
    sprintf(op, "DIminuir");
  }
  else if(calc.operacao == 2){
    sprintf(op,"Multiplicar");
  }
  else{
    sprintf(op,"Operação desconhecida");
  }
  printf("Valor 1: %d\nValor 2: %d\nDificuldade: %d\nOperaçô: %s",
   calc.valor1, calc.valor2, calc.dificuldade,op);
}

int somar(int resposta, Calcular calc){
  int resultado = calc.valor1 + calc.valor2;
  calc.resultado = resultado;
  int certo = 0;

  if (resposta == calc.resultado){
    printf("Resposta correta!\n");
    certo = 1;
  }
  else{
    printf("Resposta errada! O correta é %d + %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
  }

  return certo;

}

int diminuir(int resposta, Calcular calc){

  int resultado = calc.valor1 - calc.valor2;
  calc.resultado = resultado;
  int certo = 0;

  if (resposta == calc.resultado){
    printf("Resposta correta!\n");
    certo = 1;
  }
  else{
    printf("Resposta errada! O correta é %d - %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
  }

  return certo;
}

int multiplicar (int resposta, Calcular calc){

  int resultado = calc.valor1 *calc.valor2;
  calc.resultado = resultado;
  int certo =  0;

  if (resposta == calc.resultado){
    printf("Resposta correta!\n");
    certo = 1;
    
  }
  else{
    printf("Resposta errada! O correta é %d * %d = %d\n",calc.valor1,calc.valor2,calc.resultado);
  }
  
  return certo;

}