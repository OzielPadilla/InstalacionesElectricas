#include<iostream>
#include<string>
#include<math.h>
#include "PrototipoFunciones.h"
using namespace std;

float FactorPotencia,VoltajeEntreFaseN,VoltajeEntreFase,Eficiencia,FactorUtilizacion,Longitud,CaballosFuerza, Watts,Toneladas; //Datos
float CaidaVoltajeFNP,CaidaVoltajeFP;  //Cometida
float CaidaVoltajeNeutro, CaidaVoltajeFase; //calculo
float CorrienteTotal, CorrienteCorrigida,Superficie; 
float AmperiosRecubrimiento;
float AreaCalibre,AreaAislamiento,AreaConjuntoCables;
string Calibre, DiametroPared, Aislamiento, Subestacion;
float AreaParedTotal;
float ProteccionTermo;
int NumeroPolo;


//Objetos
Mensaje mensaje;
SeleccionMundial selector;
IngresoDeDatos ingresarUnidades;
CalculoDeUnidades calcular;
CalculoDeUnidades mostrarCalculo;


//Funciones SeleccionMunidal

//Seleccion de Unidaes de carga
int SeleccionMundial :: SeleccionUnidades(){ 
	cout<<"Seleccione la unidad a utilizar:"<<endl;             
	cout<<"1.Unidad a utilizar HP."<<endl;    
	cout<<"2.Unidad a utilizar TON."<<endl;
	cout<<"3.Unidad a utilizar Watts."<<endl;
	cin>>SeleccionUnidad;
	switch(SeleccionUnidad){
		case 1:
	  		cout<<"Ingrese Caballos de fuerza:"<<endl;    
	    	cin>>CaballosFuerza;
	    	calcular.ConvertirCaballosWatts(CaballosFuerza);
	    break;
	    case 2:
	    	 cout<<"Ingrese Toneladas refrigeracion"<<endl;    
	       	 cin>>Toneladas;  	 
	       	 calcular.ConvertirToneladasWatts(Toneladas);
	    break;
		case 3:
			 cout<<"Ingrese Watts:"<<endl;                        
		     cin>>Watts;
		     calcular.ConvertirWatts(Watts);
		break;
		default:
			mensaje.Advertencia();
		break;
	}
}
//Seleccion de Aislamiento
int SeleccionMundial :: SeleccionProteccionAislamiento(){
	cout<<"Seleccione el aislamiento ha utilizar:"<<endl;
	cout<<"1.Aislamiento tipo TW."<<endl;
	cout<<"2.Aislamiento tipo THW."<<endl;
	cout<<"3.Aislamiento tipo VINANEL 90 O NYLON."<<endl;
	cin>>SeleccionAislamiento;
	
}
int SeleccionMundial :: getSeleccionProteccionAislamiento(){
	return SeleccionAislamiento;
}
//Seleccion de Grosor de Tubos
int SeleccionMundial :: SeleccionGrosorTubo(){
	cout<<"Seleccione el tipo de pared de tubo conduit:"<<endl;
	cout<<"1.Tubo conduit PARED DELGADA."<<endl;   
	cout<<"2.Tubo conduit PARED GRUESA."<<endl;  
	cin>>SeleccionTubos;	
}
int SeleccionMundial :: getSeleccionGrosorTubo(){
	return SeleccionTubos;
}
//Seleccion Sistema de Subestacion
int SeleccionMundial :: SeleccionSubestacion(){
	cout<<"Seleccione el sistema distribucion a utilizar:"<<endl;            
	cout<<"1.Sistema monofasico 2 hilos."<<endl; 
	cout<<"2.Sistema monofasico 3 hilos."<<endl; 
	cout<<"3.Sistema trifasico 3 hilos."<<endl; 
 	cout<<"4.Sistema trifasico 4 hilos."<<endl;
	cin>>SeleccionSistemaDistribucion;
	switch(SeleccionSistemaDistribucion){
		case 1:
			Subestacion="Sistema Monofasico 2 hilos";
			break;
		case 2:
			Subestacion="Sistema Monofasico 3 hilos";
			break;
		case 3:
			Subestacion="Sistema Trifasico 3 hilos";
			break;
		case 4:
			Subestacion="Sistema Trifasico 4 hilos";
			break;
		default:
			mensaje.Advertencia();
			break;
	}
	return SeleccionSistemaDistribucion;
}

