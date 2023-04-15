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

    printf("Selecione a forma do vetor:\na - vetor fixo digitado pelo usuário\nb - vetor aleatório gerado automaticamente\n"); scanf(" %c", &vetor);

    if(vetor == 'a'){ //se o vetor for fixo, recebe apenas a quantidade de números do vetor 
        tipo_vetor = 1;
        printf("Insira a quantidade de numeros do vetor: "); scanf("%d", &quantidade); 
    }
    if(vetor == 'b') { //se o vetor for aleatório recebe a quantidade de númeors e maior valor possível do vetor
        tipo_vetor = 2;
        printf("Insira a quantidade de numeros do vetor: "); scanf("%d", &quantidade); 
        printf("Insira o maior numero possivel do vetor: "); scanf("%d", &maior_num);
    }

    Selecao(maior_num, quantidade, tipo_vetor);

    printf("\n\nObrigado por visitar nosso projeto para o HackoonSpace, entidade de cultura Hacker na Universidade Federal de São Carlos, campus Sorocaba.\n\n");

    return 0;
}


void MensagemDeBoasVindas () {
    printf("\nOlá, jovem padawan! Seja bem vindo ao nosso repositório de algoritmos de ordenação, aqui você pode testar diferentes métodos,\ntanto iterativa quanto recursivamente, e ainda compreender o funcionamento de cada um deles!\n\n");
}

void Selecao(int numeros, int quantidade, int tipoVet) {

    int opcao = 0;

    printf("\nSelecione a opção que desejar: \n1 - Quero testar os algoritmos!\n2 - Quero aprender sobre recursão\n3 - Sair\n\n");
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
            vetor[f] = g; //atribui os valores de quantidade até 1 no vetor de maneira decrescente
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

    printf("\nQual algoritmo de ordenação você deseja usar?\n1 - Bubblesort\n2 - InsertionSort\n3 - SelectionSort\n4 - MergeSort\n5 - QuickSort\n6 - HeapSort\n7 - Voltar...\n\n");
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
    printf("\nRecursão é uma técnica de programação que envolve a chamada de uma função a si mesma. \nEm outras palavras, uma função recursiva é aquela que se chama dentro de sua própria definição.\n\nAo invocar uma função recursiva, a mesma é capaz de resolver um problema dividindo-o em subproblemas menores, até que um ou mais casos-base sejam alcançados, \nmomento em que a recursão para e os resultados obtidos são combinados para resolver o problema original.\n\nUma função recursiva precisa sempre possuir um caso-base, que é uma condição que indica quando a recursão deve parar. \nCaso contrário, a função irá chamar a si mesma infinitamente, o que levará a um estouro de pilha e causará um erro no programa.\n\nA recursão pode ser uma ferramenta poderosa para resolver problemas complexos, especialmente aqueles que possuem uma estrutura recursiva natural, \ncomo algoritmos de busca em árvores, ordenação de listas encadeadas, entre outros.\n\nNo entanto, o uso excessivo de recursão pode levar a um consumo excessivo de memória e pode ser menos eficiente do que abordagens iterativas em alguns casos. \n\nPortanto, é importante considerar cuidadosamente o uso de recursão em um programa e verificar se há uma alternativa mais eficiente.\n\n");
}

void swap(int vetor[], int a, int b) {int aux = vetor[a]; vetor[a] = vetor[b]; vetor[b] = aux;}

