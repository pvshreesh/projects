<!DOCTYPE HTML>
<html>
<head>
	<title> Add User Page</title>
	<link href="Top.css" rel="stylesheet" type="text/css"  />
	<link href="Login.css" rel="stylesheet" type="text/css"  />
</head>
<body>
	<header class="headers">
	<div >
	<img src="icon1.jpg" class="icon1" alt="Icon 1" />
	<img src="icon2.jpeg" class="icon2" alt="Icon 2" />
	<h1 class="head1">POWER SECTOR-MARKETING</h1>
	<br>
	<form action="Page1.php">
	<button class="button1">HOME</button>
</form>
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
	<form method="post">
		<label for="StaffNo" class="p2">Staff Number:</label><br>
		<input type="text" name="StaffNo" placeholder="Staff Number" required><br><br>
		<label for="NewPassword" class="p2">Password:</label><br>
		<input type="password" name="Password" placeholder="Password" required><br><br>
		<label for="StaffNo" class="p2">Email ID:</label><br>
		<input type="text" name="emailid" placeholder="Email ID" required><br><br>
		<label for="StaffNo" class="p2">Name:</label><br>
		<input type="text" name="name" placeholder="Name" required><br><br>
		<input type="submit" value="Submit" name="submit" class="submit"><br><br>
	</form>
	<?php
    if(isset($_POST['submit']))
	{
     $servername='localhost';
     $user='root';
     $pwd='';
     $db='login';
     // Create connection
     $conn = mysqli_connect($servername, $user, $pwd,$db);

     // Check connection
     if (!$conn) {
     die("Connection failed: " . mysqli_connect_error());
     }
     $StaffNo=$_POST['StaffNo'];
     $pwd=$_POST['Password'];
     $emailid=$_POST['emailid'];
     $name=$_POST['name'];
     $query="INSERT INTO loginfo (staffno,password,emailid,Name) VALUES ('$StaffNo','$pwd','$emailid','$name')";
     if(mysqli_query($conn,$query))
     {
     	echo "User Added";
     	$to= $emailid;
         $sub="Account Creation";
         $msg="An account has been created. Your password for login is:".$pwd;
         $head="From:damodaran.nived@gmail.com";
         if(mail($to,$sub,$msg,$head))
         { echo "<br>Mail sent to ".$emailid; }
     }
     else
     {
     	echo "Unable to Add User. Try again later.";
     }
 }
     ?>
 </div>
</body>
</html>