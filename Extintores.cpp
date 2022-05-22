/*Autor: Luis Gonzalo Guzman Sanchez, Fecha: 22/05/2022
Control de extintores de UVM
*/
#include<stdio.h>
#include<stdlib.h>
#include"milibreria.h"
//Declarar
#define MAX 10
struct extintor {
	char tipo[10];
	char fecha[10]; 
	char resguardo[30];
	char edificio[10];
	char area[17];
};
int n=0; //variable
//Prototipos
int menu();
void agregar(struct extintor x[]);
void imprimir(struct extintor x[], int tipo);
void buscarTipoExt(struct extintor x[]);
void buscarxEdificioExt(struct extintor x[]);
void buscarxFechaExt(struct extintor x[]);
void guardar(struct extintor x[]);
void cargar(struct extintor x[]);
void reasignar(struct extintor x[]); 
//main
int main(){
	int op;
	struct extintor grupo[MAX];
	do{
		op=menu();
		switch(op){
			case 0: printf("Adios..\n");
				break;
			case 1: agregar(grupo);
				break;
			case 2: imprimir(grupo,0);
				break;
			case 3: buscarxEdificioExt(grupo);
				break;
			case 4: buscarxFechaExt(grupo);
				break;
			case 5: buscarTipoExt(grupo);
				break;
			case 6:reasignar(grupo);
				break;
			case 7:guardar(grupo);
				break;
			case 8:cargar(grupo);
				break;
		}
	}while(op!=0);
	return 0;
}
//funciones
int menu(){
 	int opcion;
	printf("-------- MENU PRINCIPAL ---------\n");
	printf("0. Salir \n");
	printf("1. Agregar exintor: \n");
	printf("2. Lista de todos los extintores: \n");
	printf("3. Listar Extintores de un edificio especifico: \n");
	printf("4. Listar Extintores de una fecha especifica: \n");
	printf("5. Listar Extintores de un tipo especifico: \n");
	printf("6. Recargar extintor: \n");
	printf("7. Guardar Archivos: \n");
	printf("8. Cargar Archivos: \n");
	printf("--------------------------------------\n");
	opcion=leerd("Selecciona una opcion: ",0,8);
	return opcion;
}
void agregar(struct extintor x[]){
	int pregunta;
	while(n<MAX){
		leersd("Tipo de Extintor: 1. A 2. B 3. C 4. D 5. K: ",x[n].tipo,1,5);
		leers("Fecha: ", x[n].fecha,10);
		leers("Edificio: ", x[n].edificio,10);
		leers("Area: ", x[n].area,17);
		n++; //suma contador +1
		//ciclo if para cerrar o agregar mas extintores
		pregunta=leerd("¿Agregar otro Extintor? (1-Si, 0-No): ", 0, 1);
		if (pregunta==0) {
			break;
		}
	}
	//si el arreglo se llena, detenerse.
	if(n==MAX){
		printf("Arreglo lleno!!!\n");
		system("PAUSE");
	}
}
//La funcion imprimir el parametro tipo se le indica que va a imprimir
//imprimir TOTAL de extintores de fuego
void imprimir(struct extintor x[], int tipo){
	char mensaje[20];
	switch(tipo){
		case 0: strcpy(mensaje, "TOTALES	");
			break;
	}
	printf("----------------- EXTINTORES %s ----------------------------\n", mensaje);
	printf("NO. EXTINTOR \tTIPO\t\t          \tFECHA \t\tEDIFICIO       \t\tAREA\n");
	printf("----------------------------\n");
	for (int i=0;i<n;i++){ 
		switch(tipo){
			case 0: printf("%2d    \t\t%-30s%-30s%-30s%-30s \n",i+1,x[i].tipo,x[i].fecha,x[i].edificio,x[i].area);
				break;
		}
	}
	printf("----------------------------\n");
		system("PAUSE");
} 
//Solo buscara por tipo de extintor escrito
void buscarTipoExt(struct extintor x[]) {
	//Pedir el dato
	char nombre[30];
	int busca=0;
	leers("Buscar tipo de extintor asignado: ", nombre,30);
		for (int i=0;i<n;i++){	
			if(strcmp(nombre,x[i].tipo)==0){
					busca=1;
					printf("NO. EXTINTOR \tTIPO\t\t          \tFECHA \t\tEDIFICIO       \t\tAREA\n");
					printf("%2d    \t\t%-30s%-30s%-30s%-30s \n",i+1,x[i].tipo,x[i].fecha,x[i].edificio,x[i].area);
					break;
			}	
		}
		if(busca==0){
			printf("No se encuentra\n");
		}
		system("PAUSE");
	}
	//Solo buscara por edificio escrito
	void buscarxEdificioExt(struct extintor x[]) {
	//Pedir el dato
	char nombre[30];
	int busca=0;
	leers("Buscar por edificio donde el extintor esta asignado: ", nombre,30);
		for (int i=0;i<n;i++){	
			if(strcmp(nombre,x[i].edificio)==0){
					busca=1;
					printf("NO. EXTINTOR \tTIPO\t\t          \tFECHA \t\tEDIFICIO       \t\tAREA\n");
					printf("%2d    \t\t%-30s%-30s%-30s%-30s \n",i+1,x[i].tipo,x[i].fecha,x[i].edificio,x[i].area);
					break;
			}	
		}
		if(busca==0){
			printf("No encontrado o no registrado\n");
		}
		system("PAUSE");
	}
