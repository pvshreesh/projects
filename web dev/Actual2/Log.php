<!DOCTYPE html>
<html>
<head>
	<title>Login Page</title>
	<link href="Top.css" rel="stylesheet" type="text/css"  />
	<link href="Login.css" rel="stylesheet" type="text/css" />
</head>
<body>
	<header class="headers">
	<div>
	<img src="icon1.jpg" class="icon1" alt="Icon 1" />
	<img src="icon2.jpeg" class="icon2" alt="Icon 2" />
	<h1 class="head1">POWER SECTOR-MARKETING</h1>
        <div id="top_buttons">
	<button class="button1">HOME</button>
	<button class="button1">ABOUT US</button>
	<button class="button1">OUR CUSTOMERS</button>
	<button class="button1">BUSINESS ENVIRONMENT</button>
	<button class="button1">ONLINE SYSTEM</button>
	<button class="button1">TENDERS</button>
	<button class="button1">CONTRACTS</button>
	<button class="button1">EMPLOYEE CORNER</button>
        </div>
</div>
</header>
<main>
	<div class="row">
	<div class="col side">
		<div class="login">
		<h3 class="head2">Login</h3>
		<form method="post">
			<label for="StaffNo" action="Log.php" class="p2">Staff Number:</label><br>
			<input type="text" name="StaffNo" placeholder="Staff Number" required><br>
			<label for="Password" class="p2">Password:</label><br>
			<input type="password" name="Password" placeholder="Password" required><br><br>
			<input type="submit" value="Login" name="login" class="submit"><br><br>
        </form>
        <button class="Pass"><a href="Password.php">Forgot Password</a></button><br><br>
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
    <div class="col middle head3" style="color:	#FFD700">

    <?php
    if(isset($_POST['login']))
	{
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
		$StaffNo=$_POST['StaffNo'];
		$password=$_POST['Password'];
		$query="SELECT password from bhelstaff where staffno=$StaffNo";
		
		$query_run= mysqli_query($conn,$query);
        $result=mysqli_fetch_assoc($query_run);
        $resultstring=$result['password'];
        
        if($password==$resultstring)
		{
			$_SESSION['StaffNo']=$username;
			$_SESSION['Password']=$password;
            echo $result['Type'];
            header('location:Page1.php');

		}
		else
		{
			#echo '<script type="text/javascript"> alert("Invalid credentials") </script>';
			echo "Invalid Credentials!";
		}
	}
	?>
    </div>
	    <div class="col middle">
		<h2 class="head3">INSTRUCTIONS</h2>
		<ul class="matter">
			<li> Enter your 6 digit Staff Number and Password to Login, only if you're an admin.</li>
			<li> If you have forgotten your password, click Forgot Password.</li>
			<li> An email will be sent with your new password upon clicking Forgot Password.</li>
			<li> Do not forget to Logout after use.</li>
	</div>
</div>
</main>
</body>
</html>
