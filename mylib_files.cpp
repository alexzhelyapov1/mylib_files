#include "mylib_files.h"
int error = 0;

int Remove_r (const char *name_of_file) {
	FILE *input = fopen (name_of_file, "r");
	if (input == NULL) {
		DPR("Can't open file")
		return ERROR_OPEN_FILE;
	}

	size_t n = 0;
	error = LenOfFile (input, &n);
	DP(printf ("len of file = %d, name_of_file = \"%s\"\n", n, name_of_file);)
	if (error != OK) {
		return error;
	}

	char *temp_str = (char *) calloc (n, sizeof (char));
	if (temp_str == NULL) {
		DPR("ERROR_ALLOC")
		return ERROR_ALLOC;
	}

	if (fread (temp_str, sizeof (char), n, input) <= 0){
		DPR("ERROR_FREAD")
		return ERROR_FREAD;
	}
	DB(PrintDigitPerformanceOfStr (temp_str, n, "out1.txt");)
	size_t count_zero_end = 0;

	if ((error = CountZeroEnd (temp_str, n, &count_zero_end)) != OK) {
		return error;
	}
	n -= count_zero_end;
	DP(printf ("New len of file = %d, name_of_file = \"%s\"\n", n, name_of_file);)
	fclose (input);

	RELEASE(FILE *output = fopen (name_of_file, "wb");)
	//UNRELEASE(FILE *output = fopen ("output.txt", "wb");)
	if (output == NULL) {
		DPR("ERROR_OPEN_FILE")
		return ERROR_OPEN_FILE;
	}
	if (fwrite (temp_str, sizeof (char), n, output) != n) {
		DPR("ERROR_WRITE")
		return ERROR_WRITE;
	}
	fclose (output);
	return OK;
}


int LenOfFile (FILE *input, size_t *n) {
	struct stat statbuf;
	if (fstat (fileno (input), &statbuf) != -1) {
		DP(printf ("fstat = OK\n");)
		*n = statbuf.st_size;
		return OK;
	}
	else {
		DP(printf ("ERROR in Fstat\n");)
		DPR("ERROR_FSTAT")
		return ERROR_FSTAT;
	}
}


int CountZeroEnd (char *str, int n, size_t *count_zero_end) {
	int i = n - 1;
	size_t counter = 0;
	while (i >= 0 && str[i] == 0) {
		counter++;
		i--;
	}
	DP(printf ("Count of zeros = %d\n", counter);)
	*count_zero_end = counter;
	return OK;
}


int PrintDigitPerformanceOfStr (const char *str, size_t n, const char *name_of_file_out) {
	size_t width_of_output = 20;	//count of symbols in width
	FILE *output = fopen (name_of_file_out, "w");
	if (output == NULL) {
		DPR("Can't open file in function digit performance")
		return ERROR_OPEN_FILE;
	}

	for (int i = 0; i < n; i++) {
		if (i % width_of_output == 0 && i != 0) {
			fprintf (output, "\n");
		}
		fprintf (output, "%d ", str[i]);
	}
	fclose (output);
	return OK;
}