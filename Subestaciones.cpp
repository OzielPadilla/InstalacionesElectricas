#include<iostream>
#include<string>
#include<stdlib.h>
#include"Funciones.cpp"
using namespace std;


int main(){
	   cout<<"Seleccione la unidad a utilizar;"<<endl;             
	   cout<<"1.Unidad a utilizar HP."<<endl;    
	   cout<<"2.Unidad a utilizar TON."<<endl;
	   cout<<"3.Unidad a utilizar Watts."<<endl;
	   cin>>SeleccionUnidad;
	   switch(SeleccionUnidad){
	  	case 1:
	  		cout<<"Ingrese Caballos de fuerza:"<<endl;    
	    	cin>>CaballosFuerza;
	    	convertir.ConvertirCaballosWatts(CaballosFuerza);
	    break;
	    case 2:
	    	 cout<<"Ingrese Toneladas refrigeracion"<<endl;    
	       	 cin>>Toneladas;  	 
	       	 convertir.ConvertirToneladasWatts(Toneladas);
	    break;
		case 3:
			 cout<<"Ingrese Watts:"<<endl;                        
		     cin>>Watts;
		     convertir.ConvertirWatts(Watts);
		break;
		default:
			mensaje.Advertencia();
		break;
		}
	                                                                     	//Seleccion de aislamiento
		cout<<"Seleccione el aislamiento ha utilizar:"<<endl;
	    cout<<"1.Aislamiento tipo TW."<<endl;
	    cout<<"2.Aislamiento tipo THW."<<endl;
	    cout<<"3.Aislamiento tipo VINANEL 90 O NYLON."<<endl;
	    cin>>SeleccionAislamiento;
	                                                                        //Seleccion de tipo de tubos
        cout<<"Seleccione el tipo de pared de tubo conduit:"<<endl;
	    cout<<"1.Tubo conduit PARED DELGADA."<<endl;   
	    cout<<"2.Tubo conduit PARED GRUESA."<<endl;  
	    cout<<endl;
	    cin>>SeleccionTubos;
        cout<<"Seleccione el sistema distribucion a utilizar:"<<endl;            
	    cout<<"1.Sistema monofasico 2 hilos."<<endl; 
	    cout<<"2.Sistema monofasico 3 hilos."<<endl; 
	    cout<<"3.Sistema trifasico 3 hilos."<<endl; 
     	cout<<"4.Sistema trifasico 4 hilos."<<endl;
     	cin>>SeleccionSistemaDistribucion;
     	cout<<endl;
     	selector.SeleccionGeneral(SeleccionSistemaDistribucion); 
     	selector.SeleccionCircuito(SeleccionSistema);
     	ingresarUnidades.IngresarUnidades(SeleccionSistema,SeleccionSistemaDistribucion);
     	selector.SeleccionMonoTri(SeleccionSistemaDistribucion);
     	calcular.CalculoUnidades(SeleccionSistemaDistribucion,SeleccionSistema);
     	calcular.MostrarUnidades(SeleccionSistemaDistribucion);
		calcular.CalculoCalibre(Superficie,CorrienteCorrigida,SeleccionAislamiento);
     	calcular.CalculoHilos(SeleccionSistemaDistribucion,AreaAislamiento);
     	calcular.CalculoTubos(AreaConjuntoCables,SeleccionTubos);
		calcular.CalculoProteccion(SeleccionSistemaDistribucion,CorrienteCorrigida);
		cout<<endl;
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


		

		
  return 0;      
}

