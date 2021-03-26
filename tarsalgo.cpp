#include <iostream>
#include <fstream>

using namespace std;

struct Tadat {
int ora;
int perc;
int id;
int kibe;
};

int main()
{
    Tadat adat[1000];
    //1 feladat

    string temp;
    int tszaml = 0;
    char kibeseged[3];
    ifstream fajl ("ajto.txt");
    while (!fajl.eof())
    {
        getline(fajl,temp);
        sscanf(temp.c_str(),"%d %d %d %s", &(adat[tszaml].ora),&(adat[tszaml].perc),&(adat[tszaml].id),(kibeseged));
        if (kibeseged[0]=='k')
            adat[tszaml++].kibe = 0;
        if (kibeseged[0] == 'b')
            adat[tszaml++].kibe = 1;
    }
    cout<<"2. feladat"<<endl;

    cout<<adat[0].id<<endl;
    int i;
    int atmen = 0;

    for (i=0;i<tszaml;i++)
    {
        if (adat[i].kibe == 0)
            atmen = adat[i].id;
    }
    cout<<atmen<<endl;

    cout<<"3. feldat"<<endl;

    int forgalom[101];

    for (i=1;i<=100;i++)
        forgalom[i]=0;

    for (i=0;i<tszaml;i++)
    {
        forgalom[adat[i].id]++;
    }
    for (i=1;i<=100;i++)
    {
        if (forgalom[i]>0)
        {
            cout<<i<<" "<<forgalom[i]<<endl;
        }
    }
    cout<<"4.feladat"<<endl;

    for (i=1;i<=100;i++)
    {
        if ((forgalom[i] > 0) && (forgalom[i]%2 == 1))
            cout<<i<<" ";
    }
    cout<<endl<<"5. feladat"<<endl;

    int letszam = 0;
    int maxlszam = 0;
    int lora;
    int lperc;

    for (i=0;i<tszaml;i++)
    {
        if (adat[i].kibe == 1)
        {
            if (++letszam > maxlszam)
            {
                maxlszam = letszam;
                lora = adat[i].ora;
                lperc = adat[i].perc;
            }
        }
        else
            letszam--;
    }

    cout<<maxlszam<<" "<<lora<<":"<<lperc<<endl;

    cout<<"6. feladat"<<endl;

    int beazon;
    cin>>beazon;

    cout<<"7. feladat"<<endl;

    int idoszaml = 0;
    int kibeseged2;

    for (i=0;i<tszaml;i++)
    {
        if (adat[i].id == beazon)
        {
            if (adat[i].kibe == 1)
            {
                cout<<adat[i].ora<<":"<<adat[i].perc<<"-";
                kibeseged2 = 1;
                lora = adat[i].ora;
                lperc = adat[i].perc;
            }
            else
            {
                cout<<adat[i].ora<<":"<<adat[i].perc<<endl;
                kibeseged2 = 0;
                idoszaml+=(adat[i].ora*60+adat[i].perc)-(lora*60+lperc);
            }
        }
    }

    cout<<endl<<"8. feladat"<<endl;

    if (kibeseged2 == 1)
    idoszaml+=(15*60)-(lora*60+lperc);

    cout<<beazon<<" "<<idoszaml<<" "<<(kibeseged2?"A végén bent volt":"A végén nem volt bent")<<endl;





    return 0;
}
