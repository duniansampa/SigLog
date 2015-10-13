
#ifndef STRING_H_
#define STRING_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/*!
 * \brief     Sample application.
 * \details   This application is used to show some doxygen tips.
 * \author    Dunian Coutinho Sampa
 * \version   1.0a
 * \date      2014-2014
 * \pre       Have a Linux and C/C++ environment configured.
 * \bug       No bug.
 * \warning   N/A
 * \copyright MECTRON LTDA.
 */

#include "../Base/Object.h"

//! \brief This is the EDL_COM SDK base base namespaces.
using namespace EDL_COM::SDK::Base::Base;

//! Implementations for EDL_COM features.
namespace EDL_COM {

	//! Implementations for SDK features.
	namespace SDK {

		//! Implementations for base features.
		namespace Base {

			//! Implementations for Base operations.
			namespace Base {

				//! A class to define String operations.
				class String {
				public:
					 //They compare equal
					 static const int COMPARE_EQUAL;

					 //Either the value of the first character that does not match is lower in the compared string,
					 //or all compared characters match but the compared string is shorter.
					 static const int COMPARE_LOWER;

					 //Either the value of the first character that does not match is greater in the compared string,
					 //or all compared characters match but the compared string is longer.
					 static const int COMPARE_GREATER;

					 //Tests if this string begin with the specified prefix.
					 static bool beginsWith(const string & s, const string & prefix);

					 //Concatenates the string s2 at the end of s1
					 static string	concat(const string & s1, const string & s2);

					//Compares two strings lexicographically.
					 static int	compare(const string & s1, const string & s2);

					 //Tests if this string ends with the specified suffix.
					 static bool endsWith(const string & s, const string & suffix);

					 //Compares this String to another String, ignoring case considerations.
					 static bool equalsIgnoreCase(const string & s1, const string & s2);

					 //Compares this String to another String
					 static bool equals(const string & s1, const string & s2);

					 //Returns a formatted string using the specified locale, format string, and arguments.
					 static string format(const char * format, ...);

					 //Converts all of the characters in this string to lower case.
					 static string toLowerCase(const string & s);

					 //Converts all of the characters in this String to upper;
					 static string	toUpperCase(const string & s);

					 //Returns a string representation of the string argument as an string in base 16.
					 static string toHexString(const string & s);

                     //Return long vector representation of the string separated by delimiter
                     static double * ToDoubleVector(char * stringOid, const char * delimiter, size_t * size = NULL);

					 //Returns a copy of the string, with leading and trailing whitespace omitted.
					 static string	trim(const string & s);

					 //Returns the string representation of the bigLong argument.
					 static string 	valueOf(bigLong b);

					 //Returns the string representation of the boolean argument.
					 static string 	valueOf(bool b);

					 //Returns the string representation of the byte argument.
					 static string 	valueOf(byte b);

					 //Returns the string representation of the char argument.
					 static string 	valueOf(char c);

					 //Returns the string representation of the double argument.
					 static string 	valueOf(double d);

					 //Returns the string representation of the float argument.
					 static string 	valueOf(float f);

					 //Returns the string representation of the int argument.
					 static string 	valueOf(int i);

					 //Returns the string representation of the long argument.
					 static string 	valueOf(long l);

					 //Returns the string representation of the Object argument.
					 static string 	valueOf(Object obj);

					 //Returns the string representation of the short argument.
					 static string 	valueOf(short i);                     
				};

				/*!
				 * \class String
				 * \brief A class to perform atring operations.
				 */
			}
		}
	}
}

#endif /* STRING_H_ */
