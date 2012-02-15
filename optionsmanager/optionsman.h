/************************************
*This file contains a singleton manager
*for global variables. It will load in
*variables from a options file specified,
*store and maintain those options, and
*save them back out to a file specified.
*
*This is an attempt at a
*workaround for pseudo run time type
*information (RTTI) in C++ for global options.
*
*
*Written by:
*  Alex Shepard
*  aksfkb@mst.edu
*************************************/
#ifndef OPTIONSMAN_H
#define OPTIONSMAN_H

#include "option.h"
#include "../singleton.h"
#include "../mutex/Mutex.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <sstream>


/** This is a helper typedef in case the requirements
  * for the id of options changes. Ex: from std::string to QString
  **/
typedef std::string OptID_t;

/** This class is the singleton manager for the options.
  * It isn't meant to have any kind of instance based off of it
  * and instead all access to the class is done through static
  * member functions
  */
class OptionsMan : public Singleton <OptionsMan>
{
	public:
		/** @brief loadOptionFile
		  * this loads in an option file to the singleton
		  * @param filename the option file to load
		  * @return true if all goes well
		  */
		static bool loadOptionFile(const std::string & filename);

		/** @brief saveOptionFile
		  *	save all of your options to file
		  * @param filename the name of the file to save the options into
		  * @return true if all goes well
		  * @todo find a way to maintain comments and white space
		  * @todo better error checking
		  */
		static bool saveOptionFile(const std::string & filename);

		/** @brief operator()
		  *	Directly access an option's pointer
		  * @param oName the name of the option to access
		  * @return a pointer to the option if it exists, otherwise NULL
		  */
		OptionBase * operator()(const OptID_t & oName);

		/** @brief exists
		  * check to see if the string is a valid option name
		  * @param oName The name of the option to check
		  * @return true if it exists
		  */
		static bool exists(const OptID_t & oName);


		/** @brief getInt
		  * get the value of a integer option
		  * @param oName the name of the option
		  * @return the value of the option or a default variable value if it
				doesnt exist
		  */
		static int getInt(const OptID_t & oName);

		/** @brief setInt
		  * set an integer option to the intended value
		  * @param oName the name of the option to be modified
		  * @param val the value to change the option to
		  */
		static void setInt(const OptID_t & oName,const int & val);


		/** @brief getFloat
		  * get the value of a float option
		  * @param oName the name of the option
		  * @return the value of the option or a default variable value if it
				doesnt exist
		  */
		static float getFloat(const OptID_t & oName);

		/** @brief setFloat
		  * set a float option to the intended value
		  * @param oName the name of the option to be modified
		  * @param val the value to change the option to
		  */
		static void setFloat(const OptID_t & oName,const float & val);


		/** @brief getBool
		  * get the value of a bool option
		  * @param oName the name of the option
		  * @return the value of the option or a default variable value if it
				doesnt exist
		  */
		static bool getBool(const OptID_t & oName);

		/** @brief setBool
		  * set a bool option to the intended value
		  * @param oName the name of the option to be modified
		  * @param val the value to change the option to
		  */
		static void setBool(const OptID_t & oName,const bool & val);


		/** @brief getStr
		  * get the value of a string option
		  * @param oName the name of the option
		  * @return the value of the option or a default variable value if it
		  * 	doesnt exist
		  */
		static std::string getStr(const OptID_t & oName);

		/** @brief setStr
		  * set a string option to the intended value
		  * @param oName the name of the option to be modified
		  * @param val the value to change the option to
		  */
		static void setStr(const OptID_t & oName,const std::string & val);

		/** @brief optionType
		  * get the type of the option in question
		  * @param oName the name of the option
		  * @return the type of the option if it exists, otherwise OT_NONE
		  */
		static OptionType optionType(const OptID_t & oName);

		/** @brief destroy
		  * destroy the options manager
		  * @return true if all goes well
		  */
		static bool destroy();

		/** @brief add*
		  * add a variable of the chosen type to be tracked by the options
				manager
		  * @param oName the name of the option
		  * @param val the value the option will be set to
		  * @return true if the option doesn't exist yet and if the OptionManager
				has been created
		  */
		static bool addString(const OptID_t & oName, const std::string & val);
		static bool addInt(const OptID_t & oName, const int & val);
		static bool addFloat(const OptID_t & oName, const float & val);
		static bool addBool(const OptID_t & oName, const bool & val);


	protected:
	private:

		//! private contstructor to prevent instantiation
		OptionsManager(){}


		//! @see optionsman.cpp for helper function documentation
		template<class T, OptionType OT>
		static T getVar(const OptID_t & oName);

		template<class T, OptionType OT>
		static void setVar(const OptID_t & oName, const T & val);

		static bool strToBool(const std::string & val);

		static OptionType getTypeFromStr(const std::string & val);


		static bool addString(const OptID_t & oName, std::stringstream & ss, const unsigned int & lineNum);
		static bool addInt(const OptID_t & oName, std::stringstream & ss, const unsigned int & lineNum);
		static bool addFloat(const OptID_t & oName, std::stringstream & ss, const unsigned int & lineNum);
		static bool addBool(const OptID_t & oName, std::stringstream & ss, const unsigned int & lineNum);

		std::map<OptID_t, OptionBase* > m_options;
};

#endif // OPTIONSMAN_H