int  SeleccionMundial::getSeleccionSubestacion(){
	return SeleccionSistemaDistribucion;
}

//Seleccion del tipo de instalacion
int SeleccionMundial :: SeleccionInstalacion(){
	cout<<"Seleccione sistema a instalar:"<<endl;           
	cout<<"1.Alumbrado."<<endl;
	cout<<"2.Fuerza."<<endl;
	cin>>SeleccionSistema;
}

int  SeleccionMundial::getSeleccionInstalacion(){
	return SeleccionSistema;
}

//Seleccion de Tipo circuito a alimentar
int SeleccionMundial :: SeleccionCircuito(){
	cout<<"Seleccione circuito a utilizar:"<<"\n";
	cout<<"1.Alimentador principal."<<"\n";
	cout<<"2.Circutios derivados."<<"\n";
	cin>>SeleccionCircuitos;
	switch(SeleccionCircuitos){
		case 1: //alimenador principal
			if(SeleccionSistema == 1){
				CaidaVoltajeFP = CaidaVoltajeFNP = 1;      
			}else if(SeleccionSistema == 2){
				CaidaVoltajeFP = CaidaVoltajeFNP = 3;         
			}
		break;
		case 2: //circuito derivados
			if(SeleccionSistema == 1){
				CaidaVoltajeFP = CaidaVoltajeFNP = 2;
			}else if(SeleccionSistema == 2){
				CaidaVoltajeFP = CaidaVoltajeFNP = 1;
			}
		break;
		default:
			mensaje.Advertencia();
		break;		 
	}	
}
//Ingreso de unidades

float IngresoDeDatos :: IngresarUnidades(){
	cout<<"Ingrese factor de potencia:"<<"\n";                
	cin>>FactorPotencia;
	switch(selector.getSeleccionInstalacion()){
		case 1:
			cout<<"Ingrese factor de utilizacion:"<<"\n";
	        cin>>FactorUtilizacion;
		break;
		case 2:
	        cout<<"Ingrese la eficiencia:"<<"\n";    
			cin>>Eficiencia;
        break;
        default:
        	mensaje.Advertencia();
        break;
	}
	switch(selector.getSeleccionSubestacion()){
		case 1:
	    case 2:
		    cout<<"Ingrese el voltaje entre fase y neutro:"<<"\n";
			cin>>VoltajeEntreFaseN;
	    break;
	    case 3:
	    case 4:
	    	cout<<"Ingrese el voltaje entre fase:"<<"\n";
			cin>>VoltajeEntreFase;
		break;
		default:
			mensaje.Advertencia();
		break;
	}
	cout<<"Ingrese la longitud del cable (METROS)"<<"\n";
	cin>>Longitud;
}

//Calculos

float CalculoDeUnidades :: ConvertirCaballosWatts(float CaballosWatts){
	Watts= CaballosWatts *745.4;
	return Watts;
}

float CalculoDeUnidades :: ConvertirToneladasWatts(float Toneladas){
    Watts= Toneladas / 12000;
	return Watts;
}
float CalculoDeUnidades :: ConvertirWatts(float Watts){
    Watts=Watts;
	return Watts;
}
void Mensaje :: Advertencia(){
	cout<<"Error";
}


