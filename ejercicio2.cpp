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

struct Heladeria{
    char nombreComercio[30];
    int codZona;
}regheladeria;

struct Pizzeria{
    char nombreComercio[30];
    unsigned codZona;
}regpizzeria;

struct Bebida{
    char nombreComercio[30];
    unsigned codZona;
}regbebida;

struct Parrilla{
    char nombreComercio[30];
    unsigned codZona;
}regparrilla;

int mostrarMenuRubro();
int mostrarMenuZonas();
void limpiar(Heladeria comercioHela[],Pizzeria comercioPizz[],Bebida comercioBebi[], Parrilla comercioParr[]);
void mostrarRubro(Heladeria comercioHela[],int codZona,int lim);
//-------Funcion de la consigna 2)------------
void informarPorZonaComercios(Heladeria comercioHela[],Pizzeria comercioPizz[],Bebida comercioBebi[],Parrilla comercioParr[]);
//-------Funcion de la consigna 3)------------
void informarRubrosSinComercios(Heladeria comercioHela[],Pizzeria comercioPizz[],Bebida comercioBebi[],Parrilla comercioParr[]);
//--------------------------------------------
int verificarCantComerPorZonaH(int codZona,Heladeria comercioHela[]);
int verificarCantComerPorZonaPi(int codZona,Pizzeria comercioPizz[]);
int verificarCantComerPorZonaBeb(int codZona,Bebida comercioBebida[]);
int verificarCantComerPorZonaParr(int codZona,Parrilla comercioParrilla[]);
void agregarComercioHeladeria(Heladeria comercioHela[],FILE*hel);
void agregarComercioPizzeria(Pizzeria comercioPizz[],FILE*pizz);
void agregarComercioBebida(Bebida comercioBebi[],FILE*beb);
void agregarComercioParrilla(Parrilla comercioParr[],FILE*parr);
void generarAccion(int opc,Heladeria comercioHela[],FILE*hel,Pizzeria comercioPizz[],FILE*pizz,Bebida comercioBebi[],FILE*beb,Parrilla comercioParr[],FILE*parr);

int main(){

    FILE *hel;
	FILE *pizz;
	FILE *beb;
	FILE *parr;

    //VER EL PROBLEMA DE POR QUE INICIALIZAN LOS ARRAYS CON VALORES
    Heladeria comercioHela[60];
    Pizzeria comercioPizz[60];
    Bebida comercioBebi[60];
    Parrilla comercioParr[60];

    limpiar(comercioHela,comercioPizz,comercioBebi,comercioParr);

    int opc=0;

    //Consigna 1)-Solo falta ordenar los arrays (comercioHela,comercioPizz,comercioBebi, comercioParr) alfabeticamente por el nombre del los comercios.
    do{
        opc = mostrarMenuRubro();
        if((opc>0)&&(opc<5)){
            generarAccion(opc, comercioHela, hel, comercioPizz, pizz, comercioBebi, beb, comercioParr, parr);
        }
    }while((opc>0)&&(opc<5)&&opc!=5);

    //2) Informar por cada zona si hay comercios para todos los rubros.
    informarPorZonaComercios(comercioHela,comercioPizz,comercioBebi,comercioParr);
    //3) Informar, si hubo, rubros en los que no se hayan incorporado comercios.
    informarRubrosSinComercios(comercioHela,comercioPizz,comercioBebi,comercioParr);
    return 0;
}

