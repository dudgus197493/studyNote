// 그래프
// 1. 그래프의 정의
// 그래프는 '정점의 모음'과 이 정점을 잇는 '간선의 모음'과의 결합이다.
// ㄴ> "정점의 집합을 V, 간선의 집합을 E, 그리고 그래프를 G라고 했을 때, G = (V, E)이다."
// 인접(adjacent)관계 : 간선으로 연결되어 있는 두 정점의 관계
// 경로(Path) : 정점과 정점사이의 간선의 수(길이)
// 사이클(Cycle) : 어느 경로가 정점 하나를 두 번 이상 거치는 경로
//	1) 방향성 그래프
//		- 간선이 방향성을 가짐
//	2) 무방향성 그래프
//		- 간선에 방향성이 없음
//		- 연결성(Connectivity) : 무방향성 그래프 내의 두 정점 사이에 경로(Path)가 존재하면 "이 두 정점이 연결되어 있다"고 함
//								 또 그래프 내의 각 정점들이 다른 모든 정점들과 연결되어 있으면 "이 그래프는 연결되었다"라고 함

// 2. 그래프의 표현 방식
// 그래프의 표현은 "간선, 즉 정점과 정점의 인접 관계를 어떻게 나타내는가?"의 문제로 귀결.
//	1) 인접 행렬(Adjacency Matrix) - 정점끼리의 인접 관계를 나타내는 행렬.
//		- 그래프의 정점의 수를 N, NxN크기의 행렬을 만들어 행렬의 각 원소를 한 정점과 또 다른 정점이 인접해 있는 경우(정점 사이 간선이 존재한느 경우)
//		1로 표시, 인접해 있지 않은 경우 0으로 표시
//		- 무방향성인 경우에는 인접행렬의 주 대각성에 대해 대칭을 이루는 것이 특징
//		- 구조가 간단하지만 메모리효율이 좋지 않다
//		- 그래프 내의 정점의 수가 많지 않거나 정점끼리의 인접 여부를 빠르게 알아내야 한다면 사용	
//	2) 인접 리스트(Adjacency List)
//		- 구조가 복잡하지만 메모리효율이 좋다.
//		- 정점과 간선의 입력이 빈번하게 이루어지고 메모리 효율성을 우선시 해야 한다면 사용

// 인접리스트의 구현
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