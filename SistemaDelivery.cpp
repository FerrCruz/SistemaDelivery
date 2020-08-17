#include <iostream>
#include <stdio.h>
#include <string.h>
/*
Los rubros de los negocios a los que presta servicio la empresa de delivery son Heladería, Pizzería, Bebidas,
Parrilla.
Se ingresan los datos de los negocios que quieren trabajar con la empresa.
Por cada negocio se ingresa: Nombre de comercio, rubro y código de zona en la que se encuentra.
Se admite un máximo de 10 comercios por rubro por cada zona.
Al momento de ingresar los datos del comercio rechazar su incorporación si ya se completó el cupo para el
rubro en esa zona.
La finalización del ingreso de datos por teclado de los comercios queda a criterio del grupo.
---------------------
1) Generar los archivos “Heladerias.dat”, “Pizzeria.dat”, “Bebidas.dat” y “Parrilla.dat” con los comercios
incorporados por cada rubro. Cada registro de cada uno de los archivos debe tener: nombre del
comercio y código de zona en la que se encuentra. Estos archivos deben estar ordenados
alfabéticamente por nombre del comercio.
2) Informar por cada zona si hay comercios para todos los rubros.
3) Informar, si hubo, rubros en los que no se hayan incorporado comercios.

Para realizar los puntos 2 y 3 utilizar estructuras de datos en memoria (arrays), no hacerlo con los archivos
generados
*/

using namespace std;

struct Rubro{
    char nombreComercio[30];
    int codZona;
}regrubro;

int mostrarMenuRubro();
int contarComercios(Rubro rubro[]);
int mostrarMenuZonas();
int verificarNum(int min, int max);
void limpiar(Rubro comercioHela[],Rubro comercioPizz[],Rubro comercioBebi[], Rubro comercioParr[]);
//-------Funcion de la consigna 1)----------------------
void agregarComerciosArchivos(Rubro comercioHela[],int contH,Rubro comercioPizz[],int contPizz,Rubro comercioBebi[],int contBeb,Rubro comercioParr[],int contParr);
//-------Funcion de la consigna 2)----------------------
void informarPorZonaComercios(Rubro comercioHela[],Rubro comercioPizz[],Rubro comercioBebi[],Rubro comercioParr[]);
int contarComerciosPorZona(Rubro rubro[],int zona);
//-------Funcion de la consigna 3)----------------------
void informarRubrosSinComercios(Rubro comercioHela[],Rubro comercioPizz[],Rubro comercioBebi[],Rubro comercioParr[]);
//------------------------------------------------------
int verificarCantComerPorZona(int codZona,Rubro comercioHela[]);
void agregarComercioHeladeria(Rubro comercioHela[],int &contH);
void agregarComercioPizzeria(Rubro comercioPizz[],int &contPizz);
void agregarComercioBebida(Rubro comercioBebi[],int &contBeb);
void agregarComercioParrilla(Rubro comercioParr[],int &contParr);
void generarAccion(int opc,Rubro comercioHela[] ,Rubro comercioPizz[] ,Rubro comercioBebi[] ,Rubro comercioParr[],int &contH,int &contPizz,int &contBeb,int &contParr);
void seguirProcedimiento(Rubro rubro[], int &contH, int codZona);
void ordenar(Rubro ch[], unsigned t);
void agregarDatosAlArchivo(Rubro rubro[], int cont, char nomArchivo[35]);


int main(){

    int contH=0, contPizz=0, contBeb=0, contParr=0;

    Rubro comercioHela[60], comercioPizz[60], comercioBebi[60], comercioParr[60];

    limpiar(comercioHela,comercioPizz,comercioBebi,comercioParr);

    int opc=0;

    do{
        opc = mostrarMenuRubro();
        if((opc>0)&&(opc<5)){
            generarAccion(opc, comercioHela, comercioPizz, comercioBebi, comercioParr,contH, contPizz, contBeb, contParr);
        }
    }while((opc>0)&&(opc<5)&&opc!=5);

    //2) Informar por cada zona si hay comercios para todos los rubros.
    informarPorZonaComercios(comercioHela,comercioPizz,comercioBebi,comercioParr);
    //3) Informar, si hubo, rubros en los que no se hayan incorporado comercios.
    informarRubrosSinComercios(comercioHela,comercioPizz,comercioBebi,comercioParr);
    //Funcion que agrega los datos de los arrays hacia los archivos (Heladeria,Pizzeria,Bebida,Parrilla)
    agregarComerciosArchivos(comercioHela,contH,comercioPizz,contPizz,comercioBebi,contBeb,comercioParr,contParr);

    return 0;
}

void generarAccion(int opc,Rubro comercioHela[] ,Rubro comercioPizz[] ,Rubro comercioBebi[] ,Rubro comercioParr[],int &contH,int &contPizz,int &contBeb,int &contParr){

    switch(opc){

        case 1:
            agregarComercioHeladeria(comercioHela,contH);
            break;

        case 2:
            agregarComercioPizzeria(comercioPizz,contPizz);
            break;

        case 3:
            agregarComercioBebida(comercioBebi,contBeb);
            break;

        case 4:
            agregarComercioParrilla(comercioParr,contParr);
            break;
    }
}

int mostrarMenuRubro(){

    int opcion = 0;

    cout<<"¿Que rubro desea ingresar comercios?"<<endl;
    cout<<"1)Heladeria"<<endl
        <<"2)Pizzeria"<<endl
        <<"3)Bebida"<<endl
        <<"4)Parrilla"<<endl
        <<"5)Salir"<<endl;

    opcion = verificarNum(0,5);

    return opcion;
}

int mostrarMenuZonas(){
    int opcion=0;

    cout<<"\nElija la zona que desea ingresar los comercios.(0 cero para salir del menu de zonas)"<<endl;
    cout<<"1)Zona 1"<<endl
        <<"2)Zona 2"<<endl
        <<"3)Zona 3"<<endl
        <<"4)Zona 4"<<endl
        <<"5)Zona 5"<<endl
        <<"6)Zona 6"<<endl;

    opcion = verificarNum(0,6);

    return opcion;
}

int verificarCantComerPorZona(int codZona,Rubro comercioRubro[]){
    int cont=0;
        for(int i=0; i<60; i++){
            if(comercioRubro[i].codZona==codZona){
                cont++;
            }
        }
    return cont;
}

int contarComercios(Rubro rubro[]){
    int cont=0;

    for(int i=0;i<60;i++){
        if(rubro[i].codZona!=0){
            cont++;
        }
    }
    return cont;
}

void seguirProcedimiento(Rubro rubro[], int &cont, int codZona){

    int i=0, lim=0, aux, cantComercios;
    char nombreComercio[30];

    lim = contarComercios(rubro);
    if(lim<60){
        i=0;
        cantComercios = verificarCantComerPorZona(codZona,rubro);

        if(cantComercios<10){
            cout<<"\n(Escriba 'No' para finalizar.) -- Maximo 10 comercios."<<endl;

                cout<<"Nombre Comercio: "<<endl;
                fflush(stdin);
                gets(nombreComercio);

                while((i<10-cantComercios)&&strcmpi(nombreComercio,"no")!=0&&(lim<60)){
                    if(strcmpi(nombreComercio,"no")!=0){
                        strcpy(rubro[lim].nombreComercio,nombreComercio);
                        rubro[lim].codZona = codZona;

                        i++;
                        lim++;
                        cont++;
                    }
                    if(i<10-cantComercios){
                        cout<<"Nombre Comercio: "<<endl;
                        fflush(stdin);
                        gets(nombreComercio);
                    }
                }
        }else{
            cout<<"Cantidad de comercios ya alcanzada (10) en la zona: "<<codZona<<endl;
        }
    }else{
            cout<<"Cantidad de 60 comercios ya alcanzada)"<<endl;
    }
}

void agregarComercioHeladeria(Rubro comercioHela[],int &contH){

    int codZona;
    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            seguirProcedimiento(comercioHela, contH,codZona);
        }
    }while(codZona!=0);

}

void agregarComercioPizzeria(Rubro comercioPizz[],int &contPizz){

    int codZona;
    char nombreComercio[30];

    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            seguirProcedimiento(comercioPizz, contPizz,codZona);
        }
    }while(codZona!=0);
}

void agregarComercioBebida(Rubro comercioBebida[],int &contBeb){

    int codZona;
    char nombreComercio[30];

    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            seguirProcedimiento(comercioBebida, contBeb,codZona);
        }
    }while(codZona!=0);
}

void agregarComercioParrilla(Rubro comercioParrilla[],int &contParr){

    int codZona;
    char nombreComercio[30];

    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            seguirProcedimiento(comercioParrilla, contParr,codZona);
        }
    }while(codZona!=0);
}

//2) Informar por cada zona si hay comercios para todos los rubros.
void informarPorZonaComercios(Rubro comercioHela[],Rubro comercioPizz[],Rubro comercioBebi[],Rubro comercioParr[]){

    int contZonaUno=0,contZonaDos=0,contZonaTres=0,contZonaCuatro=0,contZonaCinco=0,contZonaSeis=0, auxContH=0, auxContPizz=0,auxContB=0,auxContPa=0;

    cout<<"\nCONSIGNA 2"<<endl;

    for(int i=0; i<6; i++){
        auxContH = contarComerciosPorZona(comercioHela,i+1);
        auxContPizz = contarComerciosPorZona(comercioPizz,i+1);
        auxContB = contarComerciosPorZona(comercioBebi,i+1);
        auxContPa = contarComerciosPorZona(comercioParr,i+1);

        contZonaUno=auxContH+auxContPizz+auxContB+auxContPa;
        cout<<"Cant de comercios en Zona "<<(i+1)<<": "<<contZonaUno<<endl;
    }
}

int contarComerciosPorZona(Rubro rubro[],int zona){

    int cont=0;
    for(int i=0; i<60; i++){
         if(rubro[i].codZona==zona){
            cont++;
         }
    }
    return cont;
}

//3) Informar, si hubo, rubros en los que no se hayan incorporado comercios.
void informarRubrosSinComercios(Rubro comercioHela[],Rubro comercioPizz[],Rubro comercioBebi[],Rubro comercioParr[]){

    int contRubroHeladeria=0,contRubroPizzeria=0,contRubroBebida=0,contRubroParrilla=0;

    cout<<"\nCONSIGNA 3"<<endl;
    for(int i=0; i<60;i++){
        if(comercioHela[i].codZona>0&&comercioHela[i].codZona<7){
            contRubroHeladeria++;
        }

        if(comercioPizz[i].codZona>0&&comercioPizz[i].codZona<7){
            contRubroPizzeria++;
        }

        if(comercioBebi[i].codZona>0&&comercioBebi[i].codZona<7){
            contRubroBebida++;
        }

        if(comercioParr[i].codZona>0&&comercioParr[i].codZona<7){
            contRubroParrilla++;
        }
    }
    cout<<"Rubro: Heladeria || Cant: "<<contRubroHeladeria<<endl
        <<"Rubro: Pizzeria  || Cant: "<<contRubroPizzeria<<endl
        <<"Rubro: Bebidas   || Cant: "<<contRubroBebida<<endl
        <<"Rubro: Parrilla  || Cant: "<<contRubroParrilla<<"\n\n"<<endl;
}

//AGREGACIÓN DE DATOS DE LOS ARRAYS HACIA LOS ARCHIVOS CORRESPONDIENTES
void agregarComerciosArchivos(Rubro comercioHela[],int contH,Rubro comercioPizz[],int contPizz,Rubro comercioBebi[],int contBeb,Rubro comercioParr[],int contParr){

    if(contH > 0){
        ordenar(comercioHela, contH);
        agregarDatosAlArchivo(comercioHela, contH,"Heladerias.dat");
	}

	if(contPizz > 0){
		ordenar(comercioPizz, contPizz);
        agregarDatosAlArchivo(comercioPizz, contPizz,"Pizzeria.dat");
	}

	if(contBeb > 0){
    	ordenar(comercioBebi, contBeb);
        agregarDatosAlArchivo(comercioBebi, contBeb,"Bebidas.dat");
    }

	if(contParr > 0){
		ordenar(comercioParr, contParr);
        agregarDatosAlArchivo(comercioParr, contParr,"Parrilla.dat");
    }
}

void agregarDatosAlArchivo(Rubro rubro[], int cont, char nomArchivo[35]){

    FILE * arch;

    for(int i=0; i<cont; i++){
        	arch = fopen(nomArchivo, "ab");
                strcpy(regrubro.nombreComercio, rubro[i].nombreComercio);
                regrubro.codZona = rubro[i].codZona;
                fwrite(&regrubro, sizeof(struct Rubro), 1, arch);
        	fclose(arch);
    	}
}

void ordenar(Rubro ch[], unsigned t){

	int i = 0, j;
	Rubro aux;

    for ( i = 0; i < t; i++ ){
        for ( int j = i + 1; j < t; j++ ){

            if ((strcoll(ch[i].nombreComercio, ch[j].nombreComercio)) > 0) {

                strcpy (aux.nombreComercio, ch[i].nombreComercio);
                strcpy (ch[i].nombreComercio, ch[j].nombreComercio);
                strcpy (ch[j].nombreComercio, aux.nombreComercio);
            }
        }
    }
}

void limpiar(Rubro comercioHela[],Rubro comercioPizz[],Rubro comercioBebi[], Rubro comercioParr[]){

	for(int i=0; i<60; i++){
        comercioHela[i].codZona=0;
        comercioPizz[i].codZona=0;
        comercioBebi[i].codZona=0;
        comercioParr[i].codZona=0;
        strcpy(comercioHela[i].nombreComercio,"");
        strcpy(comercioPizz[i].nombreComercio,"");
        strcpy(comercioBebi[i].nombreComercio,"");
        strcpy(comercioParr[i].nombreComercio,"");
    }
}

int verificarNum(int min, int max){

    bool error = false;
    int num;

    cin>>num;
    do{
        error=false;

        if((num<min)||(num>max)){
            cout<<"Error de rango. Ingrese nuevamente."<<endl;
            cin>>num;
            error = true;
        }
    }while(error);

    return num;
}
