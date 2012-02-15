/************************************
*This file contains a templatable option
*class that can easily be extended to
*contain new types. This is an attempt at a
*workaround for pseudo run time type
*information (RTTI) in C++ for global options.
*
*@see optionsman.h
*
*Written by:
*  Alex Shepard
*  aksfkb@mst.edu
*************************************/
#ifndef OPTION_H
#define OPTION_H


/** An enumeration that represents all of the known
  * types the global options system can handle.
  * This was lowest impact way of representing
  * RTTI.
  *
  * this is the only part of this file
  * that needs to be updated if a new
  * global option type is to be implemented
  **/
enum OptionType
{
	OT_NONE,
	OT_INT,
	OT_FLOAT,
	OT_STRING,
	OT_BOOL
};

/** This class is a base class used for tricking
  * C++ into inheriting templates
  **/
class OptionBase
{
	public:
		/** @brief OptionBase
		  * contstructor for creating an option
		  * @param ot the enumerated type of the option
		  */
		OptionBase(const OptionType & ot):m_type(ot){}

		/** @brief type
		  * accessor for the RTTI of the option
		  * @return the type this option represents
		  */
		OptionType type(){return m_type;}

	protected:
		OptionType m_type;
	private:

};

/** This is the real interface to each option object.
  * Template Argument T: The type the object represents
  * Template Argument ot: The RTTI of the option
  **/
template<class T, OptionType ot>
class Option : public OptionBase
{
	public:
		/** @brief Option
		  * contstructor for creating an option
		  * @param data the data of the option
		  */
		Option(const T & data):OptionBase(ot),m_data(data){}

		/** @brief Option
		  * contstructor for creating an empty option
		  */
		Option():OptionBase(ot){}

		/** @brief get
		  * accessor for the data contained at this option
		  * @return the data of this option
		  */
		T get(){return m_data;}

		/** @brief set
		  * mutator for the data contained at this option
		  * @param data the data to set this option to
		  */
		void set(const T & data){m_data = data;}
	protected:
		T m_data;
};


#endif // OPTION_H
