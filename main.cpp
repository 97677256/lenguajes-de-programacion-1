#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//funcion para la primera vocal//
char vocalap1(const std::string& str){
    for(size_t i= 0; i< str.length();++i){
        char c= str[i];
        
if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u'  )
      return toupper (c);
    }
return'X' ;
    } 
  
// funcion de rfc//
string calcularRFC(const string& nombre, const string& ap1, const string& apemat, const string& nac){
    string rfc; 
    
    char letra1 = ap1[0];
    char vocal1= vocalap1(ap1);
    
    char inicilapemat = (!apemat.empty()) ? apemat[0]: 'X';
    
    char inicialnombre = nombre[0];
    
    string anio = nac.substr(2, 2);
    string mes = nac.substr(5, 2);
    string dia = nac.substr(8, 2);
    
    
    
    rfc= letra1;
    rfc += vocal1;
    rfc += inicilapemat;
    rfc += inicialnombre;
    rfc += anio;
    rfc += mes;
    rfc += dia;
    rfc += "XXX";
    
    transform(rfc.begin(), rfc.end(), rfc.begin(), ::toupper);

    return (rfc);
} 
  
int main(){
    
    string nombre, apemat, ap1, nac;
    
    cout<<"Proyecto final: Cálculo de RFC\n BIENVENIDO\n  Te ayudaremos a encontrar tu RFC solo ingresa lo que pide\n";//lo primero que aparecera en pantalla
    cout<<"Introduce tu nombre: \n";
  

    getline(cin, nombre);
    cout<<"Introduce tu apellido paterno: \n";
    getline(cin, ap1);
    cout<<"Introduce tu apellido materno ( si no tienes solo da enter): \n";
    getline(cin, apemat);
    cout<<"Introduce tu fecha de nacimiento (aaaa/mm/dd): \n";
    getline(cin, nac);
   
    
    string rfc = calcularRFC(nombre, ap1, apemat, nac);
    
            
    // Lista de palabras inconvenientes
    vector<string> palabras_inconvenientes = {"BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO","COGE","COJA","KOGE","KOJO","KAKA","KULO","MAME","MAMO","MEAR","MEAS","MEON","MION","COJE","COJI","COJO","CULO","FETO","GUEY","JOTO","KACA","KACO","KAGA","KAGO","MOCO","MULA","PEDA","PEDO","PENE","PUTA","PUTO","QULO","RATA","RUIN"};

    // Comprobar si el RFC generado es una palabra inconveniente
    for (const string& palabra : palabras_inconvenientes) {
        if (rfc.substr(0, 4) == palabra) {
            // Si es una palabra inconveniente, cambia la inicial del nombre por 'X' y vuelve a generar el RFC
            nombre[0] = 'X';
            rfc = calcularRFC(nombre, ap1, apemat, nac);
            break;
        }
    }
    
  
            
    cout<<" TU RFC ES: \n "<<rfc;
    cout<<"\n¡¡HASTA PRONTO!!!\n";
}