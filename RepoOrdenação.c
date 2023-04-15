#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MensagemDeBoasVindas(); // Printa mensagem
void Algortimos (int numeros, int quantidade, int tipoVet); // Seleciona o algoritmo a ser usado
void Selecao(int numeros, int quantidade, int tipoVet); // Seleciona a opcao do user
void PrintaVetor(int vetor[], int quantidade); // printa um vetor aleatorio na tela
void TextoRecursao(); 
void printaSeparacao();

// Algoritmos de ordenacao =================================================
void swap(int vetor[], int a, int b);
void TextoBubblesort();
void bubblesort(int vetor[], int n);
void TextoInsertionSort();
void insertionsort(int vetor[], int n);
void TextoSelectionSort();
void selectionsort (int vetor[], int n);
void TextoMergeSort();
void merge(int vetor[], int aux[], int imin, int imid, int imax, int n);
void mergesort(int vetor[], int aux[], int imin, int imax, int quantidade);
void TextoQuickSort();
int partition(int vetor[], int imin, int imax, int n);
void quicksort(int vetor[], int imin, int imax, int n);
void TextoHeapsort();
void heap(int vetor[], int n, int i);
void heap_sort(int vetor[], int n);
// ==========================================================================

int main() {

    MensagemDeBoasVindas();

    int maior_num = 0, quantidade = 0, tipo_vetor = 0;
    char vetor;

    printf("Selecione a forma do vetor:\na - vetor fixo digitado pelo usuario\nb - vetor aleatorio gerado automaticamente\n"); scanf(" %c", &vetor);

    if(vetor == 'a'){ //se o vetor for fixo, recebe apenas a quantidade de números do vetor 
        tipo_vetor = 1;
        printf("Insira a quantidade de numeros do vetor: "); scanf("%d", &quantidade); 
    }
    if(vetor == 'b') { //se o vetor for aleatorio recebe a quantidade de númeors e maior valor possivel do vetor
        tipo_vetor = 2;
        printf("Insira a quantidade de numeros do vetor: "); scanf("%d", &quantidade); 
        printf("Insira o maior numero possivel do vetor: "); scanf("%d", &maior_num);
    }

    Selecao(maior_num, quantidade, tipo_vetor);

    printf("\n\nObrigado por visitar nosso projeto para o HackoonSpace, entidade de cultura Hacker na Universidade Federal de Sao Carlos, campus Sorocaba.\n\n");

    return 0;
}


void MensagemDeBoasVindas () {
    printf("\nOla, jovem padawan! Seja bem vindo ao nosso repositorio de algoritmos de ordenacao, aqui você pode testar diferentes metodos,\ntanto iterativa quanto recursivamente, e ainda compreender o funcionamento de cada um deles!\n\n");
}

void Selecao(int numeros, int quantidade, int tipoVet) {

    int opcao = 0;

    printf("\nSelecione a opcao que desejar: \n1 - Quero testar os algoritmos!\n2 - Quero aprender sobre recursao\n3 - Sair\n\n");
    scanf("%d", &opcao); 

    switch (opcao)
    {
    case 1: Algortimos(numeros, quantidade, tipoVet); break;
    case 2: TextoRecursao(); printaSeparacao(); Selecao(numeros, quantidade, tipoVet); break;
    case 3: break;
    }

}

void Algortimos (int numeros, int quantidade, int tipoVet) {

    int vetor[quantidade], aux[quantidade], min = 0, max = quantidade - 1;

    switch (tipoVet)
    {
    case 1:
        for(int g = quantidade, f = 0; f < quantidade; g--, f++){
            vetor[f] = g; //atribui os valores de quantidade ate 1 no vetor de maneira decrescente
        }
        break;

    case 2:
        srand(time(NULL));
  
        for (int o = 0; o < quantidade; o++) {
            vetor[o] = rand() % numeros;
        }
        break;
    
    default:
        break;
    }
  
    int opcao = 0;

    printf("\nQual algoritmo de ordenacao você deseja usar?\n1 - Bubblesort\n2 - InsertionSort\n3 - SelectionSort\n4 - MergeSort\n5 - QuickSort\n6 - HeapSort\n7 - Voltar...\n\n");
    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1: printaSeparacao(); TextoBubblesort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor, quantidade); printf("\n"); bubblesort(vetor, quantidade); printf("\nvetor ordenado: "); PrintaVetor(vetor, quantidade); printaSeparacao(); Algortimos(numeros, quantidade, tipoVet);  break;
    case 2: printaSeparacao(); TextoInsertionSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor, quantidade); printf("\n"); insertionsort(vetor, quantidade); printf("\nvetor ordenado: "); PrintaVetor(vetor, quantidade); printaSeparacao(); Algortimos(numeros, quantidade, tipoVet);  break;
    case 3: printaSeparacao(); TextoSelectionSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor, quantidade); printf("\n"); selectionsort(vetor, quantidade); printf("\nvetor ordenado: "); PrintaVetor(vetor, quantidade); printaSeparacao(); Algortimos(numeros, quantidade, tipoVet);  break;
    case 4: printaSeparacao(); TextoMergeSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor, quantidade); printf("\n"); mergesort(vetor, aux, min, max, quantidade); printf("\nvetor ordenado: "); PrintaVetor(vetor, quantidade); printaSeparacao(); Algortimos(numeros, quantidade, tipoVet);  break;
    case 5: printaSeparacao(); TextoQuickSort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor, quantidade); printf("\n"); quicksort(vetor, min, max, quantidade); printf("\nvetor ordenado: "); PrintaVetor(vetor, quantidade); printaSeparacao(); Algortimos(numeros, quantidade, tipoVet);  break;
    case 6: printaSeparacao(); TextoHeapsort(); printf("\n\nvetor desordenado: "); PrintaVetor(vetor, quantidade); printf("\n"); heap_sort(vetor, quantidade); printf("\nvetor ordenado: "); PrintaVetor(vetor, quantidade); printaSeparacao(); Algortimos(numeros, quantidade, tipoVet); break;
    case 7: printf("\n"); Selecao(numeros, quantidade, tipoVet); break;
    }

}

