#pragma once
#include <unordered_set>
#include <vector>
#include <iostream>
#include "graph_entities.h"
#include "single_linked_list.h"

using namespace std;

template<typename value_type, typename cost_type>
class graph
{
private:
	typedef graph_node<value_type, cost_type> node_type;
	typedef graph_edge<value_type, cost_type> edge_type;
	//typedef dijkstra_node<value_type, cost_type> d_node_type;

	node_type* _root_node = nullptr;
	unordered_set<node_type*> _nodes;
	size_t _nodes_count = 0;

public:
#pragma region properties
	const size_t count() const
	{
		return this->_nodes_count;
	}

	const node_type* root_node() const
	{
		return this->_root_node;
	}
#pragma endregion

#pragma region methods
	void traversal(
		void (&node_action) (node_type*),
		void (&edge_action) (edge_type*))
	{
		single_linked_list<node_type*> visited_nodes;
		single_linked_list<node_type*> unvisited_nodes;
		unvisited_nodes.insert_element_to_start(this->_root_node);

		while (unvisited_nodes.count() > 0)
		{
			node_type* explored_node = unvisited_nodes[0];
			unvisited_nodes.remove_first_element();
			visited_nodes.insert_element_to_start(explored_node);
			node_action(explored_node);
			
			for (edge_type* output_edge : explored_node->output_edges())
			{
				node_type* destination_node = output_edge->destination_node();
				edge_action(output_edge);
				if (!unvisited_nodes.contains(destination_node) && !visited_nodes.contains(destination_node))
				{
					unvisited_nodes.insert_element_to_the_end(output_edge->destination_node());
				}
			}
		}
	}

	node_type* add_node(value_type value, cost_type shortest_path_cost)
	{
		node_type* added_node = new node_type(value, shortest_path_cost);
		this->_nodes.insert(added_node);
		if (this->_nodes_count == 0)
		{
			this->_root_node = added_node;
		}
		this->_nodes_count += 1;
		return added_node;
	}

	void add_edge(node_type* source_node, node_type* destination_node, cost_type cost)
	{
		source_node->add_edge(destination_node, cost);
	}

	void d_e(edge_type* edge)
	{
	}

	void dijkstra()
	{
		this->_root_node->shortest_path_cost() = 0;
	}

	//vector<d_node_type> dijkstra_alg_result() const
	//{
	//	vector<d_node_type> result;
	//	d_node_type d(this->_root_node, 0, true);
	//	result.insert(d);
	//}
#pragma endregion
};
