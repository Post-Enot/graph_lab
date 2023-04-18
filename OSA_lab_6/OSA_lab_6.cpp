#include <iostream>
#include "graph.h"
#include "graph_entities.h"

using namespace std;

void print_node(graph_node<int32_t, size_t>* node)
{
	cout << "edge " << node->value() << endl;
}

void handle_edge(graph_edge<int32_t, size_t>* edge)
{}

int main()
{
	// Граф:
	graph<int32_t, size_t> graph;

	// Инициализируем узлы:
	graph_node<int32_t, size_t>* node_1 = graph.add_node(1, -1);
	graph_node<int32_t, size_t>* node_2 = graph.add_node(2, -1);
	graph_node<int32_t, size_t>* node_3 = graph.add_node(3, -1);
	graph_node<int32_t, size_t>* node_4 = graph.add_node(4, -1);
	graph_node<int32_t, size_t>* node_5 = graph.add_node(5, -1);
	graph_node<int32_t, size_t>* node_6 = graph.add_node(6, -1);
	graph_node<int32_t, size_t>* node_7 = graph.add_node(7, -1);

	// Инициализируем рёбра:
	graph.add_edge(node_1 , node_2, 1);
	graph.add_edge(node_2, node_3, 2);
	graph.add_edge(node_2, node_4, 1);
	graph.add_edge(node_3, node_5, 5);
	graph.add_edge(node_3, node_6, 3);
	graph.add_edge(node_4, node_6, 10);
	graph.add_edge(node_5, node_7, 1);
	graph.add_edge(node_6, node_5, 1);
	graph.add_edge(node_6, node_7, 10);

	graph.traversal(print_node, handle_edge);
}
