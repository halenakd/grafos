#ifndef __GRAFO_DIRIGIDO_H__
#define __GRAFO_DIRIGIDO_H__

#include "grafo.h"
#include "aresta_dirigida.h"

class GrafoDirigido: public Grafo
{
    public:
        vector<ArestaDirigida*> arestas_grafo; // guarda as arestas do grafo
 
        // construtores e destrutores 
        GrafoDirigido();
        ~GrafoDirigido();

        // funcoes
        void imprimir();

        // funcoes de vertice
        void removeVertice(string v_id); // remove vertice
        int grauSaida(string v_id); // grau de saida do vertice v
        int grauEntrada(string v_id); // grau de entrada do vertice v
        vector<string> verticesAresta(string a_id); // par de vertices conectados a aresta
        string oposto(string v_id, string a_id); // vertice incidente a aresta incidente ao vertice v

        // funcoes de aresta
        void insereAresta(string a_id, string vs_id, string ve_id); // instancia aresta entre os vertices i e j e adiciona ao grafo
        void removeAresta(string a_id); // remove aresta
        int tamanho(); //retorna quantidade de arestas
        vector<ArestaDirigida*> arestas(); // iteracao das arestas do grafo
        vector<ArestaDirigida*> getAresta(string vs_id, string ve_id); // referencia para aresta(s) de i a j, j a i ou null
        vector<ArestaDirigida*> arestasSaida(string v_id); // iteracao das arestas de saida do vertice
        vector<ArestaDirigida*> arestasEntrada(string v_id); // iteracao das arestas de entrada do vertice

};

#endif // __GRAFO_DIRIGIDO_H__