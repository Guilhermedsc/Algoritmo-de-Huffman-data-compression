all:
	g++ main.cpp ftab.cpp prefix.cpp eqtab.cpp bqueue.cpp -o trabalho.exe

comp:
	.\trabalho.exe texto.txt COMPACTAR compactado.huff

descomp:
	.\trabalho.exe compactado.huff DESCOMPACTAR descompactado.txt
