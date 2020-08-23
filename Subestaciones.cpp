#include<iostream>
#include<string>
#include<stdlib.h>
#include"Funciones.cpp"
using namespace std;


int main(){
	//Seleccion de Carga(Unidades_Watts).
	selector.SeleccionUnidades();
	//Seleccion de aislamiento
	selector.SeleccionProteccionAislamiento();
    //Seleccion de tipo de tubos
    selector.SeleccionGrosorTubo();
	//Seleccion de sistema de distribucion (Subestacion)
	selector.SeleccionSubestacion();
	//Seleccion sistema a instalar
    selector.SeleccionInstalacion();
	//Seleccion circuito 
    selector.SeleccionCircuito();
    //Ingreso de unidades
    ingresarUnidades.IngresarUnidades();
	//Calculo
    calcular.CalculoUnidades();
	calcular.CalculoCalibre(Superficie,CorrienteCorrigida);
    calcular.CalculoHilos(AreaAislamiento);
    calcular.CalculoTubos(AreaConjuntoCables);
	calcular.CalculoProteccion(CorrienteCorrigida);
	//Resultados
	calcular.MostrarUnidades();
	calcular.MostrarResultados();
  return 0;      
}

