/*
*	FILE			: animals.cpp
*	PROJECT			: A - 03 : Animal - Serve – website developed in CGI and PHP(PROG2001)
*	FIRST VERSION	: 2020 - 10 - 24 (Rev.04)
*	AUTHORS			: Dusan Sasic & Kevin Downer
*	DESCRIPTION		: The CGI coded in C for the Animal Zoo project.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sys/types.h"

#pragma warning(disable : 4996)		// need to do this to be able to use getenv()


//Properties
void DisplayOutput(char* image, char* path);




int main(void)
{


	char* data;				//The variably that will hold query string enviroment variable
	char name[25];			// C style string to store name
	char animal[15];		// C style string to store animal name


	//Constructing HTML head, title and link to an external css file
	printf("Content-type:text/html\n\n");
	printf("<html><head><title>Animal</title><link rel=\"stylesheet\" href=\"../../../ext-css-style-zoo.css\"> </head>\n");
	


	// Get the environment variable containing passed parameters through the URL.
	data = getenv("QUERY_STRING");
	
	//Finding '&' charachrter and replacing it with a whitspace
	char *found = strchr(data, '&');
	*found = ' ';	



	//Scans the the query string and parses two strings, if both strings passed go inside
	if (sscanf(data, "in_name=%s combo_animals=%s", &name, &animal) == 2)
	{

		//Constructing the HTML body and display the greeting message
		printf("<body\n><div class=\"helloName\" align=\"center\">");
		printf("<br><h1> Hello %s, Look If You Dare!</h1></div>", &name);
		

		//Creating a string representing the relative path to the image file for the animal.
		char path_image[500] = "../../../theZoo/";
		strcat(path_image, animal);
		strcat(path_image, ".jpg");

		//Creating a string representing the relative path to the text file for the animal.
		char path_description[500] = "theZoo/";
		strcat(path_description, animal);
		strcat(path_description, ".txt");


		//Function for displaying text and the image based on the file paths
		DisplayOutput(path_image, path_description);


	}
	else
	{
		//In case the the url string was not read properly 
		printf("<p>Invalid Data!</p>");		//Print a message
	}
	
	

	//Close the HTML tags
	printf("</body></html>");
	//Exit the program
	return 0;
}







/*
* FUNCTION		: DisplayOutput
* DESCRIPTION	: This function opens an image based on the file path specified as the parameter and 
				opens a file for reading through the first parameter path and reads three description
				lines from it. Lines are later displayed in formated HTML page.
* RETURN		: shouldSubmit : bool :  Decides if the required User inputs are present and valid.
* Form sent if all the validation requirements are met.
*/
void DisplayOutput(char *image, char *path)
{


	printf("<div><table align=\"center\">");
	printf("<tr><td align=\"right\" width=\"51 % \"> <div class=\"pictureAnimal\"width: 50%; margin: 0 auto;><img src=\"%s\"></img></div></td>", image);
	

	//Open a file		//someText.txt
	FILE* f;
	char line_title[50];
	char line_overview[350];
	char line_characteristics[350];
	char line_special_traits[350];

	//Opens the fil78
	f = fopen(path, "r");
	if (!f)	//If file not opened
	{
		printf("<br><h1>ERROR!!!!</h1>");
		return;
	}

	//fscanf all the way until the fist \n (modified .txt file lil bit, had to)
	fscanf(f, "%[^\n] %[^\n] %[^\n] %[^\n] ", line_title, line_overview, line_characteristics, line_special_traits);

	fclose(f); //Important to close the file


	
	printf("<td align=\"left\" width=\"51 % \"><div id=\"detailTxtBox\" class=\"textAllAnimals\">");
	printf("<h2 class=\"animaltitle\">&nbsp&nbsp%s </h2>", line_title);
	printf(" <ul class = \"a\">");
	printf(" <li><b>Overview:</b><br> %s </li><br><br>", line_overview);
	printf(" <li><b>Characteristics : </b><br> %s </li><br><br>", line_characteristics);
	printf(" <li><b>Special Traits : </b><br> %s </li></div>", line_special_traits);
	printf("</div></td></tr></div>");
	

}



