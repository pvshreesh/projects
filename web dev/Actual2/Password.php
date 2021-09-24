<!DOCTYPE html>
<html>
<head>
	<title>Password Recovery Page</title>
	<link href="Top.css" rel="stylesheet" type="text/css"  />
	<link href="Login.css" rel="stylesheet" type="text/css" />
</head>
<body>
	<header class="headers">
	<div >
	<img src="icon1.jpg" class="icon1" alt="Icon 1" />
	<img src="icon2.jpeg" class="icon2" alt="Icon 2" />
	<h1 class="head1">POWER SECTOR-MARKETING</h1>
	
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
<main>
	<div class="row">
	<div class="col side">
		<div class="login">
		<h3 class="head2">Login</h3>
		<form method="post" action="Log.php">
			
			<input type="submit" value="Return Back to Login" name="submit" class="submit">
        </form>
        <br>

    </div>
	<br>
	<div class="login">
		<h3 class="head2">Quick Links</h3>
		<ul>
			<li><a href="#">Old Website</a></li>
			<li><a href="#">Customer Directory</a></li>
			<li><a href="#">Client Certificate</a></li>
			<li><a href="#">Knowledge Management</a></li>
			<li><a href="#">Telephone Directory</a></li>
			<li><a href="#">Debtor Management System</a></li>
			<li><a href="#">Webmail</a></li>
		</ul>
	</div>
    </div>
	<div class="col middle">
		<h2 class="head3" style="color:#006400">PASSWORD RECOVERY PAGE</h2>
		<p style="font-size:30px;"> Enter your Staff Number to receive an email with the new password</p>
		<div style="text-align:center; font-size:30px;">
                    <form method="post" action="Password.php">
			<label for="StaffNo" style="font-weight: bold;font-size:30px;"> Staff Number:</label>
			<input type="text" name="StaffNo" placeholder="Staff Number" required><br><br>
			<input type="submit" value="Send Password" name="enter" class="submit">
		</form>
		
		
		<?php
		if(isset($_POST['enter']))
           { 
    $chars="0123456789QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm <br>";
    $newpassword='';
    for($i=0;$i<7;$i++)
        $newpassword .= $chars[mt_rand(0,61)];
    $servername='localhost';
     $user='root';
     $pwd='snores';
     $db='login';
     // Create connection
     $conn = mysqli_connect($servername, $user, $pwd,$db);

     // Check connection
     if (!$conn) {
     die("Connection failed: " . mysqli_connect_error());
     }
     $a=$_POST['StaffNo'];
     $sql="SELECT * FROM bhelstaff WHERE staffno='$a'";
     $query=mysqli_query($conn,$sql);
     $result=mysqli_fetch_assoc($query);
     $resultstring=$result['email'];
     $sql2=" UPDATE bhelstaff SET password='$newpassword' WHERE staffno='$a'";
     
       $to= $resultstring;
         $sub="Password ";
         $msg="Your new password is ".$newpassword;
         $head="From:bejjankiaditya1010@gmail.com";
         
         if(mail($to,$sub,$msg,$head))
         { 
           mysqli_query($conn,$sql2);
           echo "Mail sent to ".$resultstring; 
           
         }
         else 
         { 
           echo "Mail not sent"; }
         } 
       
           ?>
	   




	    </div>
     </div>
   </div>
</main>
</body>
</html>
