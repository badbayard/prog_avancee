#include <iostream>

using namespace std;

class String{
    public:
        string tab;
        char b;

        String(string _tab){
            tab = _tab;
        }
        String(char a){
            b = a;
        }
        void getString(){
            //printf("%s",tab);
            cout<<tab<<endl;
        }
        void convert(char b){
            tab = b;
        }
        string concat(string f){
            return tab = tab + f;
        }
        int chlongueur (string mot){
            int i;
             i=0;
            while (mot[i]!='\0')
            {
                i++;
            }
            return i;
        }
        
        bool compare(string f){
            int lg1 = chlongueur(tab);
            int lg2 = chlongueur(f);

            for(int i = 0 ; i < lg1 ; i++){
                if(tab[i] != f[i] ){
                    return false;
                }
            }
            return true;
        }
        
};

class String2{
    public:
        char * tab;
        String2();
        String2(const char* tab2=""): tab(tab){
            int len = chlongueur(tab2);
            tab = new char[len];
            for(int i = 0 ; i < len ;i++){
                tab[i]=tab2[i];
            }
        }
        String2(const char c){}
        int chlongueur (const char* tab1){
            int i;
             i=0;
            while (tab1[i]!='\0')
            {
                i++;
            }
            return i;
        }

        const char* strcpy(){
            int len = chlongueur(tab);
            char tab2[len+1];
            for(int i = 0 ; i < len ; i++){
                tab2[i] = tab[i];
            }
            tab2[len]='\0';
            return tab2;
        }
        String2(const String2&){}
        ~String2(){}

};


int main(){
   // String2 essai1;
    String2 essai2("yolo");
    //cout<<essai2.chlongueur();
    /*
    string a;
    cout<<"mettre un mot"<<endl;
    cin >> a;
    String essai1(a);
    String essai2('z');
    essai1.getString();
    essai2.getString();
    //essai1.concat("hello");
    cout <<"apres operation"<<endl;
    essai1.getString();
    cout <<essai1.compare("tarte")<<endl;
    */
    return 0;
}