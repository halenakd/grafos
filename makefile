all: vertice.o aresta_dirigida.o aresta_nao_dirigida.o grafo.o grafo_nao_dirigido.o grafo_dirigido.o

	$(CXX) main.cpp vertice.o aresta_dirigida.o aresta_nao_dirigida.o grafo.o grafo_nao_dirigido.o grafo_dirigido.o


%.o: %/%.cpp %/%.h
	$(CXX) -c %/%.cpp

clean:
	rm *.o
	rm a.out