float CalculoDeUnidades :: CalculoUnidades(){
	switch(selector.getSeleccionSubestacion()){
		case 1: //Sistema monofasico 2 hlos
		if(selector.getSeleccionInstalacion()==1){
			
		CorrienteTotal=Watts/(VoltajeEntreFaseN*FactorPotencia);
		CorrienteCorrigida=CorrienteTotal*FactorUtilizacion;
		
		}else if(selector.getSeleccionInstalacion()==2){
			
		CorrienteTotal=Watts/(VoltajeEntreFaseN*FactorPotencia*Eficiencia);
		CorrienteCorrigida=CorrienteTotal*1.25;
		}
		Superficie=(4*Longitud*CorrienteCorrigida)/(VoltajeEntreFaseN*CaidaVoltajeFNP);
		CaidaVoltajeNeutro=(Longitud*CorrienteCorrigida)/(25*Superficie);
		break;
	    case 2: //Sistema monofasico 3 hilos
		if(selector.getSeleccionInstalacion()==1){
		CorrienteTotal=Watts/(2*VoltajeEntreFaseN*FactorPotencia);
		CorrienteCorrigida=CorrienteTotal*FactorUtilizacion;
		}else if(selector.getSeleccionInstalacion()==2){
		CorrienteTotal=Watts/(2*VoltajeEntreFaseN*FactorPotencia*Eficiencia);
		CorrienteCorrigida=CorrienteTotal*1.25;
		}
		Superficie=(2*Longitud*CorrienteCorrigida)/(VoltajeEntreFaseN*CaidaVoltajeFNP);
		CaidaVoltajeNeutro=(Longitud*CorrienteCorrigida)/(25*Superficie);
		break;
		case 3: // Trifasico 
		if(selector.getSeleccionInstalacion()==1){
		    mensaje.Advertencia();
		}else if(selector.getSeleccionInstalacion()==2){
			CorrienteTotal=Watts/(sqrt(3)*VoltajeEntreFase*FactorPotencia*Eficiencia);
			CorrienteCorrigida=CorrienteTotal*1.25;
			Superficie=(2*sqrt(3)*Longitud*CorrienteCorrigida)/(VoltajeEntreFase*CaidaVoltajeFP);
	        CaidaVoltajeFase=(sqrt(3)*Longitud*CorrienteCorrigida)/50*Superficie;
		}
		break;
		case 4: //Trifasico 4 hilos 
		if(selector.getSeleccionInstalacion()==1){
			CorrienteTotal=Watts/(sqrt(3)*VoltajeEntreFase*FactorPotencia*Eficiencia);
			CorrienteCorrigida=CorrienteTotal*FactorUtilizacion;	
	    }else if(selector.getSeleccionInstalacion()==2){
	    	CorrienteTotal=Watts/(sqrt(3)*VoltajeEntreFase*FactorPotencia*Eficiencia);
			CorrienteCorrigida=CorrienteTotal*1.25;
		}
		Superficie=(2*sqrt(3)*Longitud*CorrienteCorrigida)/(VoltajeEntreFase*CaidaVoltajeFP);
	    CaidaVoltajeFase=(sqrt(3)*Longitud*CorrienteCorrigida)/50*Superficie;
		break;
		default:
		mensaje.Advertencia();
		break;
    }
}

