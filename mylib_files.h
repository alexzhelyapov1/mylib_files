#ifndef REMOVE_R_H_INCLUDED
#define REMOVE_R_H_INCLUDED

/*!
What can you define:
	DEBUG - allow print debug info to degub programm.
	REDIRECTION_OUTPUT - STD output will be redirected and printed in file.
	RELEASE_MODE - the best modification of programm.
*/

	//#define DEBUG  
	//#define REDIRECTION_OUTPUT
	#define RELEASE_MODE
	#include <stdio.h>
	#include <stdlib.h>
	#include <sys\stat.h>

	enum ERRORS {
		OK = 0,
		ERROR_OPEN_FILE,
		ERROR_ALLOC,
		ERROR_FREAD,
		ERROR_WRITE,
		ERROR_FSTAT
	};

/// -------------------------------------------------------------------------------------------------------------------
/*! 
This is manual of my LIBRARY

	Remove_r - delete \r in windows test files and rewrite it.
	LenOfFile - return the length of the file in bytes.
	CountZeroEnd - return count of zeros in the end of the string.
	PrintDigitPerformanceStr - print char document in digit format.

*/

	int Remove_r (const char *name_of_file);
	int LenOfFile (FILE *input, size_t *n);
	int CountZeroEnd (char *str, int n, size_t *count_zero_end);
	int PrintDigitPerformanceOfStr (const char *str, size_t n, const char *name_of_file_out);
/// -------------------------------------------------------------------------------------------------------------------
/// Conditional compilation chapter

	#ifdef DEBUG
	#define DP(code) {fprintf code;}
	#define DB(code) code
	#define DPR(code) {printf ("------ "); printf (code); printf ("! FILE = %s, LINE = %d\n", __FILE__, __LINE__);}
	#else
	#define DP(code) 
	#define DB(code) 
	#define DPR(code) 
	#endif

	#ifdef RELEASE_MODE
		#define RELEASE(code) code
		#define UNRELEASE(code) 
	#else
		#define RELEASE(code)
		#define UNRELEASE(code) code
	#endif

	#ifdef REDIRECTION_OUTPUT
	#define REDIR(code) code
	#else
	#define REDIR(code) 
	#endif
/// -------------------------------------------------------------------------------------------------------------------

#endif