#include "graph.h"// 请不要删除，否则检查不通过
#include <stdio.h>

bool matrix_insert_vertex(MatrixGraph *G, VertexType v) {
    if (matrix_locate_vertex(G, v) != -1 || G->vexnum + 1 >= MAX_VERTEX_NUM) {
        return false;
    }
    G->vertex[G->vexnum] = v;
    G->vexnum++;
    for (int i = 0; i < G->vexnum; ++i) {
        G->arcs[i][G->vexnum - 1] = 0;
        G->arcs[G->vexnum - 1][i] = 0;
    }
    return true;
}

bool matrix_insert_arc(MatrixGraph *G, VertexType v, VertexType w) {
    if (matrix_locate_vertex(G, v) == -1 || matrix_locate_vertex(G, w) == -1 || G->arcnum + 1 >= MAX_VERTEX_NUM) {
        return false;
    }
    if(G->type == DG){
        if(G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] == 1){
            return false;
        }
        G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] = 1;
        G->arcnum++;
    }
    if (G->type == UDG){
        if(G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] == 1){
            return false;
        }
        G->arcs[matrix_locate_vertex(G, v)][matrix_locate_vertex(G, w)] = 1;
        G->arcs[matrix_locate_vertex(G, w)][matrix_locate_vertex(G, v)] = 1;
        G->arcnum++;
    }
    return true;
}