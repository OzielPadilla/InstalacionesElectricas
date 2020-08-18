#include<iostream>
#include<string>
#include<math.h>
#include "PrototipoFunciones.h"
using namespace std;

int SeleccionSistemaDistribucion,SeleccionUnidad,SeleccionAislamiento,SeleccionTubos,SeleccionSistema,Circuito;  //Selectores
float FactorPotencia,VoltajeEntreFaseN,VoltajeEntreFase,Eficiencia,FactorUtilizacion,Longitud,CaballosFuerza, Watts,Toneladas; //Datos
float CaidaVoltajeFNP,CaidaVoltajeFP;  //Cometida
float CaidaVoltajeNeutro, CaidaVoltajeFase; //calculo
float CorrienteTotal, CorrienteCorrigida,Superficie; 
float AmperiosRecubrimiento;
float AreaCalibre,AreaAislamiento,AreaConjuntoCables;
string Calibre;
string DiametroPared;
string Aislamiento;
string Subestacion;
float AreaParedTotal;
float ProteccionTermo;
int NumeroPolo;


//Objetos
Mensaje mensaje;
SeleccionMundial selector;
ConvertirUnidades convertir;
IngresarUnidadesGlobales ingresarUnidades;
CalculoDeUnidades calcular;
CalculoDeUnidades mostrarCalculo;


int SeleccionMundial :: SeleccionMonoTri(int SeleccionSistemaDistribucion){
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
}
void Mensaje :: Advertencia(){
	cout<<"Error";
}

