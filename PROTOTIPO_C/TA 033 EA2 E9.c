//2101295ghgh2101295hghghghgelvaelva

#include <stdio.h>
#include <string.h>

void mostrar_datos();
int leer_cadena();
int validar_cadena(char *cadena);
int validar_i(char *cadena, char *i, int *index);
int validar_w(char *cadena, char *w,int *index, int *n);
int validar_wi(char *cadena, char *wi,int *index, int *n);
int validar_j(char *cadena, char *j, int *index);
int leer_opcion();

int main (){
	int opc = 1;
	while(opc == 1){
		system("cls");
		mostrar_datos();
		if(leer_cadena())
			printf("\nLA CADENA ES VALIDA PARA ESTA GRAMATICA\n");
		else
			printf("\nLA NO CADENA ES VALIDA PARA ESTA GRAMATICA\n");
		printf("\nDesea ingresar otra cadena?\n1-SI\n2-NO\n-> ");
		opc = leer_opcion();
	}
	return 0;
}

int leer_cadena(){
	char cadena[100];
	printf("\nINGRESE UNA CADENA\n");
	fgets(cadena, sizeof(cadena), stdin);
	cadena[strcspn(cadena, "\n")] = '\0';
	if (cadena[0] == '\0'){
		return 0;	
	}
	if(validar_cadena(cadena)){
		return 1;
	}
	else return 0;
}

int validar_cadena(char *cadena){
	char w[] = "gh";
	char wi[] = "hg";
	char j[] =  "elva";
	char i[] = "2101295";
	int n = 0;
	int index = 0;
	if(!validar_i(cadena, i, &index)){
		printf("\nCadena no valida, la cadena i no se encuentra al inicio\n");
		return 0;
	}
	if(!validar_w(cadena, w, &index, &n)){
		printf("\nCadena no valida, la cadena w debe aparecer al menos una vez\n");
		return 0;
	}
	if(!validar_i(cadena, i, &index)){
		printf("\nCadena no valida, la cadena i debe de aparecer despues de las n repeticiones de w\n");
		return 0;
	}
	if(!validar_wi(cadena, wi, &index, &n)){
		printf("\nCadena no valida, la cadena w debe aparecer el doble de veces de w\n");
		return 0;
	}
	if(!validar_j(cadena, j, &index)){
		printf("\nCadena no valida, la cadena j debe aparecer 2 veces\n");
		return 0;
	}
	if (cadena[index] != '\0') return 0;
	return 1;
}

int validar_i(char *cadena, char *i, int *index){
	int j;
	for (j = 0; j < strlen(i); j++){
		if(cadena[(*index)] == i[j]){
			(*index)++;
		}
		else
			return 0;
	}
	return 1;
}

int validar_w(char *cadena, char *w,int *index, int *n){
	while (cadena[(*index)] == w[0] && cadena[(*index) + 1] == w[1]){
		(*n)++;
		(*index) += 2;
	}
	if((*n) == 0)
		return 0;
	return 1;
}

int validar_wi(char *cadena, char *wi,int *index, int *n){
	int ni = 0;
	while (cadena[*index] == wi[0] && cadena[(*index) + 1] == wi[1]){
		ni++;
		(*index) += 2;
	}
	if(ni != 2 * (*n))
		return 0;
	return 1;
}

int validar_j(char *cadena, char *j, int *index){
    int len = strlen(j);
	int i;
    for ( i = 0; i < len; i++){
        if (cadena[*index + i] != j[i])
            return 0;
    }
    for ( i = 0; i < len; i++){
        if (cadena[*index + len + i] != j[i])
            return 0;
    }
    *index += 2 * len;
    return 1;
}

void mostrar_datos(){
	printf("\nVALIDAR UNA CADENA A PARTIR DE UNA GRAMATICA (GIC)\n");
	printf("\ngramatica: G = {I, W^n, I, WI^2n, J^2 | n >= 1}\n");
	printf("I = 2101295\nW = gh\nWI = hg\nJ = elva\n");
}

int leer_opcion(){
	int valor;
	int valido = 0;
	do{
		if (scanf("%d", &valor) == 1 && (valor == 2 || valor == 1))
			valido = 1;
		else{
			printf("\nIngrese una opcion valida\n-> ");
			valido = 0;
		}
		while (getchar() != '\n');
	} while (!valido);

	return valor;
}
