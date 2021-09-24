<?php
session_start();
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
?>
<!DOCTYPE HTML>
<html>
<head>
	<title> Update Profile Page</title>
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
	<?php
	$st=$_SESSION['StaffNo'];
	$query3="SELECT * from loginfo where staffno='$st'";
	mysqli_query($conn,$query3);
	$query_run= mysqli_query($conn,$query3);
    $result3=mysqli_fetch_assoc($query_run);
    $staff=$result3['staffno'];
    $emid=$result3['emailid'];
    $nm=$result3['Name'];
    $phno=$result3['phoneno'];
    echo "<br><br><b>Name: ".$nm;
    echo "<br>Email ID: ".$emid;
    echo "<br>Phone Number: ".$phno;
    echo "<br>Staff Number: ".$staff;
    echo "<br><br><br><b>";
	?>
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
    
     $StaffNo=$_POST['StaffNo'];
     $pwd=$_POST['Password'];
     $emailid=$_POST['emailid'];
     $name=$_POST['name'];
	 if(isset($_POST['emailid']))
	 {
		 $query="UPDATE loginfo set emailid='$emailid' where staffno='$staff'  and password='$pwd'";
		 $result1=mysqli_query($conn,$query);
	 }
	 if(isset($_POST['name']))
	 {
		 $query2="UPDATE loginfo set Name='$name' where staffno='$staff' and password='$pwd'";
		 $result2=mysqli_query($conn,$query2);
	 }
	 if(isset($_POST['StaffNo']))
	 {
	 	$query4="UPDATE loginfo set staffno='$StaffNo' where staffno='$staff' and password='$pwd'";
	 	$result4=mysqli_query($conn,$query4);
	 }
	 if($result1 || $result2 || $result4)
	 {echo "Profile Updated";}
     else
	 {
	 echo "Profile Not Updated";}
	}
	?>
	 </div>
</body>
</html>
 
	 
	