float CalculoDeUnidades :: CalculoCalibre(float Superficie,float CorrienteCorrigida){
	float areaCalibre[]={0.8235,1.307,2.082,3.307,5.260,8.367,13.30,21.15,33.62,42.41,53.48,67.43,85.01,107.2,126.7,152,177.3,202.7,253.4,304.0,380,506.7};
	float areaAislamamientoTW[]={0,0,9.62,12.57,16.62,28.27,47.78,63.60,86.60,123,145.30,172,203.60,243.30,298.60,343,430.10,514.70,735.40,934.80};
	float areaAislamientoTHWN[]={0,0,7.07,9.62,15.21,26.42,35.26,56.75,78.54,90,124.60,149.60,176.70,216.40,263,304.8,387,467.60,674.30,814.30};
	string numeroCalibre[]={"18","16","14","12","10","8","6","4","2","1","1/0","2/0","3/0","4/0","250","300","350","400","500","600","750","1000"};
	float amperiosTW[]={0,0,15,20,30,40,55,70,95,110,125,145,165,195,215,240,260,280,320,355,400,455};  
	float amperiosTHW[]={0,0,15,20,30,50,65,85,115,130,150,175,200,230,255,285,310,335,380,420,475,545};
	float amperiosNYLON90[]={14,18,20,25,35,55,75,95,130,150,170,195,225,260,290,320,350,380,430,475,535,615};
	switch(selector.getSeleccionProteccionAislamiento()){
		case 1: //TW
		for(int i=0; i<30; i++){
			if((Superficie<=areaCalibre[i])&&(CorrienteCorrigida<=amperiosTW[i])){
				AmperiosRecubrimiento=amperiosTW[i];
				AreaCalibre=areaCalibre[i];
				Calibre=numeroCalibre[i];
				AreaAislamiento=areaAislamamientoTW[i];
				Aislamiento="TW";
			break;
			}
		}
		break;
		case 2: //THW
		for(int i=0; i<30; i++){
			if((Superficie<=areaCalibre[i])&&(CorrienteCorrigida<=amperiosTW[i])){
				AmperiosRecubrimiento=amperiosTHW[i];
				AreaCalibre=areaCalibre[i];
				Calibre=numeroCalibre[i];
				AreaAislamiento=areaAislamamientoTW[i];
				Aislamiento="THW";
			break;
			}
		}
		break;
		case 3: //THWN O THHN
		for(int i=0; i<30; i++){
			if((Superficie<=areaCalibre[i])&&(CorrienteCorrigida<=areaAislamientoTHWN[i])){
				AmperiosRecubrimiento=amperiosNYLON90[i];
				AreaCalibre=areaCalibre[i];
				Calibre=numeroCalibre[i];
				AreaAislamiento=areaAislamientoTHWN[i];
				Aislamiento="THWN/THHN";
			break;
			}
		}
		break;
		default:
			cout<<"error";
		break;	
		}	
}

float CalculoDeUnidades :: CalculoHilos(float AreaAislamamiento){
	switch(selector.getSeleccionSubestacion()){
		case 1:
			AreaConjuntoCables=AreaAislamamiento*2;
			break;
		case 2:
			AreaConjuntoCables=AreaAislamamiento*3;
			break;
		case 3:
			AreaConjuntoCables=AreaAislamamiento*3;
			break;
		case 4:
			AreaConjuntoCables=AreaAislamamiento*4;
			break;
		default:
			mensaje.Advertencia();
		break;
	}
}

float CalculoDeUnidades :: CalculoTubos(float AreaConjuntoCables){
	float paredDelgada[]={78,142,220,390,532,874,0,0,0,0,0,0};
	float paredGruesa[]={96,158,250,422,570,926,1376,2116,1638,3575,4000,9000};
	string paredPulgada[]={"1/2","3/4","1","1 1/4","1 1/2","2","2 1/2","3","4","2 1/2 x 2 1/2","4 x 4","6 x 6"};
	switch(selector.getSeleccionGrosorTubo()){
		case 1: //paredDelgada
		for(int i=0;i<15; i++){
			if(AreaConjuntoCables<=paredDelgada[i]){
				AreaParedTotal=paredDelgada[i];
				DiametroPared=paredPulgada[i];
			break;
			}
		}
		break;
		case 2: //paredGruesa
		for(int i=0;i<15; i++){
			if(AreaConjuntoCables<=paredGruesa[i]){
				AreaParedTotal=paredGruesa[i];
				DiametroPared=paredPulgada[i];
			break;
			}
		}
		break;
		default:
			mensaje.Advertencia();
		break;
		}
}

