#include <stdio.h>
#include <windows.h>

main()
{
	printf("Hello Sailor\n");
	printf("%d",MessageBox( NULL, "Mensagem interessante.\n", "titulo foda", MB_OK|MB_DEFAULT_DESKTOP_ONLY ));
	
	//MessageBox( NULL, "Mensagem foda.\n", "titulo foda", MB_OK);
	//MessageBox( NULL, "Mensagem foda2.\n", "titulo foda", MB_ICONMASK );
	printf("\n\n%d",IDHELP);
	if(MessageBox( NULL, "Mensagem foda.\n", "titulo foda", MB_HELP ) == WM_HELP){
		printf("aaaaa");
	}
	
}



