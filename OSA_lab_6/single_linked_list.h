#pragma once
#include <stdexcept>
#include "single_linked_node.h"

using namespace std;

template<typename value_type>
class single_linked_list
{
private:
	typedef single_linked_node<value_type> node_type;

	static const size_t START_NODE_INDEX = 0;

	size_t _nodes_count = 0;
	node_type* _first_node = nullptr;
	node_type* _last_node = nullptr;

	/// <summary>
	///  Асимптотическая сложность: O(n).
	/// </summary>
	/// <returns>Возвращает узел списка по индексу.</returns>
	node_type* get_node_by_index(const size_t index) const
	{
		if ((index < this->start_index()) || (index >= this->count()))
		{
			throw out_of_range("element index is out of range");
		}

		node_type* node = this->_first_node;
		for (size_t i = this->start_index(); i < index; i += 1)
		{
			node = node->next_node();
		}

		return node;
	}

public:
#pragma region properties
	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	/// <returns>Возвращает количество элементов в односвязном списке.</returns>
	inline size_t count() const
	{
		return this->_nodes_count;
	}

	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	/// <returns>Возвращает начальный индекс, с которого начинается нумерация элементов списка.</returns>
	inline size_t start_index() const
	{
		return single_linked_list::START_NODE_INDEX;
	}

	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	/// <returns>Возвращает индекс последнего элемента списка.</returns>
	inline size_t last_index() const
	{
		return this->count() - 1;
	}

	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	/// <returns>Возвращает true, если список пустой; иначе false.</returns>
	inline bool is_empty() const
	{
		return this->count() == 0;
	}
#pragma endregion

#pragma region indexators
	/// <summary>
	///  Асимптотическая скорость: O(n).
	/// </summary>
	value_type operator[] (const size_t index)
	{
		node_type* node = this->get_node_by_index(index);
		return node->value();
	}

	const value_type& operator[] (const size_t index) const
	{
		node_type* node = this->get_node_by_index(index);
		return node->value();
	}
#pragma endregion

#pragma region methods
	bool find(size_t& found_index, bool(&is_find) (const value_type&)) const
	{
		node_type* i_node = this->_first_node;
		this->_first_node->set_value(10);
		for (size_t i = 0; i < this->count(); i += 1)
		{
			value_type& i_value = i_node->value();
			if (is_find(i_value))
			{
				found_index = i;
				return true;
			}
			i_node = i_node->next_node();
		}
		return false;
	}

	bool contains(value_type value)
	{
		for (size_t i = 0; i < this->count(); i += 1)
		{
			if (this->get_node_by_index(i)->value() == value)
			{
				return true;
			}
		}
		return false;
	}

	/// <summary>
	///  Асимптотическая скорость: O(n).
	/// </summary>
	void insert_element(const size_t insertion_index, value_type element)
	{
		if ((insertion_index < this->start_index()) || (insertion_index > this->count()))
		{
			throw out_of_range("element index is out of range");
		}

		if (insertion_index == this->start_index())
		{
			this->insert_element_to_start(element);
			return;
		}

		if (insertion_index == this->count())
		{
			this->insert_element_to_the_end(element);
			return;
		}

		size_t node_before_inserted_index = insertion_index - 1;
		node_type* node_before_inserted = this->get_node_by_index(node_before_inserted_index);
		node_type* node_after_inserted = node_before_inserted->next_node();

		node_type* insert_node = new node_type(element, node_after_inserted);
		node_before_inserted->set_next_node(insert_node);

		this->_nodes_count += 1;
	}

	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	void insert_element_to_start(value_type element)
	{
		node_type* insert_node = new node_type(element, this->_first_node);
		this->_first_node = insert_node;

		if (this->is_empty())
		{
			this->_last_node = insert_node;
		}

		this->_nodes_count += 1;
	}

	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	void insert_element_to_the_end(value_type element_value)
	{
		node_type* insert_node = new node_type(element_value);

		if (this->is_empty())
		{
			this->_first_node = insert_node;
			this->_last_node = insert_node;
		}
		else
		{
			this->_last_node->set_next_node(insert_node);
			this->_last_node = insert_node;
		}

		this->_nodes_count += 1;
	}

	/// <summary>
	///  Асимптотическая скорость: O(n).
	/// </summary>
	void remove_element(const size_t removed_element_index)
	{
		if ((removed_element_index < this->start_index()) || (removed_element_index >= this->count()))
		{
			throw out_of_range("element index is out of range");
		}

		if (removed_element_index == this->start_index())
		{
			this->remove_first_element();
			return;
		}

		size_t node_before_removed_index = removed_element_index - 1;
		node_type* node_before_removed = this->get_node_by_index(node_before_removed_index);
		node_type* removed_node = node_before_removed->next_node();
		node_type* node_after_removed = removed_node->next_node();
		node_before_removed->set_next_node(node_after_removed);
		delete removed_node;

		if (removed_element_index == this->last_index())
		{
			this->_last_node = node_before_removed;
		}

		this->_nodes_count -= 1;
	}

	/// <summary>
	///  Асимптотическая скорость: O(1).
	/// </summary>
	void remove_first_element()
	{
		if (this->is_empty())
		{
			return;
		}

		node_type* new_first_node = this->_first_node->next_node();
		delete this->_first_node;
		this->_first_node = new_first_node;

		if (this->count() == 1)
		{
			this->_last_node = nullptr;
		}

		this->_nodes_count -= 1;
	}

	/// <summary>
	///  Асимптотическая скорость: O(n).
	/// </summary>
	void remove_last_element()
	{
		this->remove_element(this->last_index());
	}
#pragma endregion
};
