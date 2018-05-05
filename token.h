typedef long int tipolista;
class Token{
    protected: 
        tipolista dato;
        Token *next;
    public:
        Token() {next=NULL;};
        Token(tipolista a) {dato=a; next=NULL;};
        void set_dato(tipolista a) {dato=a; };
        void set_next(Token *n) {next=n; };
        tipolista get_dato() {return dato; };
        Token *get_next() {return next; };
        bool es_vacio() {return next==NULL;}
};