//Solo buscara por fecha asignada
void buscarxFechaExt(struct extintor x[]) {
//Pedir el dato
char nombre[30];
int busca=0;
leers("Buscar por fecha donde el extintor se relleno: ", nombre,30);
	for (int i=0;i<n;i++){	
		if(strcmp(nombre,x[i].fecha)==0){
				busca=1;
				printf("NO. EXTINTOR \tTIPO\t\t          \tFECHA \t\tEDIFICIO       \t\tAREA\n");
				printf("%2d    \t\t%-30s%-30s%-30s%-30s \n",i+1,x[i].tipo,x[i].fecha,x[i].edificio,x[i].area);
				break;
		}	
	}
	if(busca==0){
		printf("No encontrado o no registrado\n");
	}
	system("PAUSE");
}
//Reasignar fecha de recarga
void reasignar(struct extintor x[]){
	//Pedir el dato
char nombre[30];
int busca=0;
leers("Buscar numero de extintor: ", nombre,30);
	for (int i=0;i<n;i++){	
		if(nombre,i){
				busca=1;
				printf("NO. EXTINTOR \tTIPO\t\t          \tFECHA \t\tEDIFICIO       \t\tAREA\n");
				printf("%2d    \t\t%-30s%-30s%-30s%-30s \n",i+1,x[i].tipo,x[i].fecha,x[i].edificio,x[i].area);
				//Reasignar fecha
				leers("Cambiar fecha: ", x[i].fecha,10);
				break;
		}	
	}
	if(busca==0){
		printf("No encontrado o no registrado\n");
	}
	system("PAUSE");
}
	//Guardar los datos como arreglos de estructuras en un archivo binario
void guardar(struct extintor x[]){
	FILE *f;
	f=fopen("Lista_Extintores.dat","w");
	if(f==NULL){
		printf("Error\n no se puede guardar el archivo\n");
	}
	else {
		for(int i=0;i<n;i++){
			fwrite(&x[i],sizeof(x[i]),1,f);
		}
		fclose(f);
		printf("--->Se guardaron %d registro\n",n);
		system("PAUSE");
	}
}
//Leer el archivo binario y cargarlo al arreglo de estructuras
void cargar(struct extintor x[]){
	FILE *f;
	f=fopen("Lista_Extintores.dat","r");
	n=0;
	if(f==NULL){
		printf("Error al intentar a cargar los datos!!!\n");
	}
	else {
		printf("Leyendo.............!\n");
		while(fread(&x[n],sizeof(x[n]),1,f)==1){
			n++;
			printf("%2d    \t\t%-30s%-30s%-30s%-30s \n",n,x[n-1].tipo,x[n-1].fecha,x[n-1].edificio,x[n-1].area);
		}
		fclose(f);
		printf("NO. EXTINTOR \tTIPO\t\t          \tFECHA \t\tEDIFICIO       \t\tAREA\n");
		printf("--->Total de %d registros cargados\n",n);
		printf("REVISA QUE LOS ARCHIVOS NO ESTEN CORRUPTOS\n\n");
		system("PAUSE");
	}
}

