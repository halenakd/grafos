#include "grafo_dirigido.h"


GrafoDirigido::GrafoDirigido():
    Grafo()
{

}


GrafoDirigido::~GrafoDirigido()
{
    
}


void GrafoDirigido::insereAresta(string a_id, string vs_id, string ve_id)
{
    ArestaDirigida * ai = new ArestaDirigida(a_id, vs_id, ve_id);
    arestas_grafo.push_back(ai);

    Vertice * vs, * ve;

    for(Vertice * v: vertices_grafo)
    {
        if(v->id == vs_id)
        {
            vs = v;
        }
        if(v->id == ve_id)
        {
            ve = v;
        }
    }

    vs->map_vs[ve->id].push_back(a_id);
    ve->map_ve[vs->id].push_back(a_id);
}


void GrafoDirigido::imprimir()
{
    for(Vertice * v: vertices_grafo) 
    {
        printf("\n");

        cout << "-----Vertice " << v->id << "-----" << "\n";
        
        for(auto &itr: v->map_vs)
        {
            for(string s: itr.second) 
            {
                cout<< v->id << " -" << s << "-> " << itr.first <<endl;
            }
        }

        for(auto &itr: v->map_ve)
        {
            for(string s: itr.second) 
            {
                cout<< v->id << " <-" << s << "- " << itr.first <<endl;
            }
        }
    }
}


int GrafoDirigido::tamanho()
{
    return arestas_grafo.size();
}


vector <ArestaDirigida*> GrafoDirigido::arestas()
{
    return arestas_grafo;
}


void GrafoDirigido::removeAresta(string a_id)
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
        for(auto & itr: v->map_ve) 
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
    for(ArestaDirigida * a: arestas_grafo)
    {
        if(a->id == a_id)
        {
            arestas_grafo.erase(remove(arestas_grafo.begin(), arestas_grafo.end(), a), arestas_grafo.end());
            free(a);
        }
    }
}


void GrafoDirigido::removeVertice(string v_id)
{
    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id)
        {
            if(v->map_ve.empty())
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
                for(auto & itr: v->map_ve) 
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
vector <ArestaDirigida*> GrafoDirigido::getAresta(string vs_id, string ve_id)
{
    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == vs_id) 
        {
            for(auto &itr: v->map_vs) 
            {
                if(itr.first == ve_id) 
                {
                    vector<ArestaDirigida*> arestas;
                    for(ArestaDirigida * a: arestas_grafo)
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
    return vector<ArestaDirigida*>();
}


int GrafoDirigido::grauSaida(string v_id)
{
    int grau = 0;

    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id) 
        {
            for(auto &itr: v->map_vs) 
            {
                grau++;
            }
        }
    }
    return grau;
}


int GrafoDirigido::grauEntrada(string v_id)
{
    int grau = 0;

    for(Vertice * v: vertices_grafo) 
    {
        if(v->id == v_id) 
        {
            for(auto &itr: v->map_ve) 
            {
                grau++;
            }
        }
    }
    return grau;
}


vector<string> GrafoDirigido::verticesAresta(string a_id)
{
    vector <string> verticesPar;
    for(ArestaDirigida * a: arestas_grafo)
    {
        ArestaDirigida * ai;

        if(a->id == a_id)
        {
            ai = a;

            verticesPar.push_back(ai->vs_id);
            verticesPar.push_back(ai->ve_id);
        }
    }
    return verticesPar;
}


string GrafoDirigido::oposto(string v_id, string a_id)
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
                for(auto &itr: v->map_ve) 
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
    }
    return nullptr;
}


vector<ArestaDirigida*> GrafoDirigido::arestasSaida(string v_id)
{
    vector<ArestaDirigida*> arestas;

    for(Vertice * v: vertices_grafo)
    {
        if(v->id == v_id)
        {
            for(auto &itr: v->map_vs)
            {
                for(string s: itr.second)
                {
                    for(ArestaDirigida * a: arestas_grafo)
                    {
                        if(a->id == s)
                        {
                            arestas.push_back(a);
                        }
                    }
                }
            }
        }
    }
    return arestas;
}


vector <ArestaDirigida*> GrafoDirigido::arestasEntrada(string v_id)
{
    vector<ArestaDirigida*> arestas;

    for(Vertice * v: vertices_grafo)
    {
        if(v->id == v_id)
        {
            for(auto &itr: v->map_ve)
            {
                for(string s: itr.second)
                {
                    for(ArestaDirigida * a: arestas_grafo)
                    {
                        if(a->id == s)
                        {
                            arestas.push_back(a);
                        }
                    }
                }
            }
        }
    }
    return arestas;
}