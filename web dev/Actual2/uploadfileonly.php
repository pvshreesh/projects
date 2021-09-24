<?php


$conn = mysqli_connect("localhost","root","snores","login");



if(isset($_GET['file_id']))
{
    $id = $_GET['file_id'];
    echo $id;


}


if(isset($_POST['save']))
{

   
    $filename = $_FILES['myfile']['name'];
    $destination= 'uploads/'.$filename;
    $file  = $_FILES['myfile']['tmp_name'];
    $size = $_FILES['myfile']['size'];
    $hpvpenqno = $_POST['hpvpenqno'];
    $sql = "UPDATE upload SET id='$filename' WHERE hpvpenqno='$hpvpenqno'";
    
    if(mysqli_query($conn,$sql))
    {   
        echo 'edited in db';
    }
        
            if(move_uploaded_file($file, $destination))
        {
  
             echo'uploaded in  folder';
        }
       
}



?><!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <meta charset="UTF-8">
        <title>Annexure 1 Upload File Page</title>
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
        <form action="uploadfileonly.php" method="post" id="upload" and enctype="multipart/form-data">
                <input type="file" name="myfile"><br>
                
                
    <label for="hpvpenqno"><b>HPVPENQNO.NO</b></label><br>
    <input type="text" placeholder="Enter HPVPENQNO.no" name="hpvpenqno" required><br>
    
                <button type="submit" name="save">Upload</button>
                
        </form>

        
          <form  action="Annexure1.php">
        <input class="editbtn" type="submit" value="back" />
        </form>
        </div>

    </body>
</html>