#include <iostream>
#include "Cabecera.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>

#define DIM 20

void llenadoInicial(Cola *banco){
	Cliente aux;
	
	aux.numCliente = 1;
	aux.tiempoLlegada = rand()%25+1;
	aux.tiempoEspera = 0;
	aux.tiempoDescanso = 0;
	aux.tiempoServicio = rand()%15+1;
	aux.tiempoSalida = aux.tiempoEspera + aux.tiempoServicio;
	aux.tiempoEntreLlegadas = aux.tiempoLlegada;
	
	(banco)->put(aux);
}

int MAX(int A, int B){
	if (A>=B){
		return A;
	}
	else{
		return B;
	}
}

Cliente llenadoAleatorio(Cola *banco,int n){
	Cliente aux;
	int A,B;
	
	aux.numCliente = n+1;
	A = banco->getCliente(n-1).tiempoLlegada;
	aux.tiempoLlegada = rand()%24+1+A;
	A = banco->getCliente(n-1).tiempoSalida;
	B = aux.tiempoLlegada;
	aux.tiempoEspera = MAX(A,B)-B;
	aux.tiempoDescanso = MAX(B,A)-A;
	aux.tiempoServicio = rand()%15+1;
	aux.tiempoSalida = aux.tiempoLlegada + aux.tiempoEspera + aux.tiempoServicio;
	A = banco->getCliente(n-1).tiempoLlegada;
	aux.tiempoEntreLlegadas = aux.tiempoLlegada - A;
	
	return (aux);
}

void cabecera(){
	
	printf ("\t\tUNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE\n");
	printf ("\t\t\tESTRUCTURAS DE DATOS");
	printf ("\n\tNombre: Santiago Del Salto\tKevin Taday\n\tDepartamento de Ciencias de la Computacion\tTutor: Ing. Fernando Solis\n\nTema: Ejercicio realizado en excel\n\n");
}

int main(int argc, char** argv) {
	Cola banco;
	srand(time(NULL));
	
	cabecera();
	
	//LLENADO INICIAL
	llenadoInicial(&banco);
	for (int i = 1; i<DIM;i++){
		banco.put(llenadoAleatorio(&banco,i));
	}
	
	
	
	printf ("NUM CLIENTE\tTIEMPO LLEGADA\tTIEMPO ESPERA\tTIEMPO DESCANSO\tTIEMPO SERVICIO\tTIEMPO SALIDA\tTIEMPO ENTRE LLEGADAS\n\n");
	for (int i = 0 ;i<banco.numClientes();i++){
		printf ("    %d \t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",banco.getCliente(i).numCliente,banco.getCliente(i).tiempoLlegada,banco.getCliente(i).tiempoEspera,banco.getCliente(i).tiempoDescanso,banco.getCliente(i).tiempoServicio,banco.getCliente(i).tiempoSalida,banco.getCliente(i).tiempoEntreLlegadas);
	}
	
	banco.~Cola();
	return 0;
}
