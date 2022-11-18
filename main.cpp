#include "grafo_nao_dirigido.h"
#include "grafo_dirigido.h"


// FUNCOES PARA IMPRIMIR VETORES

void imprimirVectorS(vector<string> v);
void imprimirVectorA(vector<ArestaNaoDirigida*> v);
void imprimirVectorA(vector<ArestaDirigida*> v);
void imprimirVectorV(vector<Vertice*> v);

// TESTES

int main(int argc, char* argv[])
{
    printf("\n---------TESTE GRAFOS---------\n");


    printf("\n---------TESTE GRAFO NAO DIRIGIDO---------\n");


    // Criando e instanciando grafo nao dirigido
    GrafoNaoDirigido * grafoND = new GrafoNaoDirigido();


    // Inserindo vertices no grafo
    grafoND->insereVertice("v1");
    grafoND->insereVertice("v2");
    grafoND->insereVertice("v3");
    grafoND->insereVertice("v4");
    grafoND->insereVertice("v5");
    grafoND->insereVertice("v6");


    // Inserindo arestas no grafo
    grafoND->insereAresta("a1", "v1", "v2");
    grafoND->insereAresta("a2", "v3", "v4");
    grafoND->insereAresta("a3", "v1", "v5");
    grafoND->insereAresta("a4", "v1", "v1");


    // Imprimindo o grafo
    grafoND->imprimir();


    // Imprimindo a ordem(qntd vertices) do grafo
    printf("\nOrdem do grafo:\n");
    printf("%i\n", grafoND->ordem());


    // Imprimindo o tamanho(qntd arestas) do grafo
    printf("\nTamanho do grafo:\n");
    printf("%i\n", grafoND->tamanho());


    // Imprimindo iteracao dos vertices do grafo
    vector <Vertice*> verticesGND = grafoND->vertices();
    printf("\nIteracao de vertices do grafo: \n");
    imprimirVectorV(verticesGND);


    // Imprimindo iteracao das arestas do grafo
    vector <ArestaNaoDirigida*> arestasGND = grafoND->arestas();
    printf("\nIteracao de arestas do grafo: \n");
    imprimirVectorA(arestasGND);


    // Imprimindo iteracao de vertices adjacentes de um vertice do grafo
    vector <string> verticesAdjGND = grafoND->adjacente("v1");
    printf("\nIteracao dos vertices adjacentes do vertice 1 do grafo: \n");
    imprimirVectorS(verticesAdjGND);


    // Imprimindo aresta entre dois vertices do grafo
    printf("\nAresta entre os vertices 1 e 2 do grafo: \n");
    vector<ArestaNaoDirigida*> aND = grafoND->getAresta("v1", "v2");
    imprimirVectorA(aND);


    // Imprimindo o grau de um vertice do grafo
    printf("\nGrau do vertice 1 do grafo:\n");
    printf("%i\n", grafoND->grau("v1"));


    // Imprimindo par de vertices de uma aresta do grafo
    vector <string> verticesParGND = grafoND->verticesAresta("a1");
    printf("\nPar de vertices da aresta 1 do grafo: \n");
    imprimirVectorS(verticesParGND);


    // Imprimindo vertice oposto de outro vertice por uma aresta do grafo
    printf("\nVertice adjacente do vertice 1 pela aresta 1 do grafo: \n");
    printf("%s\n", grafoND->oposto("v1", "a1").c_str());


    /*// Removendo arestas e vertices do grafo
    printf("\nRemoção da aresta a3 e do vertice v2 do grafo \n");
    // Removendo aresta do grafo
    grafoND->removeAresta("a3");
    // Removendo vertice do grafo
    grafoND->removeVertice("v2");

    grafoND->imprimir();*/


/* ---------------------------------------------------------------------------------------------------------------- */


    printf("\n---------TESTE GRAFO DIRIGIDO---------\n");


    // Criando e instanciando grafo dirigido
    GrafoDirigido * grafoD = new GrafoDirigido();


    // Inserindo vertices no grafo
    grafoD->insereVertice("v1");
    grafoD->insereVertice("v2");
    grafoD->insereVertice("v3");
    grafoD->insereVertice("v4");
    grafoD->insereVertice("v5");
    grafoD->insereVertice("v6");


    // Inserindo arestas no grafo
    grafoD->insereAresta("a1", "v1", "v2");
    grafoD->insereAresta("a2", "v3", "v4");
    grafoD->insereAresta("a3", "v1", "v5");
    grafoD->insereAresta("a4", "v1", "v1");


    // Imprimindo o grafo
    grafoD->imprimir();


    // Imprimindo a ordem(qntd vertices) do grafo
    printf("\nOrdem do grafo:\n");
    printf("%i\n", grafoD->ordem());


    // Imprimindo o tamanho(qntd arestas) do grafo
    printf("\nTamanho do grafo:\n");
    printf("%i\n", grafoD->tamanho());


    // Imprimindo iteracao dos vertices do grafo
    vector <Vertice*> verticesGD = grafoD->vertices();
    printf("\nIteracao de vertices do grafo: \n");
    imprimirVectorV(verticesGD);


    // Imprimindo iteracao das arestas do grafo
    vector <ArestaDirigida*> arestasGD = grafoD->arestas();
    printf("\nIteracao de arestas do grafo: \n");
    imprimirVectorA(arestasGD);


    // Imprimindo iteracao de vertices adjacentes de um vertice do grafo
    vector <string> verticesAdjGD = grafoD->adjacente("v1");
    printf("\nIteracao dos vertices adjacentes do vertice 1 do grafo: \n");
    imprimirVectorS(verticesAdjGD);


    // Imprimindo aresta entre dois vertices do grafo
    printf("\nAresta entre os vertices 1(saida) e 2(entrada) do grafo: \n");
    vector<ArestaDirigida*> aD = grafoD->getAresta("v1", "v2");
    imprimirVectorA(aD);


    // Imprimindo o grau de saida de um vertice do grafo
    printf("\nGrau de saida do vertice 1 do grafo:\n");
    printf("%i\n", grafoD->grauSaida("v1"));


    // Imprimindo o grau de entrada de um vertice do grafo
    printf("\nGrau de entrada do vertice 1 do grafo:\n");
    printf("%i\n", grafoD->grauEntrada("v1"));


    // Imprimindo par de vertices de uma aresta do grafo
    vector <string> verticesParGD = grafoD->verticesAresta("a1");
    printf("\nPar de vertices da aresta 1 do grafo: \n");
    imprimirVectorS(verticesParGD);


    // Imprimindo vertice oposto de outro vertice por uma aresta do grafo
    printf("\nVertice oposto do vertice 1 pela aresta 1 do grafo: \n");
    printf("%s\n", grafoD->oposto("v1", "a1").c_str());


    // Imprimindo iteracao das arestas de saida de um vertice do grafo
    vector <ArestaDirigida*> arestasS = grafoD->arestasSaida("v1");
    printf("\nIteracao de arestas de saida do vertice 1 do grafo: \n");
    imprimirVectorA(arestasS);


    // Imprimindo iteracao das arestas de entrada de um vertice do grafo
    vector <ArestaDirigida*> arestasE = grafoD->arestasEntrada("v1");
    printf("\nIteracao de arestas de entrada do vertice 1 grafo: \n");
    imprimirVectorA(arestasE);


    // Removendo arestas e vertices do grafo
    printf("\nRemoção da aresta a3 e do vertice v2 do grafo \n");
    // Removendo aresta do grafo
    grafoD->removeAresta("a3");
    // Removendo vertice do grafo
    grafoD->removeVertice("v2");

    grafoD->imprimir();


/* ---------------------------------------------------------------------------------------------------------------- */


    printf("\n---------TESTE BUSCAS---------\n");


    grafoND->BFS("v1");

    return 0;
}

// FUNCOES PARA IMPRIMIR VETORES

void imprimirVectorS(vector<string> v)
{
    for(int i = 0; i < v.size()-1; i++)
    {
        printf("%s, ", v[i].c_str());
    }

    printf("%s \n", v[v.size()-1].c_str());
}

void imprimirVectorA(vector<ArestaNaoDirigida*> v)
{
    for(int i = 0; i < v.size()-1; i++)
    {
        printf("%s, ", v[i]->id.c_str());
    }

    printf("%s \n", v[v.size()-1]->id.c_str());
}

void imprimirVectorA(vector<ArestaDirigida*> v)
{
    for(int i = 0; i < v.size()-1; i++)
    {
        printf("%s, ", v[i]->id.c_str());
    }

    printf("%s \n", v[v.size()-1]->id.c_str());
}

void imprimirVectorV(vector<Vertice*> v)
{
    for(int i = 0; i < v.size()-1; i++)
    {
        printf("%s, ", v[i]->id.c_str());
    }

    printf("%s \n", v[v.size()-1]->id.c_str());
}