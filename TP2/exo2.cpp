struct t_tabDyn{
    int capa;
    int occup;
    int* tabint;
};

void insere_fin(t_tabDyn *tab, int e){
    if(tab->occup < tab->capa){
    
        tab->tabint[(tab->occup)+1] = e;
        
    } else {

        t_tabDyn *newtab;
        newtab->capa = (tab->capa)*2;
        newtab->occup = 0;

        for(int i = 0; i < tab->occup; i++){
            newtab->tabint[i] = tab->tabint[i];
            newtab->occup = newtab->occup++;
        }
        newtab->tabint[(newtab->occup)+1] = e;

        delete[] tab->tabint;
        tab->tabint = newtab->tabint;
        tab->capa = newtab->capa;
        tab->occup = newtab->occup;
    }
}
int main() {} 