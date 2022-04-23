#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>

using namespace std;

// Esta función es para crear una semilla que nos servirá para generar los números aleatorios
int semilla() {
    auto point_time = std::chrono::system_clock::now();
    auto since_epoch = point_time.time_since_epoch();
    auto duracion = std::chrono::duration_cast<std::chrono::nanoseconds>(since_epoch);
    auto millisec = duracion.count();
    return millisec;
}

//Esta función genera números aleatorios teniendo como base una semilla
int random_number() {
    int aleatorio;
    srand(semilla());
    aleatorio= 33 + rand()%(128-33);
    return aleatorio;
}

//Esta función escribe la contraseña en el archivo
void escribir(string pass) {
    string file_name;
    cout << "Ingrese el nombre del archivo (Solo el nombre, no la extensión): ";
    getline(cin >> ws, file_name);
    file_name += ".txt";
    ofstream file;
    file.open(file_name);
    file << pass;
    file.close();
    cout << "Su archivo " << file_name << " ha sido creado con su contraseña adentro.\n";
}

int main() {
    string password, response;
    int pass_long;
    cout << "Bienvenido a este programa para generar tus contraseñas.\n";
    cout << "Ingrese la longitud de su contraseña: ";
    while (1) {
        cin >> pass_long;
        if (pass_long < 8) {
            cout << "Por su seguridad la contraseña no debe ser menor a 8 caracteres.";
            cout << "\nIntente nuevamente: ";
            continue;
        }
        break;
    }
    for (int i = 0; i < pass_long; i++) {
        password += random_number();
    }
    cout << "Su contraseña es: " << password;
    cout << "\nDesea guardarlo? (Ingrese \"si\" o \"no\"): ";
    getline(cin >> ws, response);
    if (response == "si") {
        escribir(password);
    }
    cout << "Gracias por usar nuestra aplicación!\n";
}
