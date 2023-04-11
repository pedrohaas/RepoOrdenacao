#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MensagemDeBoasVindas(); // Printa mensagem
void Algortimos (); // Seleciona o algoritmo a ser usado
void Selecao(); // Seleciona a opcao do user
void PrintaVetor(int vetor[]); // printa um vetor aleatorio na tela
void TextoRecursao(); 

// Algoritmos de ordenacao =================================================
void swap(int vetor[], int a, int b);
void TextoBubblesort();
void bubblesort(int vetor[], int n);
void TextoInsertionSort();
void insertionsort(int vetor[], int n);
void TextoSelectionSort();
void selectionsort (int vetor[], int n);
void TextoMergeSort();
void merge(int vetor[], int aux[], int imin, int imid, int imax);
void mergesort(int vetor[], int aux[], int imin, int imax);
void TextoQuickSort();
int partition(int vetor[], int imin, int imax);
void quicksort(int vetor[], int imin, int imax);
void TextoHeapsort();
void heap(int vetor[], int n, int i);
void heap_sort(int vetor[], int n);
// ==========================================================================

int main() {

    MensagemDeBoasVindas();
    Selecao();

    printf("\n\nObrigado por visitar nosso projeto para o HackoonSpace, entidade de cultura Hacker na Universidade Federal de São Carlos, campus Sorocaba.\n\n");

    return 0;
}


void MensagemDeBoasVindas () {
    printf("Olá, jovem padawan! Seja bem vindo ao nosso repositório de algoritmos de ordenação, aqui você pode testar diferentes métodos, tanto iterativa quanto recursivamente, e ainda compreender o funcionamento de cada um deles!\n\n");
}

void Selecao() {

    int opcao = 0;

    printf("Selecione a opção que desejar: \n1 - Quero testar os algoritmos!\n2 - Quero aprender sobre recursão\n3 - Sair\n\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: Algortimos(); break;
    case 2: TextoRecursao(); Selecao(); break;
    case 3: break;
    }

}

void Algortimos () {

    int vetor[10], aux[10] = {0}, min = 0, mid = 5, max = 9;

    srand(time(NULL));
  
    for (int o = 0; o < 10; o++) {
      vetor[o] = rand() % 99;
    }
  
    int opcao = 0;

    printf("\n\nQual algoritmo de ordenação você deseja usar?\n1 - Bubblesort\n2 - InsertionSort\n3 - SelectionSort\n4 - MergeSort\n5 - QuickSort\n6 - HeapSort\n7 - Voltar...\n\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: TextoBubblesort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor); bubblesort(vetor, 10); printf("\nvetor ordenado: "); PrintaVetor(vetor); Algortimos(); break;
    case 2: TextoInsertionSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor); insertionsort(vetor, 10); printf("\nvetor ordenado: "); PrintaVetor(vetor); Algortimos(); break;
    case 3: TextoSelectionSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor); selectionsort(vetor, 10); printf("\nvetor ordenado: "); PrintaVetor(vetor); Algortimos(); break;
    case 4: TextoMergeSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor); mergesort(vetor, aux, min, max); printf("\nvetor ordenado: "); PrintaVetor(vetor); Algortimos(); break;
    case 5: TextoQuickSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor); quicksort(vetor, min, max); printf("\nvetor ordenado: "); PrintaVetor(vetor); Algortimos(); break;
    case 6: TextoHeapsort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor); heap_sort(vetor, 10); printf("\nvetor ordenado: "); PrintaVetor(vetor); Algortimos(); break;
    case 7: Selecao(); break;
    }

}

void PrintaVetor(int vetor[]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
}

void TextoRecursao() {
    printf("\nRecursão é uma técnica de programação que envolve a chamada de uma função a si mesma. Em outras palavras, uma função recursiva é aquela que se chama dentro de sua própria definição.\n\nAo invocar uma função recursiva, a mesma é capaz de resolver um problema dividindo-o em subproblemas menores, até que um ou mais casos-base sejam alcançados, momento em que a recursão para e os resultados obtidos são combinados para resolver o problema original.\n\nUma função recursiva precisa sempre possuir um caso-base, que é uma condição que indica quando a recursão deve parar. Caso contrário, a função irá chamar a si mesma infinitamente, o que levará a um estouro de pilha e causará um erro no programa.\n\nA recursão pode ser uma ferramenta poderosa para resolver problemas complexos, especialmente aqueles que possuem uma estrutura recursiva natural, como algoritmos de busca em árvores, ordenação de listas encadeadas, entre outros.\n\nNo entanto, o uso excessivo de recursão pode levar a um consumo excessivo de memória e pode ser menos eficiente do que abordagens iterativas em alguns casos. Portanto, é importante considerar cuidadosamente o uso de recursão em um programa e verificar se há uma alternativa mais eficiente.\n\n");
}

