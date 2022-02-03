# estrutura-de-dados##


### 20220126 - Lista Encadeada - Notas de Aula

- elementos consecutivos na lista, não necessariamente estarão no endereço consecutivo na memória;
- nodo, elemento de uma lista, este possui o valor de variável + o prox (apontador para endereço de memória).
  
  ```
  struct elemento {
      int conteudo;
      int prox;
  }
  ```