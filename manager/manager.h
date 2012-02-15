/**************************************
  * This is the class where most manager functionality should
  * be derrived from (A manager is a souped up map class, with special singleton powers)
  *
  *
  *Written by:
  *  Alex Shepard
  *  aksfkb@mst.edu
  *************************************/

#ifndef MANAGER_H
#define MANAGER_H

#include "../singleton.h"
#include <map>





template < typename IdType, typename DataType >
class Manager : public Singleton < Manager<IdType,DataType> >
{
	public:

		typedef std::map<IdType,DataType> DataTable;

		/** @brief reg
		  * register an item into the manager
		  * @param id the id the object is to have
		  * @param data the value the object is to have
		  * @return true if the manager is created and the object doesnt already exist
		  */
		static bool reg(const IdType & id, const DataType & data);

		/** @brief del
		  *	deletes an item from the manager
		  * @param id the id of the object in question
		  * @return true if the item in question was deleted, otherwise false
		  * @see delPointers
		  */
		static bool del(const IdType & id);

		/** @brief delPointer
		  * deletes a pointer, only to be used if the manager is managing pointers
		  * to objects and not the objects themselves
		  * @param id the id of the object to delete
		  * @return true if the object exists
		  * @see del
		  */
		static bool delPointer(const IdType & id);

		/** @brief exists
		  * Checks to see if an item exists in the manager
		  * @param id the id of the object in question
		  * @return true if it exists
		  */
		static bool exists(const IdType & id);

		/** @brief clear
		  * Clears all data from the manager
		  * @see clearPointer
		  */
		static void clear();

		/** @brief clearPointers
		  * clears out the manager, only to be used if the manager
		  * handles pointers and not actual objects
		  * @see clear
		  */
		static void clearPointers();

		/** @brief size
		  * the amount of stuff stored in the manager
		  * @return The size of the manager map
		  */
		static unsigned int size();

		/** @brief getItem
		  * retrieves the object in question
		  * @param id the id of the object in question
		  * @return a pointer to the object or null if it doesnt exist
		  */
		static DataType * getItem(const IdType & id);

		/** @brief data
		  * retrieves a pointer to the map wrapped map class in case
		  * extra functionality is needed but not given
		  * @return a pointer to the wrapped map class
		  */
		DataTable * data() { return &m_data; }

	protected:

		DataTable m_data;

		//Helper Typedefs to clean up the code and make it readable
		typedef Singleton < ManagerBase<IdType,DataType> > ManagerSingleton;
		typedef ManagerBase<IdType,DataType> BaseType;
		typedef Manager<IdType,DataType> ManagerType;
		typedef std::map<IdType,DataType> DataTable;

	private:
};

#include "manager.hpp"

#endif // MANAGER_H