void swap(int vetor[], int a, int b) {int aux = vetor[a]; vetor[a] = vetor[b]; vetor[b] = aux;}

void TextoBubblesort() {
    printf("\nO algoritmo Bubblesort é um algoritmo de classificação (ou ordenação) simples e comumente usado, embora não seja tão eficiente quanto outros algoritmos mais avançados em termos de tempo de execução. Ele funciona comparando cada par de elementos adjacentes na lista e trocando-os de posição se estiverem na ordem errada. Esse processo é repetido várias vezes até que toda a lista esteja ordenada.\n\nO funcionamento do algoritmo pode ser descrito em cinco passos simples:\n\n1 - Começando com o primeiro elemento (índice 0), compare-o com o próximo elemento (índice 1) na lista.\n2 - Se o primeiro elemento for maior que o próximo elemento, troque-os de posição.\n3 - Continue percorrendo a lista, comparando elementos adjacentes e trocando-os de posição se estiverem fora de ordem.\n4 - Repita esse processo para cada par de elementos adjacentes na lista, percorrendo a lista várias vezes até que nenhum elemento seja trocado de posição.\n5 - Quando nenhum elemento for mais trocado de posição, a lista estará ordenada.n");

}

void bubblesort(int vetor[], int n) {

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if ( vetor[j] > vetor[j+1] ) { swap(vetor, j, j+1); }
        }
    }

}

void TextoInsertionSort() {
    printf("\nO insertionsort é um algoritmo de ordenação simples e eficiente, especialmente para listas pequenas ou para listas que já estão quase ordenadas. O algoritmo funciona de maneira semelhante ao processo de classificação de cartas em uma mão de baralho.\n\nO funcionamento do algoritmo pode ser descrito em quatro passos simples:\n\n1 - Começando com o segundo elemento da lista (índice 1), compare-o com o elemento anterior (índice 0) na lista.\n2 - Se o elemento anterior for maior que o atual, mova o elemento anterior uma posição à frente e continue a comparar com o próximo elemento anterior na lista até encontrar o local correto para inserir o elemento atual.\n3 - Repita esse processo para cada elemento subsequente na lista até que todos os elementos estejam ordenados.\n4 - Quando todos os elementos estiverem ordenados, a lista estará classificada.\n");

}

void insertionsort(int vetor[], int n) {

    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && vetor[j] < vetor[j-1]) {
            swap(vetor, j, j-1); j--;
        }
    }

}

void TextoSelectionSort() {
    printf("\nO selectionsort é um algoritmo simples de ordenação que funciona encontrando o menor elemento da lista e colocando-o na primeira posição, depois encontrando o próximo menor elemento e colocando-o na segunda posição e assim por diante. O algoritmo funciona selecionando o menor elemento da lista em cada iteração e trocando-o com o elemento na primeira posição da lista não classificada.\n\nO funcionamento do algoritmo pode ser descrito em três passos simples:\n\n1 - Defina o limite da lista classificada no início da lista como 0.\n2 - Encontre o menor elemento na lista não classificada (isto é, os elementos após o limite da lista classificada).\n3 - Troque o menor elemento encontrado com o primeiro elemento da lista não classificada e atualize o limite da lista classificada para incluir o elemento trocado.\n4 - Repita esses passos para cada elemento não classificado na lista até que toda a lista esteja ordenada.\n");

}

void selectionsort (int vetor[], int n) {

    for (int i = 0; i < n-1; i++) {
        int minimo = i;
        for (int j = i+1; j < n; j++) {
            if (vetor[j] < vetor[minimo]) { minimo = j; }
        }
        swap(vetor, minimo, i); 
    }

}

