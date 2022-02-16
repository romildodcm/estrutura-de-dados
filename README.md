# estrutura-de-dados

### Uso de ponteiros

`*e = p->dado;`

No lado esquerdo da igualdade temos a maneira de usar ponteiros para variáveis, à direita está a seta `->` que é o jeito de usar ponteiros quando se trata de tipo/struct.


### 20220126 - Lista Encadeada - Notas de Aula

- elementos consecutivos na lista, não necessariamente estarão no endereço consecutivo na memória;
- nodo, elemento de uma lista, este possui o valor de variável + o prox (apontador para endereço de memória).
  
  ```
  struct elemento {
      int conteudo;
      int prox;
  }
  ```


### 20220209 - Pilha

```
(p) -> (4,p) -> (5,p)  -> (9,p) -> (3,p)
```

**Operações básicas sobre pilhas:**
- Cria plilha;
- Empilha;
- Desempilha;

**Operações opcionais**
- Conta pilha (contrar o número de elementos);
- Imprime pilha (exibir elementos);
- Verificar se pilha é vazia;

**Comportamentos**

LastIn-FirstOut (LIFO) <- Esse é o comportamento da pilha

FirstIn-FirstOut (FIFO)

**Declarando pilha dinâmica**
```
struct elemento {
    int dado;
    struct elemento *prox;
};
typedef struct elemento *Pilha;

// ou

typedef struct elemento
{
    int dado;
    struct elemento *prox;
} *Pilha;
```

**Função para criar pilha**

```
Pilha criaPilha()
{
    return NULL;
}
```

**Função empilha**

```
// supondo a pilha iniciada e vazia
```

#### Tarefa Pilhas

**Faça um programa que implemente uma pilha com alocação dinâmica, para armazenar números inteiros.**

O usuário deve poder incluir quantos elementos desejar na pilha.

As opções permitidas para o usuário são:

1 - Empilhar um elemento (inserir na pilha)
2 - Desempilhar um elemento (retirar o elemento do topo da pilha)
3 - Imprimir o conteúdo da pilha.

Deve ser postado o código fonte em C, compilável e funcionando, sem o uso de bibliotecas específicas de Windows.