void generarAccion(int opc,Heladeria comercioHela[],FILE*hel ,Pizzeria comercioPizz[],FILE*pizz ,Bebida comercioBebi[],FILE*beb ,Parrilla comercioParr[],FILE*parr){

    switch(opc){

        case 1:
            agregarComercioHeladeria(comercioHela,hel);
            break;

        case 2:
            agregarComercioPizzeria(comercioPizz,pizz);
            break;

        case 3:
            agregarComercioBebida(comercioBebi,beb);
            break;

        case 4:
            agregarComercioParrilla(comercioParr,parr);
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
    cin>>opcion;
    return opcion;
}

int mostrarMenuZonas(){
    int opcion=0;

    cout<<"Elija la zona que desea ingresar los comercios. || 0 (cero para salir del menu de zonas)"<<endl;
    cout<<"1)Zona 1"<<endl
        <<"2)Zona 2"<<endl
        <<"3)Zona 3"<<endl
        <<"4)Zona 4"<<endl
        <<"5)Zona 5"<<endl
        <<"6)Zona 6"<<endl;
    cin>>opcion;

return opcion;
}

void mostrarRubro(Heladeria comercioHela[],int codZona,int lim){

    for(int i=0; i<lim; i++){
        if(codZona==comercioHela[i].codZona){
            cout<<"Nombre Comercio: "<<comercioHela[i].nombreComercio<<" || Zona: "<<comercioHela[i].codZona<<endl;
        }

    }
}
int verificarCantComerPorZonaH(int codZona,Heladeria comercioHela[]){
    int cont=0;
        for(int i=0; i<60; i++){
            if(comercioHela[i].codZona==codZona){
                cont++;
            }
        }
    return cont;
}
int verificarCantComerPorZonaPi(int codZona,Pizzeria comercioPizz[]){
    int cont=0;
        for(int i=0; i<60; i++){
            if(comercioPizz[i].codZona==codZona){
                cont++;
            }
        }
    return cont;
}

int verificarCantComerPorZonaBeb(int codZona,Bebida comercioBebida[]){
    int cont=0;
        for(int i=0; i<60; i++){
            if(comercioBebida[i].codZona==codZona){
                cont++;
            }
        }
    return cont;
}

int verificarCantComerPorZonaParr(int codZona,Parrilla comercioParrilla[]){
    int cont=0;
        for(int i=0; i<60; i++){
            if(comercioParrilla[i].codZona==codZona){
                cont++;
            }
        }
    return cont;
}

void agregarComercioHeladeria(Heladeria comercioHela[],FILE*hel){

    int i=0, lim=0, aux;
    int codZona,auxCod;
    int cantComercios;
    char nombreComercio[30];

    //Ver si hay alguna manera de verificar si un archivo (por ejemplo, Parrilla.dat) no existe para asi informar al usuario que no existe comercios de ese rubro

    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            if(auxCod==codZona){
                i=0;
                cantComercios = verificarCantComerPorZonaH(codZona,comercioHela);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;

                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioHela[lim].nombreComercio,nombreComercio);
                                comercioHela[lim].codZona = codZona;

                                hel = fopen("Heladerias.dat", "ab");
                                    strcpy(regheladeria.nombreComercio, nombreComercio);
                                    regheladeria.codZona = codZona;
                                    fwrite(&regheladeria, sizeof(struct Heladeria), 1, hel);

                                fclose(hel);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10-aux&&strcmpi(nombreComercio,"no")!=0&&lim<60);
                }
            }else{
                i=0;
                cantComercios = verificarCantComerPorZonaH(codZona,comercioHela);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioHela[lim].nombreComercio,nombreComercio);
                                comercioHela[lim].codZona = codZona;

                                hel = fopen("Heladerias.dat", "ab");
                                    strcpy(regheladeria.nombreComercio, nombreComercio);
                                    regheladeria.codZona = codZona;
                                    fwrite(&regheladeria, sizeof(struct Heladeria), 1, hel);

                                fclose(hel);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10&&strcmpi(nombreComercio,"no")!=0&&lim<60);

                    if(strcmpi(nombreComercio,"no")==0){
                        aux=i;
                        auxCod=codZona;
                    }
                }else{
                    cout<<"Cantidad de comercios ya alcanzada del codZona "<<codZona<<endl;
                }
            }
        }
    }while(codZona!=0);

}

