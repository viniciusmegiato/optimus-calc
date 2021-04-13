#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "menu_analise_combinatoria.h"
#include "menu.h"

void handleMenuAnaliseCombinatoriaInput(char selectedOption[1]);

int fatorial(float n)
{
  if (n == 0)
    return 1;
  else
    return n * fatorial(n - 1);
}

float getUserInput(char varName[1])
{
  float n;

  printf("Insira o valor de %s, sabendo que %s deve ser um numero natural:\n", varName, varName);
  scanf("%f", &n);

  return n;
}

bool isInteger(float n)
{
  int aux = n;

  if (n < 0 || n != aux)
    return false;
  else
    return true;
}

int combinacaoSimples(float n, float k)
{
  int nFatorial = fatorial(n);
  int kFatorial = fatorial(k);
  int subtracaoFatorial = fatorial(n - k);

  return nFatorial / (kFatorial * subtracaoFatorial);
}

int arranjoSimples(float n, float k)
{
  int nFatorial = fatorial(n);
  int subtracaoFatorial = fatorial(n - k);

  return nFatorial / subtracaoFatorial;
}

int permutacaoSimples(float n)
{
  return fatorial(n);
}

void getMenuAnaliseCombinatoriaInput()
{
  char selectedOption[1];

  scanf("%s", &selectedOption);

  handleMenuAnaliseCombinatoriaInput(selectedOption);
}

void handleMenuAnaliseCombinatoriaInput(char selectedOption[1])
{
  if (strcmp(selectedOption, "1") == 0)
  {
    float n = getUserInput("n");

    if (isInteger(n))
    {
      printf("Resultado: %d", permutacaoSimples(n));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuAnaliseCombinatoriaInput("1");
    }
  }
  else if (strcmp(selectedOption, "2") == 0)
  {
    float n = getUserInput("n");
    float k = getUserInput("k");

    if (isInteger(n) && isInteger(k))
    {
      printf("Resultado: %d", arranjoSimples(n, k));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuAnaliseCombinatoriaInput("2");
    }
  }
  else if (strcmp(selectedOption, "3") == 0)
  {
    float n = getUserInput("n");
    float k = getUserInput("k");

    if (isInteger(n) && isInteger(k))
    {
      printf("Resultado: %d", combinacaoSimples(n, k));
    }
    else
    {
      puts("Ops, entrada invalida.");

      handleMenuAnaliseCombinatoriaInput("3");
    }
  }
  else if (strcmp(selectedOption, "4") == 0)
  {
    puts("Selecionou 4");
  }
  else if (strcmp(selectedOption, "5") == 0)
  {
    puts("Selecionou 5");
  }
  else if (strcmp(selectedOption, "6") == 0)
  {
    puts("Selecionou 6");
  }
  else if (strcmp(selectedOption, "7") == 0)
  {
    showMainMenu();
  }
  else
  {
    puts("Ops, insira uma opcao valida:");

    getMenuAnaliseCombinatoriaInput();
  }
}

void showMenuAnaliseCombinatoria()
{
  puts("SUBMENU ANALISE COMBINATORIA");
  puts("1. Permutacao Simples: P(n)");
  puts("2. Arranjo Simples: A(n, k)");
  puts("3. Combinacao Simples: C(n, k)");
  puts("4. Arranjo com Repeticao: AR(n, k)");
  puts("5. Combinacao com Repeticao: CR(n, k)");
  puts("6. Permutacao com Repeticao: P(n, k1, ..., kp)");
  puts("7. Voltar ao Menu Anterior");

  getMenuAnaliseCombinatoriaInput();
}
