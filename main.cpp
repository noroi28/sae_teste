#include <string>
#include <vector>
#include <iostream>
using namespace std;


void presentation()//explication du réglement du vote
{
    cout << "Bienvenue au scrutin de vote n°42 pour l'élection présidentielle"<<"\n"

         << "Voici les règles : - Vous devez ordonnée dans une liste le nom des candidats par préférence de vote"<<"\n"
         << "                   - Plus votre candidat est haut dans la liste, plus il obtiendra de points !"<<"\n"
         << "                   - Le candidat ayant le plus de point gagne !"<<"\n"
         << "                   - vous ne pouvez pas voter 2 fois pour le même candidat !"<<"\n"
         << "Bon Vote !!!"<<endl;
}

void candidat (vector <string>& tabNomCandidat, vector <unsigned int>& tabPointCandidat){
    int nombreCandidat;
    cout << "Veuillez saisir le nombre de candidat :";
    cin >> nombreCandidat;
    cout << endl;
    string nom;
    tabNomCandidat.resize(nombreCandidat);
    for(int i =0; i< nombreCandidat;i=i+1)
    {
        cout << "Veuillez saisir le nom du candidat n°"<< i+1<< endl;;
        cin >> nom;
        tabNomCandidat[i] = nom;
    }
    tabPointCandidat.resize(nombreCandidat);
    for(int i =0; i< nombreCandidat;i=i+1)
    {
        tabPointCandidat[i] = 0;
    }
}


void vote (vector <string>& tabNomCandidat, vector <unsigned int>& tabPointCandidat){

    for (unsigned int i = 0; i < 115; ++i) {

        for  (size_t i =0; i < tabNomCandidat.size(); i = i+1){
            cout << i+1 <<"-" << tabNomCandidat[i] <<endl;
        }

        int point = (tabNomCandidat.size()-1)*2;
        unsigned int nbTour = 1;
        vector <unsigned int> tabVérif (tabNomCandidat.size(), 0);

        while (point > 0){ // s'assurer que tout le monde vote pour 3 personne
            unsigned int n;
            cout << "il reste "<< point << "point"<<endl;
            cout <<"qu'elle glace voulez vous mettre en "<< nbTour <<" position"<<endl;
            cin >> n;

            if (n < 1 || n > tabNomCandidat.size()){ // cette partie nous permet de s'assurer que la valeur correspond a un des candidats
                cout << "erreur il semble que la valeur rentrée n'est pas valide"<<endl;

                continue;
            }

            else { // cette parti permet que 1 candidat ne soit pas voter 2 fois
                for (size_t i =0; i < tabVérif.size(); i = i+1){
                    if (tabVérif[i] == n){
                        cout << "erreur vous avez déjà votez pour cette glace."<<endl;
                        nbTour = nbTour -1;
                        tabPointCandidat[n-1] = tabPointCandidat[n-1] - (4-nbTour);
                        point = point + (tabNomCandidat.size() - nbTour);

                    }
                }
                tabPointCandidat[n-1] = tabPointCandidat[n-1] + (4-nbTour);
                tabVérif[nbTour-1] = n;
                point = point - (tabNomCandidat.size() - nbTour);
                nbTour = nbTour +1;
            }
        }
    }
}


void resulta (vector <string>& tabNomCandidat, vector <unsigned int>& tabPointCandidat){
    unsigned int point = 0;
    string gagnant;
    for (unsigned int j =0; j < tabPointCandidat.size(); ++j){ //on compare tout les résulta ensmeble pour trouver le gagnant
        if(tabPointCandidat[j] > point) {
            point = tabPointCandidat[j];
            gagnant = tabNomCandidat[j];
        }
    }
    cout << "voici le resulta :" << endl;
    for (size_t i =0; i < tabNomCandidat.size(); i = i+1){
        cout << tabNomCandidat[i] <<" : "<< tabPointCandidat[i] <<endl;
    }
    cout <<"le gagnant est : " << gagnant<< ", avec : " <<point<< " point." <<endl;
}


int main (){
    std::vector<std::string> tabNomCandidat;
    vector <unsigned int> tabPoinCandidat;

    presentation();
    candidat(tabNomCandidat, tabPoinCandidat);
    vote(tabNomCandidat, tabPoinCandidat);
    resulta(tabNomCandidat, tabPoinCandidat);
}
