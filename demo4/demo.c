/*
http://192.168.56.101/demo4.cgi
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
	int length, age;
	char *postdata;
	char name[20];
	printHtmlHeader("Demo4-Post");

	length=atoi(getenv("CONTENT_LENGTH"));
	postdata = (char *)malloc(length + 1);
	if (!postdata) {
		exit(EXIT_FAILURE); 
	}
	fgets(postdata, length + 1, stdin);
	sscanf(postdata, "name=%[^&]&age=%d", name, &age);
	printf("name:%s<br />age:%d<br/>", name, age);
	free(postdata);

	printHtmlFooter();
	return 0;
}
