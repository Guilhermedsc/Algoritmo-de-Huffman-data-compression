Esse algoritmo foi desenvolvido como forma de avaliação para a cadeira de Estruturas de Dados. O algoritmo é capaz de compactar qualquer arquivo e descompactar qualquer arquivo anteriormente compactado pelo mesmo. [INSTRUÇÕES DE USO DO ALGORITMO](./INSTRUÇÕES.txt)

# Algoritmo de Huffman

O algoritmo de Huffman é um método de compressão de dados sem perda que é utilizado para reduzir o tamanho dos dados ao codificar os caracteres de acordo com suas frequências de ocorrência. Segue abaixo um resumo do funcionamento do algoritmo de Huffman:

1. **Contagem de Frequência**:
   - Analise o texto original e conte a frequência de cada caractere.

2. **Criação de Nós**:
   - Crie um nó para cada caractere, onde cada nó contém o caractere e sua frequência.

3. **Construção da Árvore de Huffman**:
   - Coloque todos os nós em uma fila de prioridade (geralmente um min-heap), onde os nós com menor frequência têm maior prioridade.
   - Enquanto a fila de prioridade tiver mais de um nó:
     - Remova os dois nós com as menores frequências.
     - Crie um novo nó pai com a soma das frequências dos dois nós removidos. Este novo nó pai não contém nenhum caractere.
     - Adicione o novo nó pai de volta à fila de prioridade.
   - O único nó restante na fila de prioridade será a raiz da Árvore de Huffman.

4. **Geração dos Códigos de Huffman**:
   - Percorra a árvore de Huffman da raiz até as folhas. A cada ramificação à esquerda, adicione '0' ao código e a cada ramificação à direita, adicione '1'.
   - A sequência de '0's e '1's obtida ao chegar a uma folha é o código de Huffman do caractere daquela folha.

5. **Codificação**:
   - Substitua cada caractere do texto original pelo seu código de Huffman correspondente.

6. **Decodificação**:
   - Para decodificar, utilize a árvore de Huffman. Percorra a árvore a partir da raiz seguindo os '0's e '1's até alcançar uma folha, que corresponde ao caractere decodificado.
