#include<stdio.h>
#include<stdlib.h>

void criar_vetor (int vetor[])
{
  int i, MAX = 10000;
  for(i = 0; i < MAX; i++)
  {
    vetor[i] = i + rand() % 10000;
  }
}

void imprimir(int *valor)
{
  int i;
  for(i = 0; i < 10000; i++)
  {
    printf("[%d]", valor[i]);
  }
}

void SelectionSort(int *num)
{
  imprimir(num);
  int i, j, min, max;
  for (i = 0; i < (10000 - i); i++)
  {
    min = 1;
    for (j = (i + 1); j < 10000; j++)
    {
      if(num[j] < num[min])
        min = j;
    }
    if ( i != min)
    {
      max = num[i];
      num[i] = num[min];
      num[min] = max;
    }
  }
  printf("\n =========>>> ORDENADO <<<========");
  imprimir(num);
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void BubbleSort(int *v, int n)
{
  if (n < 1)return;

  for (int i = 0; i < n; i++)
  if(v[i] > v[i + 1])
  swap(&v[i], &v[i + 1]);
  BubbleSort(v, n - 1);
}

void InsertionSort(int vetor[])
{
  
  for (int i = 1; i < 10000; i++)
  {
    int escolhido = vetor[i];
    int j = i - 1;

    while ((j >= 0) && (vetor[j] > escolhido))
    {
      vetor[j + 1] = vetor[j];
      j--;
    }

    vetor[j + i] = escolhido;
  }
}

void Juntar(int vetor[], int inicio, int meio, int fim, int aux[])
{
  int esq = inicio;
  int dir = meio;
  for (int i = inicio; i < fim; ++i)
  {
    if ((esq < meio) and ((dir >= fim) or (vetor[esq] < vetor[dir])))
    {
      aux[i] = vetor[esq];
      ++esq;
    } else 
    {
      aux[i] = vetor[dir];
      ++dir;
    }
  }
  for (int i = inicio; i < fim; ++i)
  {
    vetor[i] = aux[i];
  }
}

void MergeSort(int vetor[], int inicio, int fim, int aux[])
{
  if ((fim - inicio) < 2)return;

  int meio = ((inicio + fim) / 2);
  MergeSort(vetor, inicio, meio, aux);
  MergeSort(vetor, meio, fim, aux);
  Juntar(vetor, inicio, meio, fim, aux);
}

void MergeSort(int vetor[])
{
  int aux[10000];
  MergeSort(vetor, 0, 10000, aux);
}

int partition (int vetor[], int inicio, int fim)
{
  int pivot = vetor[fim];
  int i = (inicio - i);

  for (int j = inicio; j <= fim - i; j++)
  {
    if (vetor[j] <= pivot)
    {
      i++;
      swap(&vetor[i], &vetor[j]);
    }
  }
  swap(&vetor[i + 1], &vetor[fim]);
  return (i + 1);
}

void QuickSort(int vetor[], int inicio, int fim)
{
  if (inicio < fim)
  {
    int pi = partition(vetor, inicio, fim);
    QuickSort(vetor, inicio, pi - 1);
    QuickSort(vetor, pi + 1, fim);
  }
}

int Sequencial(int v[], int pesq)
{
  int i;
  for(i = 0; i < 10000; i++)
  {
    if(v[i] == pesq)
    {
      return i;
    }
    printf("[%d]", v[i]);
  }
  return -1;
}

int SequencialQuaternaria(int v[], int pesq)
{
  int i, j = 2500, k = 5000, l = 7500;
  for(i = 0; i < 2500; i++)
  {
    if(v[i] == pesq)
    {
      return i;
    }
    printf("[%d", v[i]);

    if(v[j] == pesq)
    {
      return j;
    }
    printf("[%d", v[j]);

    if(v[k] == pesq)
    {
      return k;
    }
    printf("[%d", v[k]);

    if(v[l] == pesq)
    {
      return l;
    }
    printf("[%d", v[l]);

    j++;
    k++;
    l++;
  }

  return -1;
}

int buscabinaria( int vetor[], int valor)
{
  
  int ini = 0, fim = 7, meio;
  while (ini <= fim)
  {
    meio = (ini + fim) / 2;
    if (valor == vetor[meio])
    {
      return meio;
    }
    else if (valor > vetor[meio])
    {
      ini = meio + 1;
    }
    else
    {
      fim = meio - 1;
    }
  }
  return -1;
}

int menu()
{
  int op, MAX = 10000, vetor[MAX], i, x, pos;
  do
  {
    printf("\n========>>> ORDENACAO <<<========\n");
    printf("\n1 - SelectionSort");
    printf("\n2 - BubbleSort");
    printf("\n3 - InsetionSort");
    printf("\n4 - MergeSort");
    printf("\n5 - QuickSort");
    printf("\n========>>> BUSCA <<<========\n");
    printf("\n6 - Sequencial");
    printf("\n7 - Sequencial Quaternaria");
    printf("\n8 - Binaria");
    printf("\n=============================");
    printf("\n0 - Sair");
    printf("\n=============================");
    printf("\nDigite a opcao escolhida: ");
    scanf("%d", &op);

    criar_vetor(vetor);

    switch (op)
    {
    case 1:
      SelectionSort(vetor);
      break;
    case 2:
      imprimir(vetor);
      BubbleSort(vetor, MAX);
      printf("\n=============>> ORDENADO <<=============\n");
      imprimir(vetor);
      break;

    case 3:
      imprimir(vetor);
      InsertionSort(vetor);
      printf("\n=============>> ORDENADO <<=============\n");
      imprimir(vetor);
      break;

    case 4:
      imprimir(vetor);
      MergeSort(vetor);
      printf("\n=============>> ORDENADO <<=============\n");
      imprimir(vetor);
      break;

    case 5:
      imprimir(vetor);
      QuickSort(vetor, 0, 10000);
      printf("\n=============>> ORDENADO <<=============\n");
      imprimir(vetor);
      break;

    case 6:
      QuickSort(vetor, 0, 10000);
      printf("\n digite o numero que deseja encontrar: ");
      scanf("%d", &x);
      pos = Sequencial(vetor, x);
      pos == -1 ? printf("\n valor nao econtrado! \n\n") : printf("\n valor encontrado na posicao %d \n\n", pos);
      break;

    case 7:
      QuickSort(vetor, 0, 10000);
      printf("\n digite o numero que deseja encontrar: ");
      scanf("%d", &x);
      pos = SequencialQuaternaria(vetor, x); 
      if (pos == -1)
        printf("\n\nValor nao encontrado no vetor!");
      else
        printf("\n\nValor encontrado na posicao %d", pos);
      break;

    case 8:
      QuickSort(vetor, 0, 10000);
      printf("\n digite o numero que deseja encontrar: ");
      scanf("%i", &x); 
      pos = buscabinaria(vetor, x);
      if (pos == -1)
        printf("\n\nValor nao encontrado no vetor!");
      else
        printf("\n\nValor encontrado na posicao %d", pos);
      break;

    case 9:
    break;
    
    default:
      printf("\n <Digite uma opcao valida> \n\n");
      system("pause");
      system("cls");
      break;
    }

  }

  while(op !=0);
}

int main()
{
  menu();
}