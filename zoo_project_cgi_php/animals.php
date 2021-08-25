<!--
FILE			      : animals.php
PROJECT			    : A-03 : Animal-Serve – website developed in CGI and PHP (PROG2001)
FIRST VERSION	  : 2020-10-24 (Rev.04)
AUTHORS			    : Dusan Sasic & Kevin Downer
DESCRIPTION		  : The PHP code for the Animal Zoo project.
-->
<!DOCTYPE html>

  <?php
    // prep the elements required 
    // User name
    $name = $_POST['in_name'];	
    // Animal selection
    $animal = $_POST['combo_animals'];

    //Animal title 
    $title;
    // Overview animal text
    $line_overview;
    // Characteristics animal text
    $line_characteristics;
    // Traits animal text
    $line_special_traits;


    // external path to the image folder and what extension type to search
    $path_img = "theZoo/" . $animal . ".jpg";
    // external path to the text folder and what extension type to serach
    $path_text= "theZoo/" . $animal . ".txt";


    // Variable that determens which string will store which line from .txt file
    $i = 0;
    

    // open and read the external text files
    if ($file = fopen($path_text, "r")) 
    {
        // While the end of file is not reached 
        while(!feof($file)) 
        {
        // process line by line from the text file 
        $textperline = fgets($file);
            if($i == 0)
                $title = $textperline;
            else if($i == 1)
                // Save the first line in line_overview variable
                $line_overview = $textperline;
            if($i == 2)
                // Save the second line in line_characteristics variable
                $line_characteristics = $textperline;
            if($i == 3)
                // Save the third line in line_special_traits variable
                $line_special_traits = $textperline;
            $i++;
        }
    // finished with text file, safely close it
    fclose($file);
    }
  ?>


  <html>

  <head>
    <title>Animals</title>
    <link rel="stylesheet" href="ext-css-style-zoo.css">
  </head>

  <body>
   <!--  NOTE:  This code was changed to accomodate the html requirements, needs to be merged into CGI --> 
  <div class="helloName" align="center"><h1> Hello <?php print($name)?>, Look If You Dare!</h1></div>
  <div>
  <table align="center">
  <tr>
  <td  align="right" width="50%"> 
  <div class="pictureAnimal"width: 50%; margin: 0 auto;><img src="<?php echo($path_img)?>"></img></div>
  </td>
  <td  align="left" width="50%">
  <div id="detailTxtBox" class="textAllAnimals">
  
    <div class="content">
    <h2 class="animaltitle"><?php echo $title ?></h2> 
    <ul class="a">
      <li><b>Overview:</b><br><?php echo $line_overview ?></li>
      <br><br>
      <li><b>Characteristics:</b><br><?php echo $line_characteristics ?></li>
      <br><br>
      <li><b>Special Traits:</b><br><?php echo $line_special_traits ?></li>
    </div>

  </div>
  </td>
  </tr>
  </div>

  

  </body>

</html>