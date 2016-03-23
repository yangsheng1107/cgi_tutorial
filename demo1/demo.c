#include "stdio.h"

char *strHeader =
"<!doctype html>\r\n"
"<html lang='en'>\r\n"
"<head>\r\n"
"  <meta charset='utf-8'>\r\n"
"  <title>%s</title>\r\n"
"  <meta name='description' content='The HTML5 Herald'>\r\n"
"</head>\r\n"
"<body>\r\n";

char *strFooter = "\r\n</body>\r\n</html>\r\n";

void printHtmlHeader(char *title)
{
	char header[256];
	snprintf(header, 255, strHeader, title);
	printf("%s", header);
}

void printHtmlFooter()
{
	printf("%s", strFooter);	
}

int main(void)
{
	printHtmlHeader("Demo1");

	printf("Hello world !\n");
	
	printHtmlFooter();

	return 0;
}

