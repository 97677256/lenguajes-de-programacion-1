#include <iostream>//declaracion de librerias//
#include <string.h>
#include <stdio.h>
using std::string;//para las cadenas//
using namespace std;//para poder pedir datos al usuario//
string nombre, apellido1, apellido2,apellido,apellido3, resp, dia, mes, anio,rfc, RFC, palabras_inc[41],las_vocales[5],ape;//variables//
int i=0;//inie el ietrador para las palbras inc
int main(){//funcion principal
string palabras_inc[]={"BUEI","BUEY","CACA","CACO","CAGA","CAGO","CAKA","CAKO","COGE","COJA","KOGE","KOJO","KAKA","KULO","MAME","MAMO","MEAR","MEAS","MEON","MION","COJE","COJI","COJO","CULO","FETO","GUEY","JOTO","KACA","KACO","KAGA","KAGO","MOCO","MULA","PEDA","PEDO","PENE","PUTA","PUTO","QULO","RATA","RUIN"};//declaracion de palabras inconvenientes
string las_vocales[]={"A", "E", "I", "O", "U"};//declaracion de vocales que no ocupe
std::cout<<"Calculo de RFC\n";//lo primero que aparecera en pantalla
    std::cout<<"Introduce tu primer nombre: \n";//1er dato a pedir
    std::cin>>nombre;//se asigna a la variable
    std::cout<<"Introduce tu apellido paterno: \n";
    std::cin>>apellido;
    std::cout<<" Cuentas con apellido materno?,(si/no): \n";
    std::cin>>resp;//asignacion de la variable a la pregunta hecha
    if(resp== "si"){//si la respuesta es si entonces  
    std::cout<<"\nIntroduce tu apellido materno: \n";//se pide
    std::cin>>apellido2;}//y se asigna
    else{resp=="X";}//si es no se asigna una x
    std::cout<<"Fecha de nacimiento (solo números)\n";//continuamos
    std::cout<<"Día(dd): \n";//con la solicitud de datos
    std::cin>>dia;
    std::cout<<"Mes(mm): \n";
    std::cin>>mes;
    std::cout<<"Año(aaaa): \n";
    std::cin>>anio;
    for(int i=0; i<nombre.length(); i++){//cambiamos a mayusculas//
    nombre[i] =toupper(nombre[i]);  }//el nombre//
for(int i=0; i <apellido.length(); i++){//cambiamos a mayusculas
    apellido[i] = toupper(apellido[i]);}//el apellidopaterno
   for(int i=0; i<apellido2.length(); i++){//cambiamos a mayusculas
    apellido2[i] = toupper(apellido2[i]);}//en apellidomaterno
   nombre = nombre.substr(0,1);//extraemos las letras que ocupamos
   apellido1 = apellido.substr(0,1);
   apellido2 = apellido2.substr(0,1);
   anio = anio.substr(2,4);// aqui como comienza en cero ponemos una posicion antes del que ocupamos//
 for (int i = 1; i <= apellido.length(); i++){//iniciamos el ciclo en uno para que no tome la primera letra
 ape = apellido.substr(i, 1);//declare otra variable ya que encontre un error de comparacion
if (ape == "A"  || ape == "E" || ape == "I" || ape== "O"  || ape == "U") { apellido3 = ape;break;}}//aqui es donde sufri ya que me daba segun cambiaba el orden o todas las vocales o ninguna busque en internet y me salio uso de break
 rfc=apellido1+apellido3+apellido2+nombre;//otra variable llamada rfc guardara solo el nombre para la comparacion
    for(int i=0; i <41; i++){//ciclo para recorrer el arreglo
   if(rfc==palabras_inc[i]){rfc =apellido1+apellido3+apellido2+'X';}//si el arreglo es igual cambiara el nombre
   RFC = rfc+anio+mes+dia;}//declaramos la salida//
   std::cout<<"Tu RFC sin homoclave es: "<<RFC<<endl;//asignamos la salida
return 0;
}    