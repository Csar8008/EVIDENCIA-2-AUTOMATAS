//Se valida paso a paso usando una posicion (pos) que recorre la cadena

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int validar_cadena();

int validar_inicio_matricula(char *cadena, char *matricula, int *pos);
int contar_w(char *cadena, char *w, int *pos);
int validar_segunda_matricula(char *cadena, char *matricula, int *pos);
int validar_wI(char *cadena, char *wI, int n, int *pos);
int validar_nombre(char *cadena, char *nombre, int *pos);

void imprimir_datos();
int leer_opcion();

int main()
{
	int opc = 1;
	while (opc != 2)
	{
		if (validar_cadena() == 0)
			printf("\nLA CADENA INGRESADA ES INVALIDA.\n");

		printf("\nDesea ingresar otra cadena?\n1. Si\n2. No\n-> ");
		opc = leer_opcion();
		system("cls");
	}
	return 0;
}

// Retorna 0 si es invalida. Retorna 1 si es valida
int validar_cadena()
{
	char cadena[200];
	
	char matricula[] = "2101295";
	char w[] = "gh";
	char wI[] = "hg";
	char nombre[] = "elva";
	
	int pos = 0;
	int n;
	
	imprimir_datos();

	// Solicita cadena
	printf("Ingrese una cadena para verificar (case-sensitive): ");
	gets(cadena);

	// verificar que la cadena no esté vacía
	if (strlen(cadena) == 0)
	{
		printf("\nCADENA VACIA");
		return 0;
	}
	
	//Valida que empiece con matricula
	if (!validar_inicio_matricula(cadena, matricula, &pos)) 
	{
		printf("\nLa cadena no incia con la matricula");
		return 0;
	}
	
	//Contar cuantas veces aparece w seguido
	n = contar_w(cadena, w, &pos);
	if (n < 1)
	{
		printf("\nLa cadena no contiene al menos una repeticion de w");
		return 0;
	}
	
	//Que despues de w siga matricula
	if (!validar_segunda_matricula(cadena, matricula, &pos))
	{
		printf("\nFalta la segunda aparicion de la matricula");
		return 0;
	}
	
	//Que aparesca w invertida 2n veces
	if (!validar_wI(cadena, wI, n, &pos))
	{
		printf("\nLa cantidad de w inversa no corresponde a 2n");
		return 0;
	}
	
	//Aparezca 2 veces j
	if (!validar_nombre(cadena, nombre, &pos))
	{
		printf("\nEl nombre no aparece exactamente dos veces");
		return 0;
	}
	
	//Que ya no haya mas caracteres
	if (cadena[pos] != '\0')
	{
		printf("\nLa cadena tiene caracteres extras");
		return 0;
	}

	printf("\nLA CADENA INGRESADA ES VALIDA.\n");
	return 1;
}

// validar numeros enteros binarios
int leer_opcion()
{
	int valor;
	int valido = 0;

	do
	{
		if (scanf("%d", &valor) == 1 && (valor == 2 || valor == 1))
			valido = 1;
		else
		{
			printf("\nIngrese una opcion valida\n-> ");
			valido = 0;
		}
		while (getchar() != '\n')
			;
	} while (!valido);

	return valor;
}

int validar_inicio_matricula(char *cadena, char *matricula, int *pos) 
{
    int i;

    for(i = 0; i < strlen(matricula); i++) 
	{
        if(cadena[*pos] != matricula[i])
            return 0;
        (*pos)++;
    }

    return 1;
}

//Cuenta cuantas veces aparece w consecutivamente 
//Se detiene cuando deja de coincidir 
int contar_w(char *cadena, char *w, int *pos) 
{
    int n = 0;
    int i;

    while(1) 
	{
        for(i = 0; i < strlen(w); i++) 
		{
			//En cuanto deja de coincidir w, la funcion regresa n
            if(cadena[*pos + i] != w[i])
                return n;
        }
        (*pos) += strlen(w);
        n++;
    }
}

int validar_segunda_matricula(char *cadena, char *matricula, int *pos) 
{
    int i;

    for(i = 0; i < strlen(matricula); i++) 
	{
        if(cadena[*pos] != matricula[i])
            return 0;
        (*pos)++;
    }

    return 1;
}

//Valida que wI aparezca exactamente 2n veces
int validar_wI(char *cadena, char *wI, int n, int *pos) 
{
    int i, j;

    for(i = 0; i < 2*n; i++) {
        for(j = 0; j < strlen(wI); j++) 
		{
            if(cadena[*pos] != wI[j])
                return 0;
            (*pos)++;
        }
    }

    return 1;
}

//funcion para validar que el nombre aparesca 2 veces en la cadena
int validar_nombre(char *cadena, char *nombre, int *pos) 
{
    int i, j;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < strlen(nombre); j++) 
		{
            if(cadena[*pos] != nombre[j])
                return 0;
            (*pos)++;
        }
    }

    return 1;
}

//imprime los datos
void imprimir_datos()
{
    printf("\n--- INFORMACION DEL LENGUAJE ---\n");
    printf("Estructura: {i (w)^n i (wI)^(2n) j^2}\n\n");

    printf("Donde:\n");
    printf("i  = matricula (2101295)\n");
    printf("w  = iniciales de apellidos (gh)\n");
    printf("wI = iniciales invertidas (hg)\n");
    printf("j  = nombre (elva)\n\n");

    printf("Condiciones:\n");
    printf("- La cadena debe iniciar con la matricula\n");
    printf("- Debe contener al menos una repeticion de w\n");
    printf("- Debe repetirse la matricula nuevamente\n");
    printf("- Debe contener wI exactamente 2n veces\n");
    printf("- El nombre debe aparecer 2 veces seguidas\n\n");

}
