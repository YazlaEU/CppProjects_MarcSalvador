#include "DynArray.hh"

DynArray::DynArray(void) {

	m_data = new int [ DYN_ARRAY_DEFAULT_SIZE ];
	m_capacity = DYN_ARRAY_DEFAULT_SIZE;
	m_size = DYN_ARRAY_DEFAULT_SIZE;

}

DynArray::DynArray(size_t size, const int &value)
{

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