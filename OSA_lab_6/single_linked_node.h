#pragma once

template<typename value_type>
class single_linked_node
{
private:
	typedef single_linked_node<value_type> self_type;

	value_type _value;
	self_type* _next_node = nullptr;

public:
#pragma region constructors
	single_linked_node(value_type value)
	{
		this->set_value(value);
	}

	single_linked_node(value_type value, self_type* next_node)
	{
		this->set_value(value);
		this->set_next_node(next_node);
	}
#pragma endregion

#pragma region properties
	/// <summary>
	/// ��������������� ��������: O(1).
	/// </summary>
	inline value_type& value()
	{
		return this->_value;
	}

	inline const value_type& value() const
	{
		return this->_value;
	}

	/// <summary>
	/// ��������������� ��������: O(1).
	/// ������������� �������� ����.
	/// </summary>
	inline void set_value(value_type value)
	{
		this->_value = value;
	}

	/// <summary>
	/// ��������������� ��������: O(1).
	/// </summary>
	inline self_type* next_node() const
	{
		return this->_next_node;
	}

	/// <summary>
	/// ��������������� ��������: O(1).
	/// </summary>
	inline void set_next_node(self_type* next_node)
	{
		this->_next_node = next_node;
	}

	/// <summary>
	/// ��������������� ��������: O(1).
	/// </summary>
	inline bool is_next_node_init() const
	{
		return this->next_node() != nullptr;
	}
#pragma endregion
};
