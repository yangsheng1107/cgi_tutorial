/*
http://192.168.56.101/demo3.cgi?name=John&age=19
*/
#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char* argv[], char *envp[])
{
	int age;
	char name[20];
	char *query;
	printHtmlHeader("Demo3-Get");

	query = getenv("QUERY_STRING");
	if(query != NULL)
	{
		sscanf(query, "name=%[^&]&age=%d", name, &age);
		printf("name:%s<br />age:%d<br/>", name, age);
	}
	else
	{
		printf("<P>Error! Invalid data.");
	}

	printHtmlFooter();
	return 0;
}
