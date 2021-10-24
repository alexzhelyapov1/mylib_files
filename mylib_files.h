#ifndef REMOVE_R_H_INCLUDED
#define REMOVE_R_H_INCLUDED

	#define DEBUG  
	#define REDIRECTION_OUTPUT
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


	int Remove_r (const char *name_of_file);
	int LenOfFile (FILE *input, size_t *n);
	int CountZeroEnd (char *str, int n, size_t *count_zero_end);
	int PrintDigitPerformanceOfStr (const char *str, size_t n, const char *name_of_file_out);


	#ifdef DEBUG
	#define DP(code) code
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

#endif