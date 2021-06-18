#include <stdio_ext.h>
#include "terminalFunctions.h"


void CleanBuffer()
{
	#ifdef _WIN32
    	fflush(stdin);
	#else
    	__fpurge(stdin);
	#endif
}

void CleanConsole()
{
	/* El símbolo _WIN32 está definido solamente en Windows
	 * y con la construcción utilizada el compilador verá,
	 * por ejemplo, la instrucción #include<windows.h> solo si
	 * es Windows. En una compilación para linux, es como si
	 * esa línea del fuente no existiera.*/

	#ifdef _WIN32
    	system("cls");
	#else
    	system("clear");
	#endif
}
