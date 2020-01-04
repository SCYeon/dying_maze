//DFSMatrix.h

#ifndef DFSMATRIX_H
#define DFSMATRIX_H
#define MAX_STACK_SIZE 100

class DFSMatrix{

protected:
   int m, n; //dfs_map�� ���� ����
   int** dfs_map; //input �޾ƿ��� �̷� matrix
    
public:      
   struct XY{
       int a;
       int b;
    }; //������ ��� (a, b) �����ϴ� ����ü
    struct XY stPath[MAX_STACK_SIZE]; //�ִܰ�� (a, b) ����� ����ü(historyXY)�� �迭(stPath)
    int q; //�ִܰ�� (a, b) ����� ����ü(historyXY) �迭(stPath)�� index
    DFSMatrix();
    ~DFSMatrix();
    void setDFSMatrix();
    void dfs(int tr, int tc, int d);
};

#endif
