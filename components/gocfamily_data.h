/************************************
*This file contains a templated component.
*Since megaminer is a semesterly event
*it must be easy to build the pieces of the
*visualizer. This is intended to give the
*visualizer programmer a base for them to put
*the struct that is automatically created
*by the code generator.
*
*Written by:
*  Alex Shepard
*  aksfkb@mst.edu
*************************************/
#ifndef GOCFAMILY_DATA_H
#define GOCFAMILY_DATA_H

#include "../gameobject/gameobject.h"
#include "../gameobject/gocomponent.h"

template <class T>
class GOCFamily_Data : public GOComponent
{
	public:
	/** Default constructor */
	GOCFamily_Data(){}
	/** Default destructor */
	virtual ~GOCFamily_Data() = 0;

	const GOC_IDType familyID() const
    {
      return GOC_IDType( "DataFamily" );
    };

    T * getData()
    {
      return &m_data;
    }

	protected:
	    T m_data;

	private:
};

#endif

