
//! \brief This is the include for the String entity.
#include "String.h"

//! \brief This is the the SDK base Base namespaces.
using namespace EDL_COM::SDK::Base::Base;

//They compare equal
const int String::COMPARE_EQUAL = 0;

//Either the value of the first character that does not match is lower in the compared string,
//or all compared characters match but the compared string is shorter.
const int String::COMPARE_LOWER = -1;

//Either the value of the first character that does not match is greater in the compared string,
//or all compared characters match but the compared string is longer.
const int String::COMPARE_GREATER = 1;

//Tests if this string begin with the specified prefix.
bool String::beginsWith(const string & s, const string & prefix){
	if(prefix.size() > s.size())
		return false;
	return String::equals(s.substr(prefix.size()), prefix );
}

//Concatenates the string s2 at the end of s1
string String::concat(const string & s1, const string & s2){
	string s = s1;
	s.append(s2);
	return s;
}

//Compares two strings lexicographically.
int	String::compare(const string & s1, const string & s2){
	int r = s1.compare(s2);
	 if (r == 0)
		  return String::COMPARE_EQUAL;
	 if(r > 0)
		 return String::COMPARE_GREATER;

	 return String::COMPARE_LOWER;

}

//Tests if this string ends with the specified suffix.
bool String::endsWith(const string & s, const string & suffix){
	if(suffix.size() > s.size())
		return false;
	return String::equals(s.substr(s.size() - suffix.size()), suffix );
}

//Compares this String to another String, ignoring case considerations.
bool String::equalsIgnoreCase(const string & s1, const string & s2){

	return String::equals( String::toLowerCase(s1), String::toLowerCase(s2) );
}

//Compares this String to another String
bool String::equals(const string & s1, const string & s2){
	return (String::compare(s1, s2) == String::COMPARE_EQUAL);
}

//Returns a formatted string using the specified locale, format string, and arguments.
string String::format(const char * format, ...){
	char buffer[500];
	int size;
	va_list args;
	string s;
	 va_start (args, format);
	 if( (size = vsprintf (buffer,format, args)) < 0){
	 	 s = "";
	 }else{
		s = string(buffer, size);
	 }
	 va_end (args);
	 return s;
}

//Converts all of the characters in this string to lower case.
string String::toLowerCase(const string & s){
	string sA;
	for(unsigned int i = 0; i < s.size(); i++)
		sA.append(1 , tolower(s.at(i)) );
	return sA;
}

//Returns a string representation of the string argument as an string in base 16.
string String::toHexString(const string & s){

   string hex = "";
   unsigned char c;
   for(unsigned int i = 0; i < s.size(); i++){
	   c = s.at(i);
	   hex.append( String::format("%02X", c));
   }
   return hex;
}

//Converts all of the characters in this String to upper;
string	String::toUpperCase(const string & s){
	string sA;
	for(unsigned int i = 0; i < s.size(); i++)
		sA.append(1 , toupper(s[i]) );
	return sA;
}

//Returns a copy of the string, with leading and trailing whitespace omitted.
string	String::trim(const string & s){
	string sA;
	char c;
	for(unsigned int i = 0; i < s.size(); i++){
		if( s.at(i) != ' ' )
		   sA.append(1, s[i]);

	}
	return sA;
}

//Returns the string representation of the bigLong argument.
string 	String::valueOf(bigLong b){

	return String::format("%lld", b);
}

//Returns the string representation of the boolean argument.
string 	String::valueOf(bool b){
	return String::format("%d", b);
}

//Returns the string representation of the byte argument.
string 	String::valueOf(byte b){
	return String::format("%d", b);
}

//Returns the string representation of the char argument.
string 	String::valueOf(char c){
	return String::format("%c", c);
}

//Returns the string representation of the double argument.
string 	String::valueOf(double d){
	return String::format("%f", d);
}
//Returns the string representation of the float argument.
string 	String::valueOf(float f){
	return String::format("%f", f);
}

//Returns the string representation of the int argument.
string 	String::valueOf(int i){
	return String::format("%d", i);
}

//Returns the string representation of the long argument.
string 	String::valueOf(long l){
	return String::format("%ld", l);
}

//Returns the string representation of the Object argument.
string 	String::valueOf(Object obj){
	return obj.toString();
}

//Returns the string representation of the short argument.
string String::valueOf(short i){
	return String::format("%d", i);
}

//Return long vector representation of the string separated by delimiter
double * String::ToDoubleVector(char * stringInteger, const char * delimiter, size_t * size){

   char * pch;
   double * vecDouble = NULL;
   char buffer[256];
   vector<double> vec;

   strcpy(buffer, stringInteger);

   pch = strtok(buffer, delimiter);
   while (pch != NULL)
   {
       vec.push_back(stod(pch));
       pch = strtok (NULL, delimiter);
   }

   if(size){
       *size = vec.size();
   }

   vecDouble = new double [vec.size()];

   for(size_t i = 0 ; i < vec.size(); i++)
       vecDouble[i] =  vec[i];

   return vecDouble;
}
