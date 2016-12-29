#include "Iterator.h"

IIterator* CAggregate::get_iterator() {
	return new CIterator(this);
}

void CIterator::first() {
	m_index = 0;
}

void CIterator::next() {
	if (m_index < m_aggregate_ptr->m_data_set.size()) {
		m_index++;
	}
}

bool CIterator::is_done() {
	return m_index == m_aggregate_ptr->m_data_set.size();
}

DATA CIterator::current() {
	return m_aggregate_ptr->m_data_set[m_index];
}