int SeleccionMundial :: SeleccionCircuito(int SeleccionSistema){
	cout<<"Seleccione circuito a utilizar:"<<"\n";
	cout<<"1.Alimentador principal."<<"\n";
	cout<<"2.Circutios derivados."<<"\n";
	cin>>Circuito;
	switch(Circuito){
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

int SeleccionMundial :: SeleccionGeneral(int SeleccionSistemaDistribucion){
	cout<<"Seleccione sistema:"<<endl;           
	cout<<"1.Alumbrado."<<endl;
	cout<<"2.Fuerza."<<endl;
	cin>>SeleccionSistema;
}

float ConvertirUnidades :: ConvertirCaballosWatts(float CaballosWatts){
	Watts= CaballosWatts *745.4;
	return Watts;
}

float ConvertirUnidades :: ConvertirToneladasWatts(float Toneladas){
    Watts= Toneladas / 12000;
	return Watts;
}
float ConvertirUnidades :: ConvertirWatts(float Watts){
    Watts=Watts;
	return Watts;
}

float IngresarUnidadesGlobales :: IngresarUnidades(int SeleccionSistema, int SeleccionSistemaDistribucion){
	cout<<"Ingrese factor de potencia:"<<"\n";                
	cin>>FactorPotencia;
	switch(SeleccionSistema){
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
	switch(SeleccionSistemaDistribucion){
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

float CalculoDeUnidades :: CalculoUnidades(int SeleccionSistemaDistribucion, int SeleccionSistema){
	switch(SeleccionSistemaDistribucion){
		case 1: //Sistema monofasico 2 hlos
		if(SeleccionSistema==1){
		CorrienteTotal=Watts/(VoltajeEntreFaseN*FactorPotencia);
		CorrienteCorrigida=CorrienteTotal*FactorUtilizacion;
		}else if(SeleccionSistema==2){
		CorrienteTotal=Watts/(VoltajeEntreFaseN*FactorPotencia*Eficiencia);
		CorrienteCorrigida=CorrienteTotal*1.25;
		}
		Superficie=(4*Longitud*CorrienteCorrigida)/(VoltajeEntreFaseN*CaidaVoltajeFNP);
		CaidaVoltajeNeutro=(Longitud*CorrienteCorrigida)/(25*Superficie);
		break;
	    case 2: //Sistema monofasico 3 hilos
		if(SeleccionSistema==1){
		CorrienteTotal=Watts/(2*VoltajeEntreFaseN*FactorPotencia);
		CorrienteCorrigida=CorrienteTotal*FactorUtilizacion;
		}else if(SeleccionSistema==2){
		CorrienteTotal=Watts/(2*VoltajeEntreFaseN*FactorPotencia*Eficiencia);
		CorrienteCorrigida=CorrienteTotal*1.25;
		}
		Superficie=(2*Longitud*CorrienteCorrigida)/(VoltajeEntreFaseN*CaidaVoltajeFNP);
		CaidaVoltajeNeutro=(Longitud*CorrienteCorrigida)/(25*Superficie);
		break;
		case 3: // Trifasico 
		if(SeleccionSistema==1){
		    mensaje.Advertencia();
		}else if(SeleccionSistema==2){
			CorrienteTotal=Watts/(sqrt(3)*VoltajeEntreFase*FactorPotencia*Eficiencia);
			CorrienteCorrigida=CorrienteTotal*1.25;
			Superficie=(2*sqrt(3)*Longitud*CorrienteCorrigida)/(VoltajeEntreFase*CaidaVoltajeFP);
	        CaidaVoltajeFase=(sqrt(3)*Longitud*CorrienteCorrigida)/50*Superficie;
		}
		break;
		case 4: //Trifasico 4 hilos 
		if(SeleccionSistema==1){
			CorrienteTotal=Watts/(sqrt(3)*VoltajeEntreFase*FactorPotencia*Eficiencia);
			CorrienteCorrigida=CorrienteTotal*FactorUtilizacion;	
	    }else if(SeleccionSistema==2){
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
float CalculoDeUnidades :: MostrarUnidades(int SeleccionSistemaDistribucion){
	    switch(SeleccionSistemaDistribucion){
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
 return CorrienteTotal,CorrienteCorrigida,CaidaVoltajeNeutro,CaidaVoltajeFase,Superficie;
}

float CalculoDeUnidades :: CalculoCalibre(float Superficie,float CorrienteCorrigida,int SeleccionAislamiento){
	float areaCalibre[]={0.8235,1.307,2.082,3.307,5.260,8.367,13.30,21.15,33.62,42.41,53.48,67.43,85.01,107.2,126.7,152,177.3,202.7,253.4,304.0,380,506.7};
	float areaAislamamientoTW[]={0,0,9.62,12.57,16.62,28.27,47.78,63.60,86.60,123,145.30,172,203.60,243.30,298.60,343,430.10,514.70,735.40,934.80};
	float areaAislamientoTHWN[]={0,0,7.07,9.62,15.21,26.42,35.26,56.75,78.54,90,124.60,149.60,176.70,216.40,263,304.8,387,467.60,674.30,814.30};
	string numeroCalibre[]={"18","16","14","12","10","8","6","4","2","1","1/0","2/0","3/0","4/0","250","300","350","400","500","600","750","1000"};
	float amperiosTW[]={0,0,15,20,30,40,55,70,95,110,125,145,165,195,215,240,260,280,320,355,400,455};  
	float amperiosTHW[]={0,0,15,20,30,50,65,85,115,130,150,175,200,230,255,285,310,335,380,420,475,545};
	float amperiosNYLON90[]={14,18,20,25,35,55,75,95,130,150,170,195,225,260,290,320,350,380,430,475,535,615};
	switch(SeleccionAislamiento){
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
float CalculoDeUnidades :: CalculoHilos(int SeleccionSistemaDistribucion,float AreaAislamamiento){
	switch(SeleccionSistemaDistribucion){
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
float CalculoDeUnidades :: CalculoTubos(float AreaConjuntoCables, int SeleccionTubos){
	float paredDelgada[]={78,142,220,390,532,874,0,0,0,0,0,0};
	float paredGruesa[]={96,158,250,422,570,926,1376,2116,1638,3575,4000,9000};
	string paredPulgada[]={"1/2","3/4","1","1 1/4","1 1/2","2","2 1/2","3","4","2 1/2 x 2 1/2","4 x 4","6 x 6"};
	switch(SeleccionTubos){
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

float CalculoDeUnidades :: CalculoProteccion(int SeleccionSistemaDistribucion, float CorrienteCorrigida){
	float unPolo[]={15,20,30,40,50};
	float dosPolo[]={15,20,30,40,50,70};
	float tresPolo[]={15,20,30,40,50,70,100,125,150,175,200,225,250,300,350,400,500,600};
		switch(SeleccionSistemaDistribucion){
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




