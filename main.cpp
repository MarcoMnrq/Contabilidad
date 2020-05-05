#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#define separador "-------------------------------------------"

using namespace std;

class Cuenta{
private:
	string dato;
	string tipo;
public:
	Cuenta(string dato, string tipo){
		this->dato = dato;
		this->tipo = tipo;
	}
	string getDato(){ return dato; }
	string getTipo(){ return tipo; }
	~Cuenta(){}
};

int main() {
	cout << "Cargando datos..." << endl;
	vector<Cuenta*> datos;
	int nConsulta = 1;
	int nDatos = 0;
	int resultados;
	string consulta;
	string registro;
	string dato;
	string tipo;
	ifstream archivo;
	archivo.open("datos.csv");
	if(archivo.fail() == true){
		cout << "Error al abrir el archivo." << endl;
		return 0;
	}
	while(getline(archivo, registro)){
		stringstream ss(registro);
		getline(ss, dato, ';');
		getline(ss, tipo, ';');
		for(int k = 0; k < dato.size(); ++k){
			dato[k] = toupper(dato[k]);
		}
		datos.push_back(new Cuenta(dato, tipo));
	}
	archivo.close();
	nDatos = datos.size();
	cout << "Se cargaron " << nDatos << " datos correctamente al programa." << endl;
	cout << "ING: Ingresos" << endl;
	cout << "GA: Gastos Administrativos" << endl;
	cout << "GV: Gastos de ventas" << endl;
	cout << "OI: Otros ingresos" << endl;
	cout << "OG: Otros gastos" << endl;
	cout << "CV: Costo de ventas" << endl;
	cout << "IF: Ingresos Financieros" << endl;
	cout << "GF: Gastos Financieros" << endl;
	
	while(true){
		resultados = 0;
		cout << separador << endl;
		cout << "[ CONSULTA #" << nConsulta << " ]" << endl;
		cout << "Ingrese consulta: ";
		getline(cin, consulta);
		for(int k = 0; k < consulta.size(); ++k){
			consulta[k] = toupper(consulta[k]);
		}
		if(consulta == "EXIT"){
			break;
		}
		for(int i = 0; i < nDatos; i++){
			if (datos.at(i)->getDato().find(consulta) != string::npos) {
				++resultados;
				cout << resultados << ". " << datos.at(i)->getDato();
				cout << " (" << datos.at(i)->getTipo() << ")" << endl;
			}
		}
		cout << endl <<"Se encontraron " << resultados << " resultados." << endl;
		cout << endl;
		nConsulta++;
	}
	cout << "Adios." << endl;
	return 0;
}
