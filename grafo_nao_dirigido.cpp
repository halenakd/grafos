#include "grafo_nao_dirigido.h"


GrafoNaoDirigido::GrafoNaoDirigido():
    Grafo()
{

}


GrafoNaoDirigido::~GrafoNaoDirigido()
{
    
}


void GrafoNaoDirigido::insereAresta(string a_id, string vi_id, string vj_id)
{
    ArestaNaoDirigida * ai = new ArestaNaoDirigida(a_id, vi_id, vj_id);
    arestas_grafo.push_back(ai);

    Vertice * vi, * vj;

    for(Vertice * v: vertices_grafo)
    {
        if(v->id == vi_id)
        {
            vi = v;
        }
        if(v->id == vj_id)
        {
            vj = v;
        }
    }

    vi->map_vs[vj->id].push_back(a_id);
    if(vi_id != vj_id) // para caso seja um laço
    {
        vj->map_vs[vi->id].push_back(a_id);
    }
}


void GrafoNaoDirigido::imprimir()
{
    for(Vertice * v: vertices_grafo) 
    {
        printf("\n\n");

        cout << "-----Vertice " << v->id << "-----" << "\n";

        for(auto &itr: v->map_vs)
        {
            for(string s: itr.second) 
            {
                cout << v->id << " --" << s << "-- " << itr.first <<endl;
            }
        }
    }
}


int GrafoNaoDirigido::tamanho()
{
    return arestas_grafo.size();
}


vector <ArestaNaoDirigida*> GrafoNaoDirigido::arestas()
{
    return arestas_grafo;
}


void GrafoNaoDirigido::removeAresta(string a_id)
{
    // remove a aresta entre u e v
    // acha u, entra no seu mapa e acha a aresta
    // remove a aresta da lista de arestas(value) associada ao vertice v(key)
    for(Vertice * v: vertices_grafo) 
    {
        for(auto & itr: v->map_vs) 
        {
            for(string s: itr.second) 
            {
                if(s == a_id) 
                {
                    itr.second.erase(remove(itr.second.begin(), itr.second.end(), a_id), itr.second.end());
                    break;
                }
            }
        }
    }
    // remove a aresta da lista de arestas do grafo
    for(ArestaNaoDirigida * a: arestas_grafo)
    {
        if(a->id == a_id)
        {
            arestas_grafo.erase(remove(arestas_grafo.begin(), arestas_grafo.end(), a), arestas_grafo.end());
            free(a);
        }
    }
}


void GrafoNaoDirigido::removeVertice(string v_id)
{
    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id)
        {
            if(v->map_vs.empty())
            {
                vertices_grafo.erase(remove(vertices_grafo.begin(), vertices_grafo.end(), v), vertices_grafo.end());
            }
            else 
            {
                for(auto & itr: v->map_vs) 
                {
                    for(string s: itr.second) 
                    {
                        removeAresta(s);
                    }
                }
                vertices_grafo.erase(remove(vertices_grafo.begin(), vertices_grafo.end(), v), vertices_grafo.end());
            }
        }
    }
}


// ver se poderia pegar a aresta direto do vector arestas_grafo, comparando os dois vertices com os vertices dela
vector <ArestaNaoDirigida*> GrafoNaoDirigido::getAresta(string vi_id, string vj_id)
{
    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == vi_id) 
        {
            for(auto &itr: v->map_vs) 
            {
                if(itr.first == vj_id) 
                {
                    vector<ArestaNaoDirigida*> arestas;
                    for(ArestaNaoDirigida * a: arestas_grafo)
                    {
                        for(string s: itr.second)
                        {
                            if(a->id == s)
                            {
                                arestas.push_back(a);
                            }
                        }
                        return arestas;
                    }
                }
            }
        }
    }
    return vector<ArestaNaoDirigida*>();
}


int GrafoNaoDirigido::grau(string v_id)
{
    int grau = 0;
    
    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id) 
        {
            for(auto &itr: v->map_vs) 
            {
                grau++;

                // se for um laco 
                if(itr.first == v_id) 
                {
                    grau++;
                }
            }
        }
    }
    return grau;
}


vector<string> GrafoNaoDirigido::verticesAresta(string a_id)
{
    vector <string> verticesPar;
    for(ArestaNaoDirigida * a: arestas_grafo)
    {
        ArestaNaoDirigida * ai;

        if(a->id == a_id)
        {
            ai = a;

            verticesPar.push_back(ai->vi_id);
            verticesPar.push_back(ai->vj_id);
        }
    }
    return verticesPar;
}


string GrafoNaoDirigido::oposto(string v_id, string a_id)
{
    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id) 
        {
            for(auto &itr: v->map_vs) 
            {
                for(string s: itr.second) 
                {
                    if(s == a_id) 
                    {
                        return itr.first;
                    }
                }
            }
        }
    }
    return nullptr;
}