void printaSeparacao() {
    printf("\n====================================================================================================");
}

void PrintaVetor(int vetor[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void TextoRecursao() {
    printf("\nRecursao e uma tecnica de programacao que envolve a chamada de uma funcao a si mesma. \nEm outras palavras, uma funcao recursiva e aquela que se chama dentro de sua propria definicao.\n\nAo invocar uma funcao recursiva, a mesma e capaz de resolver um problema dividindo-o em subproblemas menores, ate que um ou mais casos-base sejam alcancados, \nmomento em que a recursao para e os resultados obtidos sao combinados para resolver o problema original.\n\nUma funcao recursiva precisa sempre possuir um caso-base, que e uma condicao que indica quando a recursao deve parar. \nCaso contrario, a funcao ira chamar a si mesma infinitamente, o que levara a um estouro de pilha e causara um erro no programa.\n\nA recursao pode ser uma ferramenta poderosa para resolver problemas complexos, especialmente aqueles que possuem uma estrutura recursiva natural, \ncomo algoritmos de busca em arvores, ordenacao de listas encadeadas, entre outros.\n\nNo entanto, o uso excessivo de recursao pode levar a um consumo excessivo de memoria e pode ser menos eficiente do que abordagens iterativas em alguns casos. \n\nPortanto, e importante considerar cuidadosamente o uso de recursao em um programa e verificar se ha uma alternativa mais eficiente.\n\n");
}

void swap(int vetor[], int a, int b) {int aux = vetor[a]; vetor[a] = vetor[b]; vetor[b] = aux;}

void TextoBubblesort() {
    printf("\nO algoritmo Bubblesort e um algoritmo de classificacao (ou ordenacao) simples e comumente usado, \nembora nao seja tao eficiente quanto outros algoritmos mais avancados em termos de tempo de execucao. \n\nEle funciona comparando cada par de elementos adjacentes na lista e trocando-os de posicao se estiverem na ordem errada. \nEsse processo e repetido varias vezes ate que toda a lista esteja ordenada.\n\nO funcionamento do algoritmo pode ser descrito em cinco passos simples:\n\n1 - Comecando com o primeiro elemento (indice 0), compare-o com o proximo elemento (indice 1) na lista.\n2 - Se o primeiro elemento for maior que o proximo elemento, troque-os de posicao.\n3 - Continue percorrendo a lista, comparando elementos adjacentes e trocando-os de posicao se estiverem fora de ordem.\n4 - Repita esse processo para cada par de elementos adjacentes na lista, percorrendo a lista varias vezes ate que nenhum elemento seja trocado de posicao.\n5 - Quando nenhum elemento for mais trocado de posicao, a lista estara ordenada");

}

void bubblesort(int vetor[], int n) {

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++) {
            if ( vetor[j] > vetor[j+1] ) { swap(vetor, j, j+1); }
        }
        printf("Etapa %d - ", i+1); PrintaVetor(vetor, n);
    }

}

void TextoInsertionSort() {
    printf("\nO insertionsort e um algoritmo de ordenacao simples e eficiente, especialmente para listas pequenas ou para listas que ja estao quase ordenadas. \n\nO algoritmo funciona de maneira semelhante ao processo de classificacao de cartas em uma mao de baralho.\n\nO funcionamento do algoritmo pode ser descrito em quatro passos simples:\n\n1 - Comecando com o segundo elemento da lista (indice 1), compare-o com o elemento anterior (indice 0) na lista.\n2 - Se o elemento anterior for maior que o atual, \nmova o elemento anterior uma posicao à frente e continue a comparar com o proximo elemento anterior na lista ate encontrar o local correto para inserir o elemento atual.\n3 - Repita esse processo para cada elemento subsequente na lista ate que todos os elementos estejam ordenados.\n4 - Quando todos os elementos estiverem ordenados, a lista estara classificada.\n");

}

void insertionsort(int vetor[], int n) {

    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && vetor[j] < vetor[j-1]) {
            swap(vetor, j, j-1); j--;
        }
        printf("Etapa %d - ", i); PrintaVetor(vetor, n);
    }

}