float CalculoDeUnidades :: CalculoProteccion(float CorrienteCorrigida){
	float unPolo[]={15,20,30,40,50};
	float dosPolo[]={15,20,30,40,50,70};
	float tresPolo[]={15,20,30,40,50,70,100,125,150,175,200,225,250,300,350,400,500,600};
		switch(selector.getSeleccionSubestacion()){
			case 1:
			for(int i=0; i<20; i++){
				if(CorrienteCorrigida<=unPolo[i]){
					ProteccionTermo=unPolo[i];
					NumeroPolo=1;
				break;
				}
			}
			break;
			case 2:
			for(int i=0; i<20; i++){
				if(CorrienteCorrigida<=dosPolo[i]){
					ProteccionTermo=dosPolo[i];
					NumeroPolo=2;
				break;
				}
			}
			break;
			case 3:
			case 4:
			for(int i=0; i<20; i++){
				if(CorrienteCorrigida<=tresPolo[i]){
					ProteccionTermo=tresPolo[i];
					NumeroPolo=3;
				break;
				}
			}
			break;
			default:
				mensaje.Advertencia();
			break;
		}
}	

float CalculoDeUnidades :: MostrarUnidades(){
	    switch(selector.getSeleccionSubestacion()){
		case 1:
		case 2:
		cout<<"//////////// RESULTADOS DE CALCULOS //////////////"<<endl<<endl;
		cout<<"La corriente total es: "<<"\n"<<CorrienteTotal<<"\n";
	    cout<<"La corriente corregida es:"<<"\n"<<CorrienteCorrigida<<"\n";
	    cout<<"La caida voltaje entre fase y neutro es:"<<"\n"<<CaidaVoltajeNeutro<<"\n";
	    cout<<"La Seccion en milimetro cuadrado es:"<<"\n"<<Superficie<<"\n";
	    break;
	    case 3:
	    case 4:
		cout<<"//////////// RESULTADOS DE CALCULOS //////////////"<<endl<<endl;
		cout<<"La corriente total es: "<<"\n"<<CorrienteTotal<<"\n";
	    cout<<"La corriente corregida es:"<<"\n"<<CorrienteCorrigida<<"\n";
	    cout<<"La caida voltaje entre fase es:"<<"\n"<<CaidaVoltajeFase<<"\n";
	    cout<<"La Seccion en milimetro cuadrado es:"<<"\n"<<Superficie<<"\n";
	    break;
	    default:
	    	mensaje.Advertencia();
	    break;
	}
}

float CalculoDeUnidades :: MostrarResultados(){

	cout<<"//////////////////////// RESULTADO DE CALIBRE ////////////////////////"<<endl<<endl;
	cout<<"El sistema a utilizar es: "<<Subestacion<<endl<<endl;
	cout<<"El calibre a utilizar es: "<<Calibre<<" AWG"<<endl<<endl;
	cout<<"El area del calibre "<<Calibre<<" es: "<<AreaCalibre<<" Miilimetros cuadrados"<<endl<<endl;
	cout<<"El aislamiento termoplastico a utilizar es: "<<Aislamiento<<endl<<endl;
	cout<<"La corriente soportada: "<<AmperiosRecubrimiento<<" Amperios"<<endl<<endl;
	cout<<"El area con el recubrimiento "<<Aislamiento<<" es: "<<AreaAislamiento<<" Milimetros cuadrados"<<endl<<endl;
	cout<<"El area del conjunto de cables es: "<<AreaConjuntoCables<<" Milimetros cuadrados"<<endl<<endl;
	cout<<endl;
	cout<<"//////////////////////// RESULTADO DE TUBOS ////////////////////////"<<endl<<endl;
	cout<<"El diametro nominal los tubos a utilizar es: "<<DiametroPared<<" Pulgadas"<<endl<<endl;
	cout<<"El area de los tubos a utilizar es: "<<AreaParedTotal<<" Milimetros cuadrados"<<endl<<endl;
	cout<<endl;
	cout<<"//////////////////////// RESULTADO DE PROTECCION ////////////////////////"<<endl<<endl;
	cout<<"La proteccion termomagnetica a utilizar es: "<<NumeroPolo<<" x "<<ProteccionTermo<<endl<<endl;
	cout<<endl;
}




