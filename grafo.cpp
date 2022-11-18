#include "grafo.h"


Grafo::Grafo()
{
    lista * Q;
    Q = NULL;
    Grafo::Q = Q;
}


Grafo::~Grafo()
{

}


void Grafo::insereVertice(string v_id)
{
    Vertice * vi = new Vertice(v_id);
    vertices_grafo.push_back(vi);
}


Vertice * Grafo::getVertice(string v_id)
{
    for(Vertice * v: vertices_grafo)
    {
        if(v->id == v_id)
        {
            return v;
        }
    }
    return nullptr;
}


int Grafo::ordem()
{
    return vertices_grafo.size();
}


vector <Vertice*> Grafo::vertices()
{
    return vertices_grafo;
}


vector <string> Grafo::adjacente(string v_id)
{
    vector <string> verticesAdj;

    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id) 
        {
            for(auto &itr: v->map_vs)
            {
                verticesAdj.push_back(itr.first);
            }
        }
    }
    return verticesAdj;
}


int Grafo::listaVazia() 
{
    return (Q == NULL);
}


void Grafo::Insere(string v_id)
{
    bloco *b = (bloco *)malloc(sizeof(bloco));
    b->dado = v_id;

    if(!listaVazia())
    {
        bloco *tmp = Q;
        b->prox = NULL;

        while (tmp->prox != NULL)
            tmp = tmp->prox;

        tmp->prox = b;
    }
    else
    {
        b->prox = Q;
        Q = b;
    }
}


string Grafo::Remove()
{
    if(!listaVazia()) 
    {
       string dado = (Q)->dado;

       bloco *tmp = Q;
       Q = (Q)->prox;
       free(tmp);

       return dado;
    }
    return nullptr;
}


void Grafo::ImprimeCaminho(Grafo G, string s_id, string v_id)
{
    if(v_id == s_id)
    {
        printf("%s", s_id.c_str());
    }
    else{
        Vertice * v = G.getVertice(v_id);

        if(v->pi == NULL)
        {
            printf("Nao existe caminho de s para v");
        }

        else
        {
            ImprimeCaminho(G, s_id, v->pi->id);
            printf("%s", v_id.c_str());
        }
    }
}


void Grafo::BFS(string s_id)
{
    Vertice * s; // v_id, vertice inicial

    for(Vertice * v: vertices_grafo)
    {
        v->cor = "BRANCO";
        v->pi = NULL;
        v->d = DBL_MAX;

        if(v->id == s_id)
        {
            s = v;
        }
    }

    s->d = 0;
    s->cor = "CINZA";

    Insere(s_id);

    while(!listaVazia())
    {
        string u_id = Remove();
        /*Vertice * u = getVertice(u_id);

        vector <string> verticesAdj = adjacente(u_id);*/

        /*for(string v_id: verticesAdj)
        {
            Vertice * v = getVertice(v_id);

            if(v->cor == "BRANCO")
            {
                //Insere(&Q, v_id);
                v->cor = "CINZA";
                v->pi = u;
                v->d = u->d + 1;
            }
        }*/
        //u->cor = "PRETO";
    }
}