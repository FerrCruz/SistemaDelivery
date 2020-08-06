#include <iostream>
#include <stdio.h>


using namespace std;

struct Rubro{
    char nombreComercio[30];
    unsigned codZona;
};

int main()
{
    FILE *arch;
    char nomArchivo[21];
    cout<<"Nombre Archivo (.dat) ";
    cin>>nomArchivo;
    //arch=fopen("Parcial1.dat","rb");
    arch=fopen(nomArchivo,"rb");
    if(arch==NULL)
        cout<<"ERROR"<<endl;
    else
    {
        int cont=0;
        Rubro rub;
        fread(&rub,sizeof(Rubro),1,arch);
        while (!feof(arch))
        {
            cont++;
            cout<<"  "<<rub.nombreComercio<<"  "<<rub.codZona<<endl;
            fread(&rub,sizeof(Rubro),1,arch);

        }
        fclose(arch);
        cout<<"Cant: "<<cont<<endl;
    }
    return 0;
}