void TextoBubblesort() {
    printf("\nO algoritmo Bubblesort é um algoritmo de classificação (ou ordenação) simples e comumente usado, \nembora não seja tão eficiente quanto outros algoritmos mais avançados em termos de tempo de execução. \n\nEle funciona comparando cada par de elementos adjacentes na lista e trocando-os de posição se estiverem na ordem errada. \nEsse processo é repetido várias vezes até que toda a lista esteja ordenada.\n\nO funcionamento do algoritmo pode ser descrito em cinco passos simples:\n\n1 - Começando com o primeiro elemento (índice 0), compare-o com o próximo elemento (índice 1) na lista.\n2 - Se o primeiro elemento for maior que o próximo elemento, troque-os de posição.\n3 - Continue percorrendo a lista, comparando elementos adjacentes e trocando-os de posição se estiverem fora de ordem.\n4 - Repita esse processo para cada par de elementos adjacentes na lista, percorrendo a lista várias vezes até que nenhum elemento seja trocado de posição.\n5 - Quando nenhum elemento for mais trocado de posição, a lista estará ordenada.n");

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
    printf("\nO insertionsort é um algoritmo de ordenação simples e eficiente, especialmente para listas pequenas ou para listas que já estão quase ordenadas. \n\nO algoritmo funciona de maneira semelhante ao processo de classificação de cartas em uma mão de baralho.\n\nO funcionamento do algoritmo pode ser descrito em quatro passos simples:\n\n1 - Começando com o segundo elemento da lista (índice 1), compare-o com o elemento anterior (índice 0) na lista.\n2 - Se o elemento anterior for maior que o atual, \nmova o elemento anterior uma posição à frente e continue a comparar com o próximo elemento anterior na lista até encontrar o local correto para inserir o elemento atual.\n3 - Repita esse processo para cada elemento subsequente na lista até que todos os elementos estejam ordenados.\n4 - Quando todos os elementos estiverem ordenados, a lista estará classificada.\n");

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
    printf("\nO selectionsort é um algoritmo simples de ordenação que funciona encontrando o menor elemento da lista e colocando-o na primeira posição, \ndepois encontrando o próximo menor elemento e colocando-o na segunda posição e assim por diante. \n\nO algoritmo funciona selecionando o menor elemento da lista em cada iteração e trocando-o com o elemento na primeira posição da lista não classificada.\n\nO funcionamento do algoritmo pode ser descrito em três passos simples:\n\n1 - Defina o limite da lista classificada no início da lista como 0.\n2 - Encontre o menor elemento na lista não classificada (isto é, os elementos após o limite da lista classificada).\n3 - Troque o menor elemento encontrado com o primeiro elemento da lista não classificada e atualize o limite da lista classificada para incluir o elemento trocado.\n4 - Repita esses passos para cada elemento não classificado na lista até que toda a lista esteja ordenada.\n");

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
    printf("\nO merge sort é um algoritmo de ordenação muito eficiente e rápido, que usa o princípio de divisão e conquista para dividir a lista em duas partes menores, \nordená-las separadamente e, em seguida, combiná-las em uma única lista ordenada. \n\nO algoritmo é conhecido por ter uma complexidade de tempo O(n log n), o que o torna uma escolha popular para a ordenação de grandes conjuntos de dados.\n\nO funcionamento do algoritmo pode ser descrito em três passos principais:\n\n1 - Divida a lista em duas metades, até que cada sublista contenha apenas um elemento ou esteja vazia.\n2 - Recursivamente ordene cada sublista dividida.\n3 - Combine as sub-listas ordenadas em uma única lista ordenada, usando o algoritmo de fusão (merge).\n");

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
    printf("\nO QuickSort é um algoritmo de ordenação eficiente que utiliza a estratégia de dividir e conquistar para ordenar uma lista de elementos. \n\nEle é muito utilizado em diversas aplicações devido à sua velocidade e eficiência, sendo capaz de ordenar grandes quantidades de dados em pouco tempo.\n\nO funcionamento do QuickSort pode ser resumido em três passos:\n\n1 - Escolha um elemento como o pivô da lista. Geralmente é escolhido o primeiro elemento da lista, mas também é possível escolher outros elementos, \ncomo o elemento central da lista ou um elemento escolhido aleatoriamente.\n2 - Reorganize a lista de modo que todos os elementos menores que o pivô estejam à sua esquerda, e todos os elementos maiores estejam à sua direita.\n3 - Recursivamente aplique o QuickSort para as sublistas à esquerda e à direita do pivô.\n");

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
    printf("\nO HeapSort é um algoritmo de ordenação que utiliza uma estrutura de dados chamada Heap para ordenar uma lista de elementos. \n\nA Heap é uma árvore binária completa que satisfaz a propriedade de Heap, que pode ser Max-Heap ou Min-Heap. Na Max-Heap, \ncada nó pai é maior ou igual a seus filhos, enquanto na Min-Heap, cada nó pai é menor ou igual a seus filhos.\n\nO funcionamento do HeapSort pode ser resumido em dois passos:\n\n1 - Construir uma Max-Heap com a lista de elementos.\n2 - Extrair o elemento máximo da Heap e colocá-lo no final da lista. Em seguida, reconstruir a Heap e repetir o processo até que todos os elementos estejam ordenados.\n");

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


