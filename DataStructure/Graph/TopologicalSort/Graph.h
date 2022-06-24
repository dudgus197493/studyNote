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

// �׷��� ����
Graph* createGraph();
// �׷��� �Ҹ�
void destroyGraph(Graph* _pGraph);

// ���� ����
Vertex* createVertex(ElementType _data);
// ���� �Ҹ�
void destroyVertex(Vertex* _pVertex);

// ���� ����
Edge* createEdge(Vertex* _from, Vertex* _target, int _weight);
// ���� �Ҹ�
void destroyEdge(Edge* _pRemove);

// ���� �߰�
void addVertex(Graph* _pGraph, Vertex* _pNewVertex);
// ���� �߰�
void addEdge(Vertex* _pVertex, Edge* _pNewEdge);

// �׷��� ���
void printGraph(Graph* _pGraph);