void agregarComercioPizzeria(Pizzeria comercioPizz[],FILE*pizz){

    int i=0, lim=0, aux;
    int codZona,auxCod;
    int cantComercios;
    char nombreComercio[30];

    //Ver si hay alguna manera de verificar si un archivo (por ejemplo, Parrilla.dat) no existe para asi informar al usuario que no existe comercios de ese rubro

    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            if(auxCod==codZona){
                i=0;
                cantComercios = verificarCantComerPorZonaPi(codZona,comercioPizz);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioPizz[lim].nombreComercio,nombreComercio);
                                comercioPizz[lim].codZona = codZona;

                                pizz = fopen("Pizzeria.dat", "ab");
                                    strcpy(regheladeria.nombreComercio, nombreComercio);
                                    regpizzeria.codZona = codZona;
                                    fwrite(&regheladeria, sizeof(struct Pizzeria), 1, pizz);

                                fclose(pizz);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10-aux&&strcmpi(nombreComercio,"no")!=0&&lim<60);
                }
            }else{
                i=0;
                cantComercios = verificarCantComerPorZonaPi(codZona,comercioPizz);
                if(cantComercios<10){
                   cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioPizz[lim].nombreComercio,nombreComercio);
                                comercioPizz[lim].codZona = codZona;

                                pizz = fopen("Pizzeria.dat", "ab");
                                    strcpy(regpizzeria.nombreComercio, nombreComercio);
                                    regpizzeria.codZona = codZona;
                                    fwrite(&regpizzeria, sizeof(struct Pizzeria), 1, pizz);

                                fclose(pizz);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10&&strcmpi(nombreComercio,"no")!=0&&lim<60);

                    if(strcmpi(nombreComercio,"no")==0){
                        aux=i;
                        auxCod=codZona;
                    }
                }else{
                    cout<<"Cantidad de comercios ya alcanzada del codZona "<<codZona<<endl;
                }
            }
        }
    }while(codZona!=0);
}

void agregarComercioBebida(Bebida comercioBebida[],FILE*beb){
    int i=0, lim=0, aux;
    int codZona,auxCod;
    int cantComercios;
    char nombreComercio[30];

    //Ver si hay alguna manera de verificar si un archivo (por ejemplo, Parrilla.dat) no existe para asi informar al usuario que no existe comercios de ese rubro
    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            if(auxCod==codZona){
                i=0;
                cantComercios = verificarCantComerPorZonaBeb(codZona,comercioBebida);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioBebida[lim].nombreComercio,nombreComercio);
                                comercioBebida[lim].codZona = codZona;

                                beb = fopen("Bebidas.dat", "ab");
                                    strcpy(regbebida.nombreComercio, nombreComercio);
                                    regbebida.codZona = codZona;
                                    fwrite(&regbebida, sizeof(struct Bebida), 1, beb);

                                fclose(beb);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10-aux&&strcmpi(nombreComercio,"no")!=0&&lim<60);
                }
            }else{
                i=0;
                cantComercios = verificarCantComerPorZonaBeb(codZona,comercioBebida);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioBebida[lim].nombreComercio,nombreComercio);
                                comercioBebida[lim].codZona = codZona;

                                beb = fopen("Bebidas.dat", "ab");
                                    strcpy(regbebida.nombreComercio, nombreComercio);
                                    regbebida.codZona = codZona;
                                    fwrite(&regbebida, sizeof(struct Bebida), 1, beb);

                                fclose(beb);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10&&strcmpi(nombreComercio,"no")!=0&&lim<60);

                    if(strcmpi(nombreComercio,"no")==0){
                        aux=i;
                        auxCod=codZona;
                    }
                }else{
                    cout<<"Cantidad de comercios ya alcanzada del codZona "<<codZona<<endl;
                }
            }
        }
    }while(codZona!=0);
}

