<html>

<head>

	<title> register</title>

	<style type="text/css">
	#uname2 {
		position:absolute;
		top:325px;
		left:480px;
	}
	#uid2 {
		position:absolute;
		top:350px;
		left:480px;
	}
	#no2 {
		position:absolute;
		top:375px;
		left:480px;
	}

	input[type=password]{

		position:absolute;
		top:400px;
		left:480px;
	}
			
    #butn {

		position:absolute;
		top:190px;
		left:350px;
	}

	#uid1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:350px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}
	#uname1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:325px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}
	#no1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:375px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}

	#pw1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:400px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}		

	#link {
		
		width:275px;
		
		position:absolute;
		top:450px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}
	</style>

</head>

<body> 
	
	<form method="post">
	
		<h2>Register</h2>
		<div id="uname1"> New User Name</div>
		<input type="text" name="uname" id="uname2" placeholder="User Name"> <br>
		<div id="uid1"> New User ID</div>
		<input type="text" name="uid" id="uid2" placeholder="User ID"> <br>
		<div id="no1"> Mobile NO</div>
		<input type="text" name="no" id="no2" placeholder="Mobile No"> <br>
		<div id="pw1"> New Password</div>
		<input type="Password" name="pw" id="pw2" placeholder="Password"> <br>
		<div id="butn"><button type="submit" value="submit" id="butn" name="submit" > Create </button> </div>
	</form>

    
	<div id="link">
	<a href="login.php">Home</a> 
	</div>
	<?php
	
    if(isset($_POST['submit'])){
    	
		$servername='localhost';
     	$user='root';
    	$pwd='';
     	$db='user';
			
     	$conn = mysqli_connect($servername, $user, $pwd,$db);

		
     	if (!$conn) {
     		die("Connection failed: " . mysqli_connect_error());
     	}
     	$uname=$_POST['uname'];
     	$pw=$_POST['pw'];
     	$uid=$_POST['uid'];
     	$no=$_POST['no'];

		if(strlen($pw)<3 || strlen($uid)<3 || strlen($uname)<3 ||strlen($no)<1){
			echo "enter valid inputs";
		}
		else{
     		$query="INSERT INTO users (userid,mno,username,password) VALUES ('$uid','$no','$uname','$pw')";
		
			if(mysqli_query($conn,$query))
			{
				echo "User Added";
				header('location:login.php');
			}
			else
			{
				echo "Unable to Add User. Try again later.";
			}
		}
 	}
    ?>
	
</body>
</html>