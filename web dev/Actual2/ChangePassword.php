<!DOCTYPE HTML>
<html>
<head>
	<title> Change Password Page</title>
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
		<input type="text" name="StaffNo" placeholder="Staff Number" required><br>
		<label for="NewPassword" class="p2">New Password:</label><br>
		<input type="password" name="NewPassword" placeholder="Password" required><br><br>
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
     $newpwd=$_POST['NewPassword'];
     
     $query= "UPDATE loginfo set password='$newpwd' where staffno='$StaffNo'";
     if(mysqli_query($conn,$query))
     {
     	echo "Password Updated";
     }
     else
     {
     	echo "Failed to Update";
     }
 }
     ?>
 </div>
</body>
</html>

