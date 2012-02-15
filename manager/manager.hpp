#include "manager.h"


template < typename IdType, typename DataType >
unsigned int Manager<IdType,DataType>::size()
{
	if (Manager::isInit())
		Manager::get()->m_data.size();

	return 0;
}


template < typename IdType, typename DataType >
void Manager<IdType,DataType>::clear()
{
	if (Manager::isInit())
		Manager::get()->m_data.clear();
}


template < typename IdType, typename DataType >
bool Manager<IdType,DataType>::exists(const IdType & id)
{
	if (!Manager::isInit())
		return false;

	if (Manager::get()->m_data.find(id) != Manager::get()->m_data.end())
		return true;

	return false;
}


template < typename IdType, typename DataType >
bool Manager<IdType,DataType>::del(const IdType & id)
{
	if (!Manager::isInit())
		return false;

	typename DataTable::iterator it = Manager::get()->m_data.find(id);
	if (it == Manager::get()->m_data.end())
		return false;

	Manager::get()->m_data.erase(it);

	return true;
}


template < typename IdType, typename DataType >
bool Manager<IdType,DataType>::reg(const IdType & id, const DataType & data)
{
	if (!Manager::isInit())
		return false;
	typename DataTable::iterator it = Manager::get()->m_data.find(id);
	if (it != Manager::get()->m_data.end())
		return false;

	Manager::get()->m_data[id] = data;
	return true;
}


template < typename IdType, typename DataType >
DataType * Manager<IdType,DataType>::getItem(const IdType & id)
{

	typename DataTable::iterator it = Manager::get()->m_data.find(id);
	if (it == Manager::get()->m_data.end())
		return NULL;

	return &it->second;
}


template < typename IdType, typename DataType >
bool Manager<IdType,DataType>::delPointer(const IdType & id)
{
	if (!Manager::isInit())
		return false;

	typename DataTable::iterator it = Manager::get()->m_data.find(id);
	if (it == Manager::get()->m_data.end())
		return false;

	if (it->second != NULL)
		delete it->second;

	Manager::get()->m_data.erase(it);

	return true;
}


template < typename IdType, typename DataType >
void Manager< IdType,DataType >::clearPointers()
{
	if (!Manager::isInit())
		return false;

	typename DataTable::iterator it = Manager::get()->m_data.begin();
	for (;it != Manager::get()->m_data.end(); it = Manager::get()->m_data.begin())
	{
		if (it->second)
			delete it->second;

		Manager::get()->m_data.erase(it);
	}

	return true;
}


