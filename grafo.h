#ifndef __GRAFO_H__
#define __GRAFO_H__

#include "vertice.h"


typedef struct bloco {
    string dado;
    struct bloco *prox;
} lista, bloco;


class Grafo
{
    public:
        vector<Vertice*> vertices_grafo; // guarda os vertices do grafo

        // construtores e destrutores 
        Grafo();
        ~Grafo();

        // funcoes de vertice
        void insereVertice(string v_id); // instancia e insere um vertice v no grafo
        Vertice * getVertice(string v_id); // retorna um vertice v partir do id dele
        int ordem(); //retorna quantidade de vértices
        vector<Vertice*> vertices(); // iteracao dos vertices
        vector<string> adjacente(string v_id); // iteracao dos vertices adjacentes ao vertice v


        // funcoes de busca
        lista * Q;
        int listaVazia();
        void Insere(string v_id);
        string Remove();
        void ImprimeCaminho(Grafo G, string s_id, string v_id);
        void BFS(string v_id); // busca em largura
};

#endif // __GRAFO_H__