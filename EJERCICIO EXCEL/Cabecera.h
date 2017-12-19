#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Cliente{
	int numCliente;
	int tiempoLlegada;
	int tiempoEspera;
	int tiempoDescanso;
	int tiempoServicio;
	int tiempoSalida;
	int tiempoEntreLlegadas;
};

struct Nodo{
	Cliente clientes;
	Nodo *siguiente;
};


class Cola{
	private:
		int Items;
		Nodo *cola;
		Nodo *cabeza;
		
	public:
		//CONSTRUCTOR
		Cola(){
			Items = 0;
			cola = NULL;
			cabeza = NULL;
		}
		
		//DESTRUCTOR
		~Cola(){}
		
		//AGREGAR ELEMENTOS
		Cliente put(Cliente valor){
			Nodo *temp;
			
			temp = new Nodo();
			if (temp == NULL){
				printf ("ERROR");
			}
			
			else{
				Items++;
				temp->clientes = valor;
				temp->siguiente=NULL;
				
				if (cabeza == NULL){
					cabeza = temp;
					cola = temp;
				}
				else{
					cola->siguiente = temp;
					cola = temp;			
				}
			}
			
			return valor;
		}
		
		//AVISA SI COLA ESTA VACIA
		int empty (){
			return Items == 0;
		}
		
		//RETIRO DE ELEMENTOS
		
		Cliente get(){
			Nodo *temp;
			Cliente d;
			
			if (empty())
				printf ("ERROR");
			else{
				d = cabeza->clientes;
				if (cabeza){					
					delete cabeza;
					cabeza = temp;
					Items--;
				}	
			}			
			return d;
		}	
		
		int numClientes(){
			return Items;
		}
		
		//GETTERS
		Cliente getCliente(int n){
			Nodo *temp;
			temp = cabeza;
			if (temp->siguiente == NULL){
				return (temp->clientes);
			}
			else{
				for (int i = 0;i<n ;i++){
					temp=temp->siguiente;
				}
			}
			return(temp->clientes);
		}	
};