void TextoSelectionSort() {
    printf("\nO selectionsort e um algoritmo simples de ordenacao que funciona encontrando o menor elemento da lista e colocando-o na primeira posicao, \ndepois encontrando o proximo menor elemento e colocando-o na segunda posicao e assim por diante. \n\nO algoritmo funciona selecionando o menor elemento da lista em cada iteracao e trocando-o com o elemento na primeira posicao da lista nao classificada.\n\nO funcionamento do algoritmo pode ser descrito em três passos simples:\n\n1 - Defina o limite da lista classificada no inicio da lista como 0.\n2 - Encontre o menor elemento na lista nao classificada (isto e, os elementos apos o limite da lista classificada).\n3 - Troque o menor elemento encontrado com o primeiro elemento da lista nao classificada e atualize o limite da lista classificada para incluir o elemento trocado.\n4 - Repita esses passos para cada elemento nao classificado na lista ate que toda a lista esteja ordenada.\n");

}

void selectionsort (int vetor[], int n) {

    for (int i = 0; i < n-1; i++) {
        int minimo = i;
        for (int j = i+1; j < n; j++) {
            if (vetor[j] < vetor[minimo]) { minimo = j; }
        }
        swap(vetor, minimo, i); printf("Etapa %d - ", i+1); PrintaVetor(vetor, n);
    }

}

void TextoMergeSort() {
    printf("\nO merge sort e um algoritmo de ordenacao muito eficiente e rapido, que usa o principio de divisao e conquista para dividir a lista em duas partes menores, \nordena-las separadamente e, em seguida, combina-las em uma única lista ordenada. \n\nO algoritmo e conhecido por ter uma complexidade de tempo O(n log n), o que o torna uma escolha popular para a ordenacao de grandes conjuntos de dados.\n\nO funcionamento do algoritmo pode ser descrito em três passos principais:\n\n1 - Divida a lista em duas metades, ate que cada sublista contenha apenas um elemento ou esteja vazia.\n2 - Recursivamente ordene cada sublista dividida.\n3 - Combine as sub-listas ordenadas em uma única lista ordenada, usando o algoritmo de fusao (merge).\n");

}

void merge(int vetor[], int aux[], int imin, int imid, int imax, int n){
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

    PrintaVetor(vetor, n);
}

void mergesort(int vetor[], int aux[], int imin, int imax, int n) {
    if (imax <= imin) return;

    int imid = imin + ((imax - imin) / 2);
    mergesort(vetor, aux, imin, imid, n);
    mergesort(vetor, aux, imid+1, imax, n);
    merge(vetor, aux, imin, imid, imax, n);
    
}

void TextoQuickSort() {
    printf("\nO QuickSort e um algoritmo de ordenacao eficiente que utiliza a estrategia de dividir e conquistar para ordenar uma lista de elementos. \n\nEle e muito utilizado em diversas aplicacões devido à sua velocidade e eficiência, sendo capaz de ordenar grandes quantidades de dados em pouco tempo.\n\nO funcionamento do QuickSort pode ser resumido em três passos:\n\n1 - Escolha um elemento como o pivô da lista. Geralmente e escolhido o primeiro elemento da lista, mas tambem e possivel escolher outros elementos, \ncomo o elemento central da lista ou um elemento escolhido aleatoriamente.\n2 - Reorganize a lista de modo que todos os elementos menores que o pivô estejam à sua esquerda, e todos os elementos maiores estejam à sua direita.\n3 - Recursivamente aplique o QuickSort para as sublistas à esquerda e à direita do pivô.\n");

}

int partition(int vetor[], int imin, int imax, int n) {
    
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
        PrintaVetor(vetor, n);
        return j;
}

void quicksort(int vetor[], int imin, int imax, int n) {
    if (imax <= imin) return; 

    int i = partition(vetor, imin, imax, n);
    quicksort(vetor, imin, i-1, n);
    quicksort(vetor, i+1, imax, n);
}

void TextoHeapsort() {
    printf("\nO HeapSort e um algoritmo de ordenacao que utiliza uma estrutura de dados chamada Heap para ordenar uma lista de elementos. \n\nA Heap e uma arvore binaria completa que satisfaz a propriedade de Heap, que pode ser Max-Heap ou Min-Heap. Na Max-Heap, \ncada no pai e maior ou igual a seus filhos, enquanto na Min-Heap, cada no pai e menor ou igual a seus filhos.\n\nO funcionamento do HeapSort pode ser resumido em dois passos:\n\n1 - Construir uma Max-Heap com a lista de elementos.\n2 - Extrair o elemento maximo da Heap e coloca-lo no final da lista. Em seguida, reconstruir a Heap e repetir o processo ate que todos os elementos estejam ordenados.\n");

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
    int j = 1;
    for (int i = n / 2 - 1; i >= 0; i--)
        heap(vetor, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;
        printf("Etapa %d - ", j++); PrintaVetor(vetor, n);
        heap(vetor, i, 0);
    }
}


