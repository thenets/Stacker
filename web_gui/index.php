<?php
echo exec("./stacker > out.txt 2>&1");


?><html ng-app="app">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Staker</title>
    
    
    <!-- CodeMirror -->
    <link rel="stylesheet" href="lib/codemirror.css">
    <link rel="stylesheet" href="addon/fold/foldgutter.css">
    <link rel="stylesheet" href="addon/dialog/dialog.css">
    <link rel="stylesheet" href="theme/monokai.css">
    <script src="lib/codemirror.js"></script>
    <script src="addon/search/searchcursor.js"></script>
    <script src="addon/search/search.js"></script>
    <script src="addon/dialog/dialog.js"></script>
    <script src="addon/edit/matchbrackets.js"></script>
    <script src="addon/edit/closebrackets.js"></script>
    <script src="addon/comment/comment.js"></script>
    <script src="addon/wrap/hardwrap.js"></script>
    <script src="addon/fold/foldcode.js"></script>
    <script src="addon/fold/brace-fold.js"></script>
    <script src="mode/javascript/javascript.js"></script>
    <script src="keymap/sublime.js"></script>
    <!-- /CodeMirror -->
    
    <style type="text/css">
      #output {
          background: rgb(39, 40, 34);
          margin-top: 10px;
          padding: 12px 18px;
          height: 452px;
          color: rgb(166, 226, 46);
          width:100%;
          overflow-y: auto;
          font-family: "Consolas";
      }
    </style>
    
  </head>
  <body ng-controller="mainController">
      <div ng-view></div>
      
      
      <div class="container" style="margin: 40px auto;">
        <div class="md-preview" data-provider="markdown-preview" style="width: 70%; resize: none;">
            
<hr>

<h3>Pre-requisitos</h3>

<p>Necessário instalar os seguintes pacotes:</p>

<pre><code># sudo apt-get install g++</code></pre>

<hr>

<h3>Compilar</h3>

<p>Para compilar o projeto, basta navegar até a pasta do stacker e executar o compile.sh:</p>

<pre><code>$ cd ~/stacker
$ chmod 777 ./compile.sh
$ ./compile.sh</code></pre>

<hr>

<h3>Estrutura</h3>

<p>q1 (entrada, topo<em>da</em>pilha, alteracao, estado de destino)</p>

<pre><code>Se a entrada 0; topo de pilha for 1; adiciona 2 na pilha; vai para o estado q2
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
    q3 (3, 2, =, end);</code></pre>

<hr>

<h3>Símbolos</h3>

<p>q1 (entrada, topo<em>da</em>pilha, alteracao, estado de destino)</p>

<pre><code>*  vazio
-  remove
=  mantém</code></pre>

<hr>

<h3>Exemplo</h3>

<p>Automato que reconhece: a^n b^m c^n
Ex.: aaaabbcccc</p>

<pre><code>q1 
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
(*, *, =, end);</code></pre>

<hr>

<h3>And that's it!</h3>

<p>Thank you for use Stacker.
If you want, contact me at http://TheNets.org/ .</p></div><br><br>
      </div>
      
      
      <!-- Angular Libs and App -->
      <script src="//ajax.googleapis.com/ajax/libs/angularjs/1.3.15/angular.min.js"></script>
      <script src="//ajax.googleapis.com/ajax/libs/angularjs/1.3.15/angular-route.min.js"></script>
      
      <script src="app.js"></script>  
        
      
      <!-- Import all libs and modules -->
      <script data-main="//cdn.thenets.org/jdesign/js/loader_remote" src="//cdn.thenets.org/jdesign/js/codeux/require.js"></script>
      
      <!-- Edit code together -->
      <script src="https://togetherjs.com/togetherjs-min.js"></script>
  </body>
</html>