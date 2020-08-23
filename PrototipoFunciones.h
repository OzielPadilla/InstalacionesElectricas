#include <string>
using namespace std;

class Mensaje
{
public:
	void Advertencia();
};

class SeleccionMundial
{
private:
	int SeleccionUnidad;
	int SeleccionAislamiento;
	int SeleccionTubos;
	int SeleccionSistemaDistribucion;
	int SeleccionSistema;
	int SeleccionCircuitos;
public:
	int SeleccionUnidades();
	int SeleccionCircuito();
	int SeleccionInstalacion();
	int SeleccionProteccionAislamiento();
	int SeleccionGrosorTubo();
	int SeleccionSubestacion();
	//Regresar resultado
	int getSeleccionInstalacion(); //selector sistema
	int getSeleccionSubestacion(); // SeleccionSistemaDistribucion
	int getSeleccionProteccionAislamiento(); // SeleccionAislamiento
	int getSeleccionGrosorTubo(); //SeleccionTubos
};

class IngresoDeDatos : public SeleccionMundial{
	public:
	float IngresarUnidades();

};

class CalculoDeUnidades : public IngresoDeDatos{
public:
	float ConvertirCaballosWatts(float);
	float ConvertirToneladasWatts(float);
	float ConvertirWatts(float);
	float CalculoUnidades();
	float CalculoCalibre(float, float);
	float CalculoHilos(float);
	float CalculoTubos(float);
	float CalculoProteccion(float);
	float MostrarUnidades();
	float MostrarResultados();
};