void TextoMergeSort() {
    printf("\nO merge sort é um algoritmo de ordenação muito eficiente e rápido, que usa o princípio de divisão e conquista para dividir a lista em duas partes menores, ordená-las separadamente e, em seguida, combiná-las em uma única lista ordenada. O algoritmo é conhecido por ter uma complexidade de tempo O(n log n), o que o torna uma escolha popular para a ordenação de grandes conjuntos de dados.\n\nO funcionamento do algoritmo pode ser descrito em três passos principais:\n\n1 - Divida a lista em duas metades, até que cada sublista contenha apenas um elemento ou esteja vazia.\n2 - Recursivamente ordene cada sublista dividida.\n3 - Combine as sub-listas ordenadas em uma única lista ordenada, usando o algoritmo de fusão (merge).\n");

}

void merge(int vetor[], int aux[], int imin, int imid, int imax){
    int i = imin, j = imid+1;
    
    for (int k = imin; k <= imax; k++)
        aux[k] = vetor[k];

    for (int k = imin; k <= imax; k++)
        if (i > imid)
            vetor[k] = aux[j++];
        else if(j > imax)
            vetor[k] = aux[i++];
        else if(aux[j] < aux[i])
            vetor[k] = aux[j++];
        else
            vetor[k] = aux[i++];
}

void mergesort(int vetor[], int aux[], int imin, int imax) {
    if (imax <= imin) return;

    int imid = imin + ((imax - imin) / 2);
    mergesort(vetor, aux, imin, imid);
    mergesort(vetor, aux, imid+1, imax);
    merge(vetor, aux, imin, imid, imax);
}

void TextoQuickSort() {
    printf("\nO QuickSort é um algoritmo de ordenação eficiente que utiliza a estratégia de dividir e conquistar para ordenar uma lista de elementos. Ele é muito utilizado em diversas aplicações devido à sua velocidade e eficiência, sendo capaz de ordenar grandes quantidades de dados em pouco tempo.\n\nO funcionamento do QuickSort pode ser resumido em três passos:\n\n1 - Escolha um elemento como o pivô da lista. Geralmente é escolhido o primeiro elemento da lista, mas também é possível escolher outros elementos, como o elemento central da lista ou um elemento escolhido aleatoriamente.\n2 - Reorganize a lista de modo que todos os elementos menores que o pivô estejam à sua esquerda, e todos os elementos maiores estejam à sua direita.\n3 - Recursivamente aplique o QuickSort para as sublistas à esquerda e à direita do pivô.\n");

}

int partition(int vetor[], int imin, int imax) {
    
    int i = imin, j = imax+1;

    while( 1 ) {
        while (vetor[++i] < vetor[imin])
            if(i == imax) break;
        while (vetor[imin] < vetor[--j])
            if (j == imin) break;
        if (i >= j)
            break;
        swap(vetor,i,j);
    }
        swap(vetor,imin,j);
        return j;
}

void quicksort(int vetor[], int imin, int imax) {
    if (imax <= imin) return;
    int i = partition(vetor, imin, imax);
    quicksort(vetor, imin, i-1);
    quicksort(vetor, i+1, imax);
}

void TextoHeapsort() {
    printf("\nO HeapSort é um algoritmo de ordenação que utiliza uma estrutura de dados chamada Heap para ordenar uma lista de elementos. A Heap é uma árvore binária completa que satisfaz a propriedade de Heap, que pode ser Max-Heap ou Min-Heap. Na Max-Heap, cada nó pai é maior ou igual a seus filhos, enquanto na Min-Heap, cada nó pai é menor ou igual a seus filhos.\n\nO funcionamento do HeapSort pode ser resumido em dois passos:\n\n1 - Construir uma Max-Heap com a lista de elementos.\n2 - Extrair o elemento máximo da Heap e colocá-lo no final da lista. Em seguida, reconstruir a Heap e repetir o processo até que todos os elementos estejam ordenados.\n");

}

void heap(int vetor[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && vetor[esq] > vetor[maior])
        maior = esq;

    if (dir < n && vetor[dir] > vetor[maior])
        maior = dir;

    if (maior != i) {
        int temp = vetor[i];
        vetor[i] = vetor[maior];
        vetor[maior] = temp;
        heap(vetor, n, maior);
    }
}

void heap_sort(int vetor[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(vetor, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        heap(vetor, i, 0);
    }
}


