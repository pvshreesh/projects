<?php

$conn = mysqli_connect("localhost","root","snores","login");




        if(isset($_POST['save']))
{

    $slno= $_POST['slno'];
    $docname= $_POST['docname'];
    $dateofupload= $_POST['dateofupload'];
    $fname= $_POST['filename'];

    

        if(isset($_POST['docname']))
        {
            $query1 = "UPDATE annex SET docname='$docname' where slno='$slno' ";
            $result1 = mysqli_query($conn,$query1);
        }
        if(isset($_POST['dateofupload']))
        {
            $query2 = "UPDATE annex SET dateofupload='$dateofupload' where slno='$slno' ";
            $result2 = mysqli_query($conn,$query2);
        }
        if(isset($_POST['filename']))
        {
            $query3 = "UPDATE annex SET filename='$fname' where slno='$slno' ";
            $result3 = mysqli_query($conn,$query3);
        }
 
        
            if($result1 || $result2 || $result3 )
            {
                echo'edited';
            }
            else
            {
                echo 'failed to edit';
            }
        
}


  

?>
<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Annexure 2 Edit Page</title>
        <link href="Top.css" rel="stylesheet" type="text/css"  />
    <link href="Login.css" rel="stylesheet" type="text/css"  />
    <link href="Default.css" rel="stylesheet" type="text/css"  />
    <link href="buttons.css" rel="stylesheet" type="text/css"  />
    </head>
    <body>
         <header class="headers">
    <div >
    <img src="icon1.jpg" class="icon1" alt="Icon 1" />
    <img src="icon2.jpeg" class="icon2" alt="Icon 2" />
    <h1 class="head1">POWER SECTOR-MARKETING</h1>
    <br>
    
    <button class="button1">HOME</button>
    <button class="button1">ABOUT US</button>
    <button class="button1">OUR CUSTOMERS</button>
    <button class="button1">BUSINESS ENVIRONMENT</button>
    <button class="button1">ONLINE SYSTEM</button>
    <button class="button1">TENDERS</button>
    <button class="button1">CONTRACTS</button>
    <button class="button1">EMPLOYEE CORNER</button>
    


</div>
</header>
<div style="text-align:center;">
        <form action="edit2.php" method="post" id="addrow" and enctype="multipart/form-data">



            <label for="slno"><b>Sl.No</b></label><br>
    <input type="text" placeholder="Enter slno" name="slno" ><br>
    
    <label for="docname"><b>DocName</b></label><br>
    <input type="text" placeholder="Enter docname" name="docname" ><br>
    
    <label for="dateofupload"><b>Date of Upload</b></label><br>
    <input type="text" placeholder="Enter dateofupload" name="dateofupload" ><br>
    
    <label for="filename"><b>File Name</b></label><br>
    <input type="text" placeholder="Enter filename" name="filename" ><br>
    

        <button type="submit" name="save">Edit</button>
        </form>
        
        <form  action="Annexure2.php">
        <input class="editbtn" type="submit" value="back" />
        </form>
    </div>
        
    </body>
</html>