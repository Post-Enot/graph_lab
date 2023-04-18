#pragma once
#include <unordered_set>

using namespace std;

//template<typename value_type, typename cost_type>
//class dijkstra_node;
//
//template<typename value_type, typename cost_type>
//class dijkstra_edge
//{
//private:
//	typedef dijkstra_node<value_type, cost_type> node_type;
//
//	node_type* _destination_node = nullptr;
//	cost_type _cost;
//
//public:
//#pragma region constructors
//	dijkstra_edge(node_type* destination_node, cost_type cost)
//	{
//		this->destination_node() = destination_node;
//		this->cost() = cost;
//	}
//#pragma endregion
//
//#pragma region properties
//	const node_type* const& destination_node() const
//	{
//		return this->_destination_node;
//	}
//
//	node_type*& destination_node()
//	{
//		return this->_destination_node;
//	}
//
//	const cost_type& cost() const
//	{
//		return this->_cost;
//	}
//
//	cost_type& cost()
//	{
//		return this->_cost;
//	}
//#pragma endregion
//};
//
//template<typename value_type, typename cost_type>
//class dijkstra_node
//{
//private:
//	typedef dijkstra_node<value_type, cost_type> self_type;
//	typedef graph_node<value_type, cost_type> node_type;
//	typedef dijkstra_edge<value_type, cost_type> edge_type;
//
//	node_type* _node = nullptr;
//	cost_type _shortest_path_cost;
//	bool _is_visited = false;
//	unordered_set<edge_type> _output_edges;
//
//public:
//	dijkstra_node(node_type* node, cost_type shortest_path_cost, bool is_visited = false)
//	{
//		this->node() = node;
//		this->shortest_path_cost() = shortest_path_cost;
//		this->is_visited() = is_visited;
//	}
//
//#pragma region properties
//	node_type*& node()
//	{
//		return this->_node;
//	}
//
//	cost_type& shortest_path_cost()
//	{
//		return this->_shortest_path_cost;
//	}
//
//	bool& is_visited()
//	{
//		return this->_is_visited;
//	}
//#pragma endregion
//
//#pragma region methods
//	void add_edge(self_type* destination_node, cost_type cost)
//	{
//		edge_type added_edge(destination_node, cost);
//		this->_output_edges.insert(&added_edge);
//	}
//#pragma endregion
//};

template<typename value_type, typename cost_type>
class graph_node;

template<typename value_type, typename cost_type>
class graph_edge
{
private:
	typedef graph_node<value_type, cost_type> node_type;

	node_type* _destination_node = nullptr;
	cost_type _cost;

public:
#pragma region constructors
	graph_edge(node_type* destination_node, cost_type cost)
	{
		this->destination_node() = destination_node;
		this->cost() = cost;
	}
#pragma endregion

#pragma region properties
	const node_type* const& destination_node() const
	{
		return this->_destination_node;
	}

	node_type*& destination_node()
	{
		return this->_destination_node;
	}

	const cost_type& cost() const
	{
		return this->_cost;
	}

	cost_type& cost()
	{
		return this->_cost;
	}
#pragma endregion
};

template<typename value_type, typename cost_type>
class graph_node
{
private:
	//typedef dijkstra_node<value_type, cost_type> d_node_type;
	typedef graph_edge<value_type, cost_type> edge_type;
	typedef graph_node<value_type, cost_type> self_type;

	value_type _value;
	unordered_set<edge_type*> _output_edges;
	cost_type _shortest_path_cost;

public:
#pragma region constructors
	graph_node(value_type value, cost_type shortest_path_cost)
	{
		this->value() = value;
		this->shortest_path_cost() = shortest_path_cost;
	}
#pragma endregion

#pragma region properties
	const value_type& value() const
	{
		return this->_value;
	}

	value_type& value()
	{
		return this->_value;
	}

	const size_t output_edges_count() const
	{
		return this->_output_edges.size();
	}

	cost_type& shortest_path_cost()
	{
		return this->_shortest_path_cost;
	}
#pragma endregion

#pragma region methods
	void add_edge(self_type* destination_node, cost_type cost)
	{
		edge_type* added_edge = new edge_type(destination_node, cost);
		this->_output_edges.insert(added_edge);
	}

	bool remove_edge(edge_type* removed_edge)
	{
		this->_output_edges.erase(removed_edge);
	}

	unordered_set<edge_type*> output_edges()
	{
		return this->_output_edges;
	}

	void dijkstra()
	{
		// берём этот узел, назначаем цену ноль, отмечаем, что посетили.

	}
#pragma endregion
};
