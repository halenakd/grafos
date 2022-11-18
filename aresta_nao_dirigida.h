#ifndef __ARESTA_NAO_DIRIGIDA_H__
#define __ARESTA_NAO_DIRIGIDA_H__

#include "vertice.h"

class ArestaNaoDirigida
{
    public:
        string id; // para identificar a aresta
        string vi_id, vj_id; // vertices que a aresta liga
        
        /* construtores e destrutores */
        ArestaNaoDirigida();
        ArestaNaoDirigida(string id, string vi_id, string vj_id);
        ~ArestaNaoDirigida();
};

#endif // __ARESTA_NAO_DIRIGIDA_H__