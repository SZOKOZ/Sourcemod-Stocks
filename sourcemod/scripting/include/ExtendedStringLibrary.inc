/**************************
 * Extended String Library
 *
 * Convenient string operations at your disposal.
 *
 *************************/

#define SBUF(%1) %1, sizeof(%1)

/*
 * So you want to know if a string begins with a certain phrase? No worries I got you.
 *
 * @param substring        Phrase or sentence you want to check for at beginning of string.
 * @param string           Text to check for substring.
 * @param size             Size of string buffer.
 *
 * return bool             True if string begins with substring (or if both string arguments are empty... Change that part if you want)
 *                         otherwise returns false.
 */
bool beginsWith(const char[] substring, const char[] string, int size)
{
	if ((substring[0] == '\0' || string[0] == '\0'))
	{
		if (substring[0] == '\0' && string[0] == '\0')
		{
			return true;
		}
		
		return false;
	}
	
	for (int index = 0; index < size; index++)
	{
		if (substring[index] == '\0')
		{
			return true;
		}
		
		if (substring[index] == string[index])
		{
			continue;
		}	
	}
	
	return false;
}