void agregarComercioParrilla(Parrilla comercioParrilla[],FILE*parr){

    int i=0, lim=0, aux;
    int codZona,auxCod;
    int cantComercios;
    char nombreComercio[30];

    //Ver si hay alguna manera de verificar si un archivo (por ejemplo, Parrilla.dat) no existe para asi informar al usuario que no existe comercios de ese rubro
    parr = fopen("Parrilla.dat", "ab");
    do{
        codZona = mostrarMenuZonas();
        if(codZona!=0){
            if(auxCod==codZona){
                i=0;
                cantComercios = verificarCantComerPorZonaParr(codZona,comercioParrilla);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioParrilla[lim].nombreComercio,nombreComercio);
                                comercioParrilla[lim].codZona = codZona;

                                parr = fopen("Parrilla.dat", "ab");
                                    strcpy(regparrilla.nombreComercio, nombreComercio);
                                    regparrilla.codZona = codZona;
                                    fwrite(&regparrilla, sizeof(struct Bebida), 1, parr);

                                fclose(parr);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10-aux&&strcmpi(nombreComercio,"no")!=0&&lim<60);
                }
            }else{
                i=0;
                cantComercios = verificarCantComerPorZonaParr(codZona,comercioParrilla);
                if(cantComercios<10){
                    cout<<"(Escriba 'No' para finalizar.)"<<endl;
                    do{
                        if(lim<60){
                            cout<<"Nombre Comercio: "<<endl;
                            fflush(stdin);
                            gets(nombreComercio);
                            //cin>>nombreComercio;
                            if(strcmpi(nombreComercio,"no")!=0){
                                strcpy(comercioParrilla[lim].nombreComercio,nombreComercio);
                                comercioParrilla[lim].codZona = codZona;

                                parr = fopen("Parrilla.dat", "ab");
                                    strcpy(regparrilla.nombreComercio, nombreComercio);
                                    regparrilla.codZona = codZona;
                                    fwrite(&regparrilla, sizeof(struct Bebida), 1, parr);

                                fclose(parr);
                                i++;
                                lim++;
                            }
                        }
                    }while(i<10&&strcmpi(nombreComercio,"no")!=0&&lim<60);

                    if(strcmpi(nombreComercio,"no")==0){
                        aux=i;
                        auxCod=codZona;
                    }
                }else{
                    cout<<"Cantidad de comercios ya alcanzada (10) del codigo de Zona "<<codZona<<endl;
                }
            }
        }
    }while(codZona!=0);
}

//2) Informar por cada zona si hay comercios para todos los rubros.
void informarPorZonaComercios(Heladeria comercioHela[],Pizzeria comercioPizz[],Bebida comercioBebi[],Parrilla comercioParr[]){

    int contZonaUno=0,contZonaDos=0,contZonaTres=0,contZonaCuatro=0,contZonaCinco=0,contZonaSeis=0;

    cout<<"CONSIGNA 2"<<endl;

    for(int i=0; i<60;i++){
        if((comercioHela[i].codZona==1)||(comercioPizz[i].codZona==1)||(comercioBebi[i].codZona==1)||(comercioParr[i].codZona==1)){
            contZonaUno++;
        }
        if((comercioHela[i].codZona==2)||(comercioPizz[i].codZona==2)||(comercioBebi[i].codZona==2)||(comercioParr[i].codZona==2)){
            contZonaDos++;
        }
        if((comercioHela[i].codZona==3)||(comercioPizz[i].codZona==3)||(comercioBebi[i].codZona==3)||(comercioParr[i].codZona==3)){
            contZonaTres++;
        }
        if((comercioHela[i].codZona==4)||(comercioPizz[i].codZona==4)||(comercioBebi[i].codZona==4)||(comercioParr[i].codZona==4)){
            contZonaCuatro++;
        }
        if((comercioHela[i].codZona==5)||(comercioPizz[i].codZona==5)||(comercioBebi[i].codZona==5)||(comercioParr[i].codZona==5)){
            contZonaCinco++;
        }
        if((comercioHela[i].codZona==6)||(comercioPizz[i].codZona==6)||(comercioBebi[i].codZona==6)||(comercioParr[i].codZona==6)){
            contZonaSeis++;
        }
    }
    cout<<"Cant de comercios en Zona 1: "<<contZonaUno<<endl;
    cout<<"Cant de comercios en Zona 2: "<<contZonaDos<<endl;
    cout<<"Cant de comercios en Zona 3: "<<contZonaTres<<endl;
    cout<<"Cant de comercios en Zona 4: "<<contZonaCuatro<<endl;
    cout<<"Cant de comercios en Zona 5: "<<contZonaCinco<<endl;
    cout<<"Cant de comercios en Zona 6: "<<contZonaSeis<<endl;
}

//3) Informar, si hubo, rubros en los que no se hayan incorporado comercios.
void informarRubrosSinComercios(Heladeria comercioHela[],Pizzeria comercioPizz[],Bebida comercioBebi[],Parrilla comercioParr[]){
    int contRubroHeladeria=0,contRubroPizzeria=0,contRubroBebida=0,contRubroParrilla=0;

    cout<<"CONSIGNA 3"<<endl;
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
        <<"Rubro: Parrilla  || Cant: "<<contRubroParrilla<<endl;
}

void limpiar(Heladeria comercioHela[],Pizzeria comercioPizz[],Bebida comercioBebi[], Parrilla comercioParr[]){
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
