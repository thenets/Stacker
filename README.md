Stacker 1.0
===================


A stack automata compiler.

----------

### Pre-requisitos
Necessário instalar os seguintes pacotes:

	# sudo apt-get install g++

----------	
### Compilar
Para compilar o projeto, basta navegar até a pasta do stacker e executar o compile.sh:

	$ cd ~/stacker
	$ chmod 777 ./compile.sh
	$ ./compile.sh

----------	
### Estrutura
q1 (entrada, topo_da_pilha, alteracao, estado de destino)

	   Se a entrada 0; topo de pilha for 1; adiciona 2 na pilha; vai para o estado q2
        q1 (0, 1, 2, q2);
        
    Se a entrada 1; topo de pilha for 2; remove item da pilha; se mantém no estado q2
        q2 (1, 2, -, q2);
        
    Se a entrada 2; topo de pilha 1; mantém o item do topo da pilha; vai para o estado q3
        q2 (2, 1, =, q3);
        
    Se a entrada 1; pilha vazia; adiciona 1 na pilha; vai para estado q4
        q3 (1, *, 1, q4);
        
    Se chegou no final; topo de pilha 1; matém o item do topo da pilha; vai para estado de erro
        q3 (*, 1, =, error);
        
    Se a entrada 3; pilha vazia; matém o item do topo da pilha; vai para estado de erro
        q3 (3, *, =, error);
        
    Se chegou ao final
        q3 (3, 2, =, end);


### Símbolos
q1 (entrada, topo_da_pilha, alteracao, estado de destino)

	*  vazio
	-  remove
	=  mantém


### Exemplo
Automato que reconhece: a^n b^m c^n
Ex.: aaaabbcccc

	q1 
    (a, *, a, q1)
    (a, a, a, q1)
    (b, *, =, q2)
    (b, a, -, q2);
    
    q2
    (b, *, =, q2)
    (b, a, =, q2)
    (c, *, =, q3)
    (c, a, =, q3);
    
    q3
    (c, a, -, q3)
    (*, *, =, end);

----------
### And that's it! 
Thank you for use Stacker.
If you want, contact me at http://TheNets.org/ .