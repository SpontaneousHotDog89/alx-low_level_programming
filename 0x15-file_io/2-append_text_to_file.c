#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file
 * create_file - Creates a file.
 * @filename: A pointer to the name of the file to be created.
 * @text_content: A pointer to a string to be written to the file.
 *
 * Return: If the function fails, it returns -1.
 * Otherwise, it returns 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int len = 0, w, o;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	o = open(filename, O_WRONLY | O_APPEND);
	w = write(o, text_content, len);

	if (o == -1 || w == -1)
		return (-1);

	close(o);

	return (1);
}
