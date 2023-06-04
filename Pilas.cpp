// LIFO o bien conocidas como PILAS
#include <iostream>
using namespace std;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

struct Nodo{
       int Dato;
       Nodo *sig;
       };

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class Lifo{
      private:
              Nodo *Inicio, *Apt;
      public:
             Lifo()
             {
                   Inicio=NULL;
             }
             Nodo *CreaNodo(int dato)
             {
                  Nodo *Nuevo;
                  Nuevo=new Nodo;
                  Nuevo -> Dato = dato;
                  Nuevo -> sig = NULL;
                  return Nuevo;
             }
             void InsertaInicio(int dato)
             {
                  Nodo *Aux;
                  Aux = CreaNodo(dato);
                  if(Inicio == NULL)
                  Inicio = Aux;
                  else
                  {
                      Aux->sig= Inicio;
                      Inicio = Aux;
                  }
             }
             void Modificar(int dato)
             {
                  int D;
                  cout<<"\n Dame el dato que deseas modificar:";
                  cin>>D;
                  Apt= Inicio;
                  while(Apt->Dato !=D)
                  {
                                  Apt=Apt->sig;
                  }
                  Apt->Dato =dato;
             }
             void Eliminar(void)
             {
                  Nodo *Dest;
                  Dest=Inicio;
                  Inicio=Inicio->sig;
             }
             void buscar(int dato)
             {
                  Apt= Inicio;
                  while(Apt->Dato!=dato)
                  {
                                     Apt= Apt->sig;
                                     if (Apt->Dato==dato)
                                     cout<<"\n El dato si existe";
                  }
             }
             void Imprime(void)
             {
                  for(Apt=Inicio;Apt!= NULL; Apt=Apt->sig)
                  cout<<"<-[ "<<Apt->Dato<<" ] ";
             }
             ~Lifo(void)
             {
                        while(Inicio!=NULL)
                        Apt = Inicio;
                        Inicio = Inicio->sig;
                        delete Apt;
             }
      };

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int menu(void)
{
    int opc;
    cout<<"\n\t\t Bienvenido al Menu de Pilas";
    cout<<"\n\t\t Por Alan Gonzalez";
    cout<<"\n\t Que deseas hacer";
    cout<<"\n\n 1.- Ingresar datos a la pila.";
    cout<<"\n\n 2.- Modificar algun dato de la pila";
    cout<<"\n\n 3.- Buscar algun dato de la pila";
    cout<<"\n\n 4.- Eliminar el dato de la pila";
    cout<<"\n\n 5.- Salir a Windows";
    cout<<"\n\n Ingresa tu opcion";
    cin>> opc;
    return opc;
}
     

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(void)
{
    Lifo A;
    int a, b;
    
    do
    {
               a=menu();
               system("cls");
               if(a==1)
               {
                       cout<<"\n Ingresa el dato que deseas ingresar ";
                       cin>> b;
                       A.InsertaInicio(b);
                       A.Imprime();
               }
               if(a==2)
               {
                       cout<<"\n Ingresa el dato por el cual vas a sustituir";
                       cin>> b;
                       A.Modificar(b);
                       A.Imprime();
               }
               if(a==3)
               {
                       cout<<"\n Que dato deseas Buscar";
                       cin>> b;
                       A.buscar(b);
                       A.Imprime();       
               }
               if(a==4)
               {
                       A.Eliminar();
                       A.Imprime();
               }
               if(a==5)
               {
                       cout<<"\n Gracias por participar";
               }
    }while(a!=5);
    system("pause");
    return 0;
}
