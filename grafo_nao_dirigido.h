#ifndef __GRAFO_NAO_DIRIGIDO_H__
#define __GRAFO_NAO_DIRIGIDO_H__

#include "grafo.h"
#include "aresta_nao_dirigida.h"

class GrafoNaoDirigido: public Grafo
{
    public:
        vector<ArestaNaoDirigida*> arestas_grafo; // guarda as arestas do grafo

        // construtores e destrutores 
        GrafoNaoDirigido();
        ~GrafoNaoDirigido();

        // funcoes
        void imprimir();

        // funcoes de vertice
        void removeVertice(string v_id); // remove vertice
        int grau(string v_id); // grau do vertice v
        vector<string> verticesAresta(string a_id); // par de vertices conectados a aresta
        string oposto(string v_id, string a_id); // vertice incidente a aresta incidente ao vertice v

        // funcoes de aresta
        void insereAresta(string a_id, string vi_id, string vj_id); // instancia aresta entre os vertices i e j e adiciona ao grafo
        void removeAresta(string a_id); // remove aresta
        int tamanho(); //retorna quantidade de arestas
        vector<ArestaNaoDirigida*> arestas(); // iteracao das arestas
        vector<ArestaNaoDirigida*> getAresta(string vi_id, string vj_id); // referencia para aresta(s) de i a j, j a i ou null
};

#endif // __GRAFO_NAO_DIRIGIDO_H__