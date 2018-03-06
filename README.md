PROTOTIPO DE CÓDIGOS EM GTK DE FORMA SIMPLES E PRATICA, TEM ALGUNS EXEMPLOS BEM SIMPLES.

MAS PARA COMEÇAR PRIMEIRO TEMOS QUE INSTALAR O gcc E O g++. DEPOIS DISSO TEMPOS QUE INSTALAR AS BIBLIOTECAS DE gtk+3, QUE E QUAL ESSES EXEMPLOS SÃO FEITOS, PARA ISSO NO TERMINAL DIGITE O COMANDO:

$ sudo apt-get install libgtk-3*

com isso ira instalar todas as bibliotecas necessárias como cairo e glib entre outras.

Esses exemplos tem um makefile o qual compilar de forma mais fácil (basta ter o make em seu computador) é só digitar make na pasta em que estar o arquivo no teminal e pronto. Porem caso queira compilar somente um programa usa-se o comando:

$ g++ <nome_do_arquivo>.c -o <nome_do_executavel> `pkg-config --cflags --libs gtk+-3.0`

obs.: cuidado para não usar aspas simples, o comando tem que ser feito com essa aspas "torta".

E por fim para executar o executável usa o comando no terminal:

$ ./<nome_do_executavel>
