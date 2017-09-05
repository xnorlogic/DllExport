#include <stdio.h>

//#define WINDOWS_MINGW_NET 

#ifdef WINDOWS_MINGW_NET
//declaration for exporting to windows use... with export decoration
#define VAR1 0x03
__declspec(dllexport) extern void MyPrintF();
#else
//Regular declaration
#define VAR1 0x01
void MyPrintF();
#endif

int main(){

	printf("ifdef Test! %x\n",VAR1);
	switch (VAR1){
		case 0x03: printf("ready for windows export %x\n",VAR1); break;
		case 0x01: printf("NO windows export %x\n",VAR1); break;
		default: printf("\n Sorry, something failed \n");
	}
	
	MyPrintF();
	
	return 0;
}

void MyPrintF(){
	printf("\n GOOD PRINT! \n");
}

//g++ -o EXEt ifdeftest.c
