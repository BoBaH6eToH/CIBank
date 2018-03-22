#include <string>

/**
* getTripleProp(int value, int genderID, int caseID)
* функция используется для преобразования трехзначного числа в строку независимо от разряда
* 
* @param value    исходное значение
* @param genderID ID рода в диапазоне [0;2]
* @param caseID   ID падежа в диапазоне [0;5]
* @return result  буквенное написание value в соответствии с родом и падежом
*/
std::string getTripleProp(int value, int genderID, int caseID);

/**
* std::string sumProp(long long nSum, std::string sGender, std::string sCase)
* объявление функции по ТЗ
*/
std::string sumProp(long long nSum, std::string sGender, std::string sCase);
