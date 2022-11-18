#ifndef __ARESTA_DIRIGIDA_H__
#define __ARESTA_DIRIGIDA_H__

#include "vertice.h"

class ArestaDirigida
{
    public:
        string id; // para identificar a aresta
        string vs_id, ve_id; // vertices de entrada e de saida que a aresta liga

        /* construtores e destrutores */
        ArestaDirigida();
        ArestaDirigida(string id, string vs_id, string ve_id);
        ~ArestaDirigida();
};

#endif // __ARESTA_DIRIGIDA_H__