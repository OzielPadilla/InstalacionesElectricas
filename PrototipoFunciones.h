#include<string>
using namespace std;

class Mensaje{
	public:
		void Advertencia();
};
class SeleccionMundial{
	public:
	int SeleccionCircuito(int);
	int SeleccionGeneral(int);
	int SeleccionMonoTri(int);
};
class ConvertirUnidades{
	public:
	 float ConvertirCaballosWatts(float);
	 float ConvertirToneladasWatts(float);
	 float ConvertirWatts(float);
};
class IngresarUnidadesGlobales{
	public:
		float IngresarUnidades(int,int);

};
class CalculoDeUnidades{
	public:
		float CalculoUnidades(int, int);
		float MostrarUnidades(int);
		float CalculoCalibre(float,float,int);
		float CalculoHilos(int,float);
		float CalculoTubos(float,int);
		float CalculoProteccion(int,float);
};






