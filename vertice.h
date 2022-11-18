#ifndef __VERTICE_H__
#define __VERTICE_H__

#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Vertice
{
    public:
        string id; // para identificar o vertice

        // mapas - mapa - chave: id de vertice adjacente, valor: lista de arestas
        // se o grafo for nao dirigido, só usará o map_vs
        // se o grafo for dirigido, usará o map_vs, vertices de saida, e o map_ve, vertices de entrada
        map <string, vector<string>> map_vs;
        map <string, vector<string>> map_ve;

        /* construtores e destrutores */
        Vertice();
        Vertice(string id);
        ~Vertice();

        /* para as buscas */
        string cor;
        Vertice * pi;
        double d;
};

#endif // __VERTICE_H__