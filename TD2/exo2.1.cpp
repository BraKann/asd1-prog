struct t_tabDyn {
    int capa;
    int occp;
    double* tabptr;
};

int main() {
   
    t_tabDyn* tab;
    tab->capa = 10;
    tab->occp = 0;
    tab->tabptr = new double[tab->capa];

}

void inserer_fin(t_tabDyn* tab, double e){
    if(tab->occp < tab->capa){tab->tabptr[tab->occp+1] = e;}
}

