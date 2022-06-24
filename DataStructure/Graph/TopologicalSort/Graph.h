#include<stdio.h>
#include<stdlib.h>

typedef int ElementType;

enum VisitMode {Visited, NotVisited};

typedef struct _tagVertex {
	ElementType data;
	int visited;
	int index;

	struct _tagVertex* next;
	struct _tagEdge* adgacenctList;
} Vertex;

typedef struct _tagGraph {
	Vertex* vertices;
	int vertexCount;
} Graph;

typedef struct _tagEdge {
	Vertex* from;
	Vertex* target;
	int weight;
	struct _tagEdge* next;
} Edge;

// 그래프 생성
Graph* createGraph();
// 그래프 소멸
void destroyGraph(Graph* _pGraph);

// 정점 생성
Vertex* createVertex(ElementType _data);
// 정점 소멸
void destroyVertex(Vertex* _pVertex);

// 간선 생성
Edge* createEdge(Vertex* _from, Vertex* _target, int _weight);
// 간선 소멸
void destroyEdge(Edge* _pRemove);

// 정점 추가
void addVertex(Graph* _pGraph, Vertex* _pNewVertex);
// 간선 추가
void addEdge(Vertex* _pVertex, Edge* _pNewEdge);

// 그래프 출력
void printGraph(Graph* _pGraph);