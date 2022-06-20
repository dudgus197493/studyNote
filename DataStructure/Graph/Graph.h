// �׷���
// 1. �׷����� ����
// �׷����� '������ ����'�� �� ������ �մ� '������ ����'���� �����̴�.
// ��> "������ ������ V, ������ ������ E, �׸��� �׷����� G��� ���� ��, G = (V, E)�̴�."
// ����(adjacent)���� : �������� ����Ǿ� �ִ� �� ������ ����
// ���(Path) : ������ ���������� ������ ��(����)
// ����Ŭ(Cycle) : ��� ��ΰ� ���� �ϳ��� �� �� �̻� ��ġ�� ���
//	1) ���⼺ �׷���
//		- ������ ���⼺�� ����
//	2) �����⼺ �׷���
//		- ������ ���⼺�� ����
//		- ���Ἲ(Connectivity) : �����⼺ �׷��� ���� �� ���� ���̿� ���(Path)�� �����ϸ� "�� �� ������ ����Ǿ� �ִ�"�� ��
//								 �� �׷��� ���� �� �������� �ٸ� ��� ������� ����Ǿ� ������ "�� �׷����� ����Ǿ���"��� ��

// 2. �׷����� ǥ�� ���
// �׷����� ǥ���� "����, �� ������ ������ ���� ���踦 ��� ��Ÿ���°�?"�� ������ �Ͱ�.
//	1) ���� ���(Adjacency Matrix) - ���������� ���� ���踦 ��Ÿ���� ���.
//		- �׷����� ������ ���� N, NxNũ���� ����� ����� ����� �� ���Ҹ� �� ������ �� �ٸ� ������ ������ �ִ� ���(���� ���� ������ �����Ѵ� ���)
//		1�� ǥ��, ������ ���� ���� ��� 0���� ǥ��
//		- �����⼺�� ��쿡�� ��������� �� �밢���� ���� ��Ī�� �̷�� ���� Ư¡
//		- ������ ���������� �޸�ȿ���� ���� �ʴ�
//		- �׷��� ���� ������ ���� ���� �ʰų� ���������� ���� ���θ� ������ �˾Ƴ��� �Ѵٸ� ���	
//	2) ���� ����Ʈ(Adjacency List)
//		- ������ ���������� �޸�ȿ���� ����.
//		- ������ ������ �Է��� ����ϰ� �̷������ �޸� ȿ������ �켱�� �ؾ� �Ѵٸ� ���

// ��������Ʈ�� ����
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