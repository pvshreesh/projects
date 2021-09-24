<?php

$conn = mysqli_connect("localhost","root","snores","login");




        if(isset($_POST['save']))
{

    $mktgrp = $_POST['marketinggroup'];
    $hpvpno = $_POST['hpvpenqno'];
    $cname = $_POST['consultantname'];
    $cenq = $_POST['consultantenqno'];
    $duedate = $_POST['duedate'];
    $phno = $_POST['phno'];
    $description = $_POST['description'];
    $offerref = $_POST['hpvpofferref'];
    $delivery = $_POST['delivery'];
    $remarks = $_POST['remarks'];

    
        if(isset($_POST['marketinggroup']))
        {
            $query1 = "UPDATE upload SET marketinggroup='$mktgrp' where hpvpenqno='$hpvpno' ";
            $result1 = mysqli_query($conn,$query1);
        }

        if(isset($_POST['consultantname']))
        {
            $query2 = "UPDATE upload SET consultantname='$cname' where hpvpenqno='$hpvpno' ";
            $result2 = mysqli_query($conn,$query2);
        }
        if(isset($_POST['consultantenqno']))
        {
            $query3 = "UPDATE upload SET consultantenqno='$cenq' where hpvpenqno='$hpvpno' ";
            $result3 = mysqli_query($conn,$query3);
        }
        if(isset($_POST['duedate']))
        {
            $query4 = "UPDATE upload SET duedate='$duedate' where hpvpenqno='$hpvpno' ";
            $result4 = mysqli_query($conn,$query4);
        }
        if(isset($_POST['phno']))
        {
            $query5 = "UPDATE upload SET phno='$phno' where hpvpenqno='$hpvpno' ";
            $result5 = mysqli_query($conn,$query5);
        }
        if(isset($_POST['description']))
        {
            $query6 = "UPDATE upload SET description='$description' where hpvpenqno='$hpvpno' ";
            $result6 = mysqli_query($conn,$query6);
        }
        if(isset($_POST['hpvpofferref']))
        {
            $query7 = "UPDATE upload SET hpvpofferref='$offerref' where hpvpenqno='$hpvpno' ";
            $result7 = mysqli_query($conn,$query7);
        }
        if(isset($_POST['delivery']))
        {
            $query8 = "UPDATE upload SET delivery='$delivery' where hpvpenqno='$hpvpno' ";
            $result8 = mysqli_query($conn,$query8);
        }
        if(isset($_POST['remarks']))
        {
            $query9 = "UPDATE upload SET remarks='$remarks' where hpvpenqno='$hpvpno' ";
            $result9 = mysqli_query($conn,$query9);
        }
        
            if($result1 || $result2 || $result3 || $result4 || $result5 || $result6 || $result7 || $result8 || $result9)
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
        <title>Annexure 1 Edit Page</title>
        <link href="Top.css" rel="stylesheet" type="text/css"  />
        <link href="Login.css" rel="stylesheet" type="text/css"  />
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

     <form action="edit.php" method="post" id="addrow" and enctype="multipart/form-data">
    <label for="hpvpenqno"><b>HPVPENQ.NO</b></label><br>
    <input type="text" placeholder="Enter HPVPENQ.NO" name="hpvpenqno" ><br>

    <label for="marketinggroup"><b>Marketing Group</b></label><br>
    <input type="text" placeholder="Enter Msrketing Group" name="marketinggroup" ><br>
    
    <label for="consultantname"><b>Consultant/Customer name</b></label><br>
    <input type="text" placeholder="Enter Consultant/Customer name" name="consultantname" ><br>
    
    <label for="consultantenqno"><b>Consultant/CustomerEnq</b></label><br>
    <input type="text" placeholder="Enter Consultant/CustomerEnq" name="consultantenqno" ><br>
    
    <label for="duedate"><b>DueDate</b></label><br>
    <input type="text" placeholder="Enter DueDate" name="duedate" ><br>
    
    <label for="phno"><b>PhNo</b></label><br>
    <input type="text" placeholder="Enter PhNo" name="phno" ><br>
    
    <label for="description"><b>Description</b></label><br>
    <input type="text" placeholder="Enter Description" name="description" ><br>
    
    <label for="hpvpofferref"><b>hpvpOfferRef</b></label><br>
    <input type="text" placeholder="Enter HPVP Offer Ref" name="hpvpofferref" ><br>
    
    <label for="delivery"><b>Delivery</b></label><br>
    <input type="text" placeholder="Enter Delivery" name="delivery" ><br>
    
    <label for="remarks"><b>Remarks</b></label><br>
    <input type="text" placeholder="Enter Remarks" name="remarks" ><br>
        <button type="submit" name="save" class="button2 button2d">Edit</button>
        </form>
        
        <form  action="Annexure1.php">
        <button class="button2 button2d">Back</button>
        </form>
       </div> 
    </body>
</html>