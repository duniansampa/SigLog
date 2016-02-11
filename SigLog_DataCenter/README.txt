 >>>>> Tutorial de SigLog_DataCenter  <<<<<


Um ótimo tutorial de como desenvolver um software CGI em C++:
	http://www.tutorialspoint.com/cplusplus/cpp_web_programming.htm

Bibliotecca desenvolvimento para desenvolvimento de software CGI em C++:
	http://www.gnu.org/software/cgicc/

Para baixar a biblioteca CGI, use o link:

	http://ftp.gnu.org/gnu/cgicc/

Para o desenvolvimento deste software, eu utilizei a versão 3.2.16 da biblioteca
cgicc.

 >>> Instalação da biblioteca GNU cgicc <<<<

Use os seguintes comandos para efetuar a instalação:

	$tar xzf cgicc-3.2.16.tar.gz 
	$cd cgicc-3.2.16/ 
	$./configure --prefix=/usr 
	$make
	$make install

 >>> Compilação <<<

Não esqueça colocar flag de compilação da bliblioteca cgicc: -lcgicc.




 
