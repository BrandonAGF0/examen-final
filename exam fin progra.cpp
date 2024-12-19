#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase Empleado
class Empleado {
private:
    int carnet;
    string nombre;
    string fechaNacimiento;
    string categoria;
    float salario;
    string direccion;
    string telefono;
    string correo;
    static vector<string> correosUsados;

public:
    // Constructor
    Empleado(int _carnet, string _nombre, string _fechaNac, int edad, 
             string _categoria, float _salario = 250000, 
             string _direccion = "San Jose") {
        
        // Validar edad
        if (edad < 18) {
            cout << "Error: No se pueden contratar menores de edad\n";
            return;
        }
        
        // Validar salario
        if (_salario < 250000 || _salario > 500000) {
            cout << "Error: Salario debe estar entre 250000 y 500000\n";
            return;
        }
        
        // Validar categoría
        if (_categoria != "Administrador" && _categoria != "Operario" && _categoria != "Peon") {
            cout << "Error: Categoria invalida\n";
            return;
        }
        
        carnet = _carnet;
        nombre = _nombre;
        fechaNacimiento = _fechaNac;
        categoria = _categoria;
        salario = _salario;
        direccion = _direccion;
    }
    
    // Setter para correo con validación
    bool setCorreo(string _correo) {
        for(int i = 0; i < correosUsados.size(); i++) {
            if(correosUsados[i] == _correo) {
                cout << "Error: Correo ya registrado\n";
                return false;
            }
        }
        correo = _correo;
        correosUsados.push_back(_correo);
        return true;
    }
    
    void mostrarDatos() {
        cout << "\nDatos del Empleado:"
             << "\nCarnet: " << carnet
             << "\nNombre: " << nombre
             << "\nFecha Nacimiento: " << fechaNacimiento
             << "\nCategoria: " << categoria
             << "\nSalario: " << salario
             << "\nDireccion: " << direccion
             << "\nCorreo: " << correo << endl;
    }
    
    int getCarnet() { return carnet; }
    void setNombre(string _nombre) { nombre = _nombre; }
    void setFechaNacimiento(string _fechaNac) { fechaNacimiento = _fechaNac; }
    void setCategoria(string _categoria) { categoria = _categoria; }
    void setSalario(float _salario) { salario = _salario; }
    void setDireccion(string _direccion) { direccion = _direccion; }
    void setTelefono(string _telefono) { telefono = _telefono; }
    string getNombre() { return nombre; }
    string getFechaNacimiento() { return fechaNacimiento; }
    string getCategoria() { return categoria; }
    float getSalario() { return salario; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }
    string getCorreo() { return correo; }
};

// Inicializar vector estático
vector<string> Empleado::correosUsados;

// Clase Proyecto
class Proyecto {
private:
    int codigo;
    string nombre;
    string fechaInicio;
    string fechaFin;
    static vector<string> nombresUsados;

public:
    Proyecto(int _codigo, string _nombre, string _fechaInicio, string _fechaFin) {
        // Validar nombre único
        for(int i = 0; i < nombresUsados.size(); i++) {
            if(nombresUsados[i] == _nombre) {
                cout << "Error: Nombre de proyecto ya existe\n";
                return;
            }
        }
        
        codigo = _codigo;
        nombre = _nombre;
        fechaInicio = _fechaInicio;
        fechaFin = _fechaFin;
        nombresUsados.push_back(_nombre);
    }
    
    void mostrarDatos() {
        cout << "\nDatos del Proyecto:"
             << "\nCodigo: " << codigo
             << "\nNombre: " << nombre
             << "\nFecha Inicio: " << fechaInicio
             << "\nFecha Fin: " << fechaFin << endl;
    }
    
    int getCodigo() { return codigo; }
    void setNombre(string _nombre) { nombre = _nombre; }
    void setFechaInicio(string _fechaInicio) { fechaInicio = _fechaInicio; }
    void setFechaFin(string _fechaFin) { fechaFin = _fechaFin; }
    string getNombre() { return nombre; }
    string getFechaInicio()
