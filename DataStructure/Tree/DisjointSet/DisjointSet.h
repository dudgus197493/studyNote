// �и� ����
// �и� ������ ���� �Ǵ� ��ü�� ��� ���տ� �ҼӵǾ� �ִ°�? ��� ������ �������� �ϴ� �˰���
// �� ��������ó�� � �� ���Ұ� �ҼӵǾ� �ִ� ������ �˾Ƴ��� ���� ���� Ž���̶�� ��
// ��Ʈ ���� ���� �� ��ü�̰�, ��Ʈ ��� �ڽ��� ������ Ʈ�� ���� ��� ������ �� ���տ� �Ҽӵȴ�.
// �и������� ������ ���Ұ� ��� ���տ� �ͼӵǾ� �ִ����� ���� �˾Ƴ� �� �ֵ��� �ϴ� ��.

// ������
// �� ������ ���ϴ� ��. �и�����a, b�� �ִٸ� b�� �ֻ��� ����� �θ�� a�� �����ϸ� ��.

// ���� Ž��
// ���Ҹ� ã�� ���� �ƴ϶�. ���Ұ� ���� �ִ� ������ ã�� ��.
// ���Ұ� �����ִ� Ʈ���� ��Ʈ ��带 �˸� ��.

#include<stdio.h>
#include<stdlib.h>

typedef struct _tagDisjointSet {
	struct _tagDisjointSet* parent;
	void* Data;
} DisjointSet;

// �� ����
void UnionSet(DisjointSet* _pSet1, DisjointSet* _pSet2);

// ���� Ž��
DisjointSet* FindSet(DisjointSet* _pNode);

// ������
DisjointSet* createNode(void* _Data);
// ���Ҹ�
void destroyNode(DisjointSet* _remove);