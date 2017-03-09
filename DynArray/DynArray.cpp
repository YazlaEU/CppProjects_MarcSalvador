#include "DynArray.hh"

DynArray::DynArray(void) :

	m_capacity(DYN_ARRAY_DEFAULT_SIZE),
	m_size(0),
	m_data(new int[m_capacity])
{
}


DynArray::DynArray(size_t size, const int &value) :

	m_capacity(size),
	m_size(size),
	m_data(new int[size])
{
	fill(begin(), end(), value);
}

int* DynArray::begin (void) const
{
	return m_data;
}

int* DynArray::end(void) const
{
	return m_data + m_size;
}

DynArray fill(int *first, int *last, int value)
{
	while (first != last) {
		*first = value;
		first++;
	}
}

bool operator== (const DynArray& lhs, const DynArray& rhs) {
	return lhs == rhs;
}

void DynArray::push(const int &val) {
	
	if (m_capacity == m_size) {
		DynArray tmp(m_size + (m_capacity / 2), 0);
		
	}
	else {
		m_data[m_size + 1] = val